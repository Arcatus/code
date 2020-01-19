# -*- coding: utf-8 -*-
__author__ = 'Jair Paredes, Arturo Herrera, Arturo Sánchez, Josué Cirilo'
__copyright__ = 'Copyright 2019, UniNet'
__version__ = '2.0.0'
__email__ = 'jparedes@reduno.com.mx, arturohv@reduno.com.mx,' \
            'arturosm@reduno.com.mx, jcirilo@reduno.com.mx'
__status__ = 'Production'

from conexion.connection_database import ConnectionDataBase
from base_datos.queries import UPDATE_STATUS_HISTORICO, \
                               INSERT_VALIDATION_ERROR, \
                               INSERT_VALIDATION_ERROR_ID
from utilidades.constantes import USER_DB, PASSWORD_DB, HOST_DB, DATABASE
from utilidades.log import Log
from lxml import etree
import socket
import time
import re
import telnetlib
import difflib
from datetime import datetime, timedelta


def update_status_historico(id_historico, id_statusTask):
    """
        Actualiza el estado de la tarea de la tabla historico.

        Args:
            id_historico: ID del historico que se va a actualizar.
            id_statusTask: ID del estatus de la tarea [INICIO, FIN, ERROR].
            
        Raises:
            Exception: Si ocurre un problema durante la ejecución de las
                actividades.

        Returns:
            None
    """

    try:
        #Se crea objeto para la conexion a la DB
        connection_db = ConnectionDataBase(USER_DB, PASSWORD_DB, HOST_DB,
                                                        DATABASE)
        data = (id_statusTask, id_historico)
        connection_db.update_data(UPDATE_STATUS_HISTORICO, data)
        
    except Exception as err:
        raise Exception(err)


def probe_connection(address, port):

        """
        Realiza pruebas de conexion a los equipos.

        Args:
            address: IP del equipo.
            port: Número del puerto que se utilizará para probar la conexion.

        Returns:
            Respuesta, Indica si la conexion al equipo esta activa.
        """
        
        start = datetime.now()
        end = start + timedelta(seconds=5)
        probe_ok = True
        intvtimeout = 1

        while datetime.now() < end:
            s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
            s.settimeout(intvtimeout)
            try:
                s.connect((address, port))
                s.shutdown(socket.SHUT_RDWR)
                s.close()
                break
            except:
                time.sleep(1)
                pass
        else:
            probe_ok = False

        return probe_ok
    

def insert_error(host, severidad, idComando, idMetodo, error, datos_ejecucion):
    """
        Realizar la inserción de errores a la DB.

        Args:
            :host: Hostname del equipo.
            :severidad: Nivel de severidad.
            :idComando: ID del comando.
            :idMetodo: ID del metodo
            :error: Mensaje de error.
            :datos_ejecucion: Lista de los valores de ejecución.
            
        Raises:
            Exception: Si ocurre un problema durante la ejecución de
            actividades.

        Returns:
            None:
    """
    try:
        #Se crea objeto para la conexion a la DB
        connection_db = ConnectionDataBase(USER_DB, PASSWORD_DB, HOST_DB,
                                                                     DATABASE)
        
        if type(error) is not str:
            error = str(error)

        #Inserta el error en la tabla errores
        dataError_for_db = {"hostname": host,
                            "severidad": severidad,
                            "id_comando": idComando,
                            "info": error,
                            "usuario_actualizacion": datos_ejecucion[
                                                      "usuario_actualizacion"]}

        id_err = connection_db.insert_data(INSERT_VALIDATION_ERROR, 
                                                            dataError_for_db)

        #Inserta el error en la tabla ejecucion
        msj_error = "Error: %s" %(str(error))

        datos_ejecucion["id_metodo"] = idMetodo
        datos_ejecucion["id_comando"] = idComando
        datos_ejecucion["id_error"] = id_err
        datos_ejecucion["resultado"] = msj_error
        datos_ejecucion["salida"] = msj_error

        connection_db.insert_data(INSERT_VALIDATION_ERROR_ID, datos_ejecucion)

    except Exception as err:
        raise Exception(err)


def validation(cadena, validacion, tipoValidacion, vendor, filter_str=None):
    """
        Método para realizar la validacion de la cadena.

        Args:
            :cadena: Cadena a validar.
            :validacion: xpath o regex.
            :tipoValidacion: ID del catalogo (29: Xpath o 30: Expresión Regular
                                89: Expresion Regular FindAll, 245: FindInter)
            :vendor: Cisco o Juniper
            :filter_str: filtro que se genero para obtener los datos 
                        específicos. (unicamente para Cisco)
            
        Raises:
            Exception: Si ocurre un problema durante la ejecución de
            actividades.

        Returns:
            None:
    """
    try:
        if tipoValidacion == 29:
            if vendor == "Cisco":
                #filter_str se convierte en un objeto elemnt
                filter_xml = etree.XML(filter_str)
                #Se obtiene el namespace
                ns_xml = filter_xml.nsmap
                ns = ns_xml.pop(None)
                ns_xml["ns"] = ns
                
                val_response = cadena.xpath(validacion, namespaces=ns_xml)

            else:
                val_response = cadena.xpath(validacion)

        elif tipoValidacion == 30:
            if re.search(validacion, cadena):
                val_response = re.search(validacion, cadena).group()
            else: 
                val_response = "Patron no encontrado."

        elif tipoValidacion == 89:
            if re.findall(validacion, cadena):
                val_match = re.findall(validacion, cadena)
                val_response = len(val_match)
            else: 
                val_response = "Patron no encontrado."

        elif tipoValidacion == 245:
            if re.finditer(validacion, cadena):
                val_response = []
                for match in re.finditer(validacion, cadena):
                    val_response.append(match.group())
            else: 
                val_response = "Patron no encontrado."
        else:
            val_response = "tipoValidacion invalido"

        return val_response

    except etree.XPathEvalError as e:
        error = "XPath invalido, %s. \nExcepcion: %s" % (validacion, str(e))
        raise Exception("Error: %s" % (error))

    except Exception as e:
        error = "Se ha generado una excepcion: %s \nValidacion: %s" % (str(e), 
                                                                    validacion)
        raise Exception("Error: %s" % (error))

def probe_telnet_console(address):
    flag_telnet = True
    try:
        tn = telnetlib.Telnet(address)
        ind, obj, response = tn.expect([b"Username:", b"login:"], 10)
        if 'Username' in response.decode('ascii') and ind != -1:
            tn.close()
        else:
            flag_telnet = False
            tn.close()
    except:
        flag_telnet = False
    return flag_telnet

def probe_telnet_connection(address):
    try:
        response = False
        Delta = timedelta(minutes=10)
        Limit = datetime.now() + Delta
        while response == False:
            flag_port, flag_telnet = None, None
            flag_port = probe_connection(address, 23)
            flag_telnet = probe_telnet_console(address)
            if (flag_port and flag_telnet) == True:
                response = True
            if datetime.now() >= Limit:
                response = "Equipo no contesta, timeout excedido"
                break
        return response
    except Exception as e:
        raise Exception(str(e))


def comparador_telnet(buffer, validacion,tipoValidacion,vendor):

    """
    Método para realizar la validacion de configuracion.

    Args:
        :buffer: Resultado al arrojar comando.
        :validacion: validacion para comparar configuracion.

    Raises:
        Exception: Si ocurre un problema durante la ejecución de
        actividades.

    Returns:
        None:
    """
    try:
        if tipoValidacion == 90:
            #Se limpia buffer
            buffer = buffer.replace('\r','')
            buffer = buffer.split('\n')
            buffer = buffer[2:]
            #Se buscan lineas a validar y se guardan a lista
            lista = []
            for i in buffer:
                if(re.search('^[a-z].*',i.strip())):
                    lista.append(i.strip())
                elif(re.search('^%',i.strip())):
                    lista.append(i.strip())

            #Se castean las listas a conjuntos para compararlos
            conjunto_buffer = set(lista)
            plantilla = validacion.split('\n')
            conjunto_plantilla = set(plantilla)
            #print(conjunto_buffer,'buffer')
            #print('*'*70)
            #print(conjunto_plantilla,'plantilla')
            if '% No such configuration item(s)' in conjunto_buffer:
                return False, '% No such configuration item(s)'

            else:
                if conjunto_buffer==conjunto_plantilla:
                    return True, 'True'
                else:
                    #Se muestra la diferencia con la biblioteca difflib
                    diferencia = difflib.Differ()
                    generador_diferencia = diferencia.compare(lista, plantilla)
                    diff = '\n'.join(generador_diferencia)

                    return False, diff

        elif tipoValidacion == 89 or tipoValidacion == 30:
            return validation(buffer, validacion, tipoValidacion, vendor), \
                                                                        "None"
                
    except Exception as e:
        raise Exception(str(e))

  
