# -*- coding: utf-8 -*-
__author__ = 'Arturo Herrera'
__copyright__ = 'Copyright 2019, UniNet'
__version__ = '1.0.0'
__email__ = 'arturosm@reduno.com.mx'
__status__ = 'Production'

from utilidades.utilities import insert_error, validation, probe_connection
from conexion.connection_device import ConnectionDevice
from conexion.connection_database import ConnectionDataBase
from base_datos.queries import INSERT_VALIDATION_XPATH
from utilidades.constantes import USER_DB, PASSWORD_DB, HOST_DB, DATABASE
from utilidades.log import Log

class ExecuteCommandsCOU:
    """
    Clase que realiza la ejecución de los comandos en el router.

    .. note::
        Los logs asociados al comportamiento de la funcion son depositados
        en la ruta script/nas_log/EquiposLog.log.
        El nivel de severidad definido es INFO.
    """

    def __init__(self, device_data):
        self.ip = device_data[0].ip
        self.ci = device_data[0].ci
        self.hostname = device_data[0].host
        self.proveedor = device_data[0].proveedor
        self.id_ejecucion = device_data[0].idAccion
        self.id_historico = device_data[0].historico
        self.usuario = device_data[0].usuarioActualizacion
        self.user_device = device_data[1]
        self.pass_device = device_data[2]

        self.loggerExc = Log()
        self.loggerExc= self.loggerExc.setup_logger("logExec_%s" %
                          (self.hostname), "/script/nas_log/EquiposLog.log")
        
        #Diccionarios con la info necesaria para realizar los
        #insert en la db
        self.data_for_db = {"id_historico": self.id_historico,
                            "id_accion": self.id_ejecucion,
                            "usuario_actualizacion": self.usuario}


    def execute_commands(self, flujo_list, id_metodo):
        """
        Método utilizado para ejecutar comandos en los equipos.
        Aqui se van ejecutando los comandos derivados del flujo seleccionado
        por el usuario.

        Args:
            command_list_to_validate: Lista de comandos.
            id_metodo:  Id del metodo a ejecutar

        Raises:
            :Exception: Si ocurre un problema durante la ejecución de
            actividades.

        Returns:
            Mensaje de acción correcta o con error.
        """
        try:
            self.loggerExc.debug("INICIA::ExecuteCommandsCOU::execute_commands")

            device_Juniper = False

            #Se crea conexion a la DB
            connection_db = ConnectionDataBase(USER_DB, PASSWORD_DB, HOST_DB,
                                                        DATABASE)

            #Se crea conexion al equipo
            connections_factory = ConnectionDevice(self.hostname, self.ip,
                                            self.user_device, self.pass_device)

            #Se prueba conectividad al equipo (NETCONF)
            cxn_netconf = probe_connection(self.ip, 830)
            self.loggerExc.debug("Conectividad via NETCONF %s en %s" 
                                        % (str(cxn_netconf), self.hostname))

            #Se prueba conectividad al equipo (TELNET)
            cxn_telnet = probe_connection(self.ip, 23)
            self.loggerExc.debug("Conectividad via Telnet %s en %s" 
                                          % (str(cxn_telnet), self.hostname))

            if self.proveedor == "Juniper":
                device_Juniper = True
        
            #Se usa cxn_telnet para validar que el equipo este operativo
            if cxn_telnet is True:
                
                if device_Juniper is True and cxn_netconf is True:
                    connection_dev = connections_factory.get_connection(
                                                                self.proveedor)
                else:
                    connection_dev = connections_factory.get_connection(
                                                                "Cisco_telnet")
                
                #Se abre conexion
                connection_dev.open_connection('show')

                for flujo in flujo_list:
                    #Se obtiene los comandos
                    self.loggerExc.info("INICIO de validacion:: flujo \
                            %s, equipo %s"% (flujo.nombreFlujo, self.hostname))
                    
                    command_list = flujo.comandos
 
                    for each_command in command_list:
                        registro_db = str()

                        self.loggerExc.debug("Se ejecuta %s en %s"
                                        % (each_command.comando, self.hostname))
                        
                        #ID catalogo = 4 -> Comandos de Configuracion
                        if each_command.tipoComando.idCatalogoNivelUno == 4 \
                                                     and device_Juniper is True:
                            
                            self.loggerExc.debug("Comando de configuracion, %s"
                                                    % (self.hostname))

                            resp = connection_dev.get_config(
                                                  "set", each_command.comando)
                            
                            registro_db = resp.text

                        else:
                            #Si el comando tiene validaciones el formato sera 
                            # xml.
                            if device_Juniper is True and \
                                                    each_command.validaciones:

                                self.loggerExc.debug("Ejecucion xml en %s"
                                                              % (self.hostname))

                                resultado = []  
                                resp = connection_dev.execute_command(
                                                        each_command.comando)
                                
                                #Inicia la validacion del comando.
                                for validacion in each_command.validaciones:
                                    res_val = validation(resp,
                                                validacion.validacion, 
                                                validacion.tipoValidacion.\
                                                            idCatalogoNivelUno,
                                                self.proveedor)
                            
                                    self.loggerExc.debug("\n\nSe valido, " +
                                        "%s -> %s en %s \n" % 
                                            (validacion.validacion, res_val, 
                                                                self.hostname))

                                    for val in res_val:
                                        resultado.append("%s: %s" %
                                            (validacion.descripcion, 
                                                            val.text + "\n"))
                                
                                registro_db = "".join(resultado) 

                            
                            #Si el comando no tiene validaciones el formato sera 
                            # text.
                            elif device_Juniper is True:
                                self.loggerExc.debug("Ejecucion text en %s"
                                                              % (self.hostname))

                                resp = connection_dev.execute_command(
                                                each_command.comando, 'text')

                                registro_db = resp.text

                            #El equipo es Cisco y se ejecutara en CLI.
                            else:
                                self.loggerExc.debug("Ejecucion CLI en %s"
                                                              % (self.hostname))

                                resp = connection_dev.execute_command(
                                                        each_command.comando)
                                
                                registro_db = \
                                     resp.strip("\x08").strip("\r").strip("$")


                        self.data_for_db["id_comando"] =  each_command.idComando
                        self.data_for_db["resultado"] = registro_db
                        self.data_for_db["id_metodo"] = id_metodo
                        self.data_for_db["salida"] = "N/A"
                   
                        connection_db.insert_data(INSERT_VALIDATION_XPATH,
                                                              self.data_for_db)
            
            else:
                self.loggerExc.error("No se puede conectar a equipo,  %s" 
                                                            % (self.hostname))

                raise Exception("No se puede conectar a equipo,  %s" 
                                                            % (self.hostname))
            

            json_response = {}

            json_response["error"] = False

            self.loggerExc.debug("FIN::ExecuteCommandsCOU::execute_commands")

            return json_response
        
        except Exception as error:
            self.loggerExc.error("Se ha generado una excepcion" +
                                     " en execute_commands cou %s" % (error))

            if each_command.idComando is not None:
                insert_error(self.hostname, "Alta", each_command.idComando, 
                                            id_metodo, error,  self.data_for_db)

            raise Exception("Se ha generado una excepcion en %s, %s." % 
                                                    (self.hostname, str(error)))

        finally:
            #Se cierra la conexion si esta fue abierta.
            if connection_dev is not None:
                connection_dev.close_connection()
