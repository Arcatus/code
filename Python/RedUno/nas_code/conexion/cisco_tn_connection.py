# -*- coding: utf-8 -*-
__author__ = 'Jair Paredes, Arturo Herrera, Arturo Sánchez, Jorge Campos, \
                                                                Josué Cirilo'
__copyright__ = 'Copyright 2019, UniNet'
__version__ = '2.1.0'
__email__ = 'jparedes@reduno.com.mx, arturohv@reduno.com.mx, \
                            arturosm@reduno.com.mx, jcpelcas@reduno.com.mx, \
                                                        jcirilo@reduno.com.mx'

__status__ = 'Production'

import telnetlib
from utilidades.log import Log
import socket
import datetime
import time
import re
from utilidades.constantes import EXP_REG_REMOVE_CHAR

class CiscoTelnetConnection:

    """
    Clase que realiza las conexiones vía Telnet a los equipos asi como
    tambien ejecutar funciones complementarias a las acciones.

    .. note::
        Los logs asociados al comportamiento de la función son depositados
        en la ruta script/dnos_log/EquiposLog.log.
        El nivel de severidad definido es INFO.
    """

    def __init__(self, router_name, ip_address, username, password):
        self.router_name = router_name
        self.ip_address = ip_address
        self.username = username
        self.password = password
        self.connection = None
        self.logDevice = Log()
        self.loggerEq = self.logDevice.setup_logger("logEquipos",
                                             "/script/nas_log/EquiposLog.log")

    #Funcion para abrir la conexion via TELNET
    def open_connection(self, action):

        """
        Método utilizado para abrir la conexion via Telnet al equipo.

        Args:
            :param arg1: Acción a ejecutar (upload|show), dependiendo de 
            la acción se asigna un timer de espera.
            default = 30 s.
            show = 60 s
            upload = 1200 s.

        Raises:
            :Exception: Si ocurre un problema al realizar la conexion 
             en el equipo.
        """

        try:
            self.loggerEq.info("Iniciando conexion telnet a %s" %
                                                            (self.router_name))

            #Por default el timeout es 30
            timeout_ = 30
            port = 23
            flag_connected = False
            intentos_conexion = 0
            limit_intent = 10

            #Se valida si la accion es de carga u obtencion de comandos
            if action == 'upload':
                timeout_ = 1200
            elif action == 'show':
                timeout_ = 60

            self.router_name = self.router_name.split('.')[0]

            while flag_connected == False:
                self.loggerEq.info("Intento: %s en %s" %
                                        (intentos_conexion, self.router_name))
                #Abre la conexion telnet al equipo
                try:
                    self.connection = telnetlib.Telnet(self.ip_address, port, timeout_)

                    self.connection.read_until(b"Username: ", 20)
                    self.connection.write((self.username + "\n").encode('ascii'))
                    self.connection.read_until(b"Password: ", 20)
                    self.connection.write((self.password + "\n").encode('ascii'))

                    check_failed = self.connection.read_until(b"#", 20)
                    if bytes(self.router_name, 'utf-8') in check_failed:
                        self.connection.write(b"terminal length 0\n")
                        ind, obj, response = self.connection.expect([b"#"], 30)
                        self.loggerEq.info("Conexion establecida a %s" %
                                                                (self.router_name))
                        flag_connected = True
                    elif bytes('Authentication failed', 'utf-8') in check_failed:
                        self.loggerEq.info("Usuario/contraseña erronea en %s" %
                                                                (self.router_name))
                        flag_connected = False
                        self.connection.close()
                    elif bytes('Username', 'utf-8') in check_failed:
                        self.loggerEq.info("Usuario/contraseña erronea en %s" %
                                                                (self.router_name))
                        flag_connected = False
                        self.connection.close()
                    else:
                        flag_connected = True
                    intentos_conexion += 1
                    if intentos_conexion == limit_intent:
                        self.loggerEq.info("Se excedieron los intentos permitidos en %s" %
                                                                (self.router_name))
                        self.loggerEq.info("No se puede conectar al equipo %s" %
                                                                (self.router_name))
                        self.connection.close()
                        flag_connected = False
                        break
                except:
                    flag_connected = False
                    self.loggerEq.info("Fallo intento: %s en %s" %
                                        (intentos_conexion, self.router_name))            

        except Exception as err:
            self.loggerEq.error("Cannot connect to device: %s %s"
                                             % (self.router_name, format(err)))
            self.connection.close()

            raise Exception("Error: No se puede conectar al equipo.")


    #Funcion para configurar los comandos en el equipo
    def configure(self, configuracion, conf_t_mode='configure'):
        """
        Método utilizado para aplicar configuraciones en el equipo.

        Args:
            :configuracion: Lista de comandos a ejecutar en modo configuración.
            :conf_t_mode: Modo en que se ejecuta el comando 
                            (admin configure | usuario privilegiado), \
                                    default = configure

        Returns:
            Lista de comandos que no pudieron ser ejecutados.

        Raises:
            :Exception: Si ocurre un problema al realizar la configuración
                    de comandos en el equipo.
        """
        
        try:
            ctrl_z = "\x1A"
            check_failed = []
            failed_commands = []
            apply_commit = True

            #Abre la consola en modo configuracion
            self.loggerEq.info("Inicia configuracion en %s" 
                                                        % (self.router_name))
            self.connection.write(
                            ("%s exclusive\n" % (conf_t_mode)).encode('ascii'))

            self.loggerEq.debug("Terminal habilitada en modo %s exclusive en %s" 
                                            % (conf_t_mode, self.router_name))

            #Ejecuta cada comando en el router
            for each_command in configuracion:
                self.loggerEq.debug("Ejecutando comando %s en %s" 
                                             % (each_command, self.router_name))
                self.connection.write((each_command + '\n').encode('ascii'))
                self.loggerEq.debug("Comando ejecutado %s en %s" 
                                             % (each_command, self.router_name))

                ind, obj, check_failed = self.connection.expect([b"#"], 10)
                if ind != -1:
                #Verifica si exite un error al aplicar el comando
                #si hay error no ejecuta el commit
                    for line in check_failed.decode('ascii').split('\n'):
                        if re.search("Invalid input", line):
                            failed_commands.append(each_command)
                            self.loggerEq.error('%s no pudo ser aplicado en %s' 
                                            % (each_command, self.router_name))
                            self.loggerEq.error('Saliendo de modo config en %s' 
                                                        % (self.router_name))
                            apply_commit = False
                            break

                if apply_commit is False:
                    #Se borra configuracion en la candidata.
                    self.connection.write(('abort \n').encode('ascii'))
                    self.loggerEq.error('Se aborta configuracion en %s'
                                                        % (self.router_name))

                    raise Exception("Se aborta configuracion por error de \
                                            sintaxis en %s" % (self.router_name))

            if apply_commit is True:
                self.loggerEq.debug("Aplicando commit en %s"
                                                     % (self.router_name))
                self.connection.write(('commit\n').encode('ascii'))

                ind, obj, response = self.connection.expect([b"commit"], 10)
                ind, obj, response = self.connection.expect([b"config"], 10)

                self.loggerEq.debug("salida buffer %s"  % 
                                                    (response.decode('ascii')))

                flag_commit_failed = 0

                for line in response.decode('ascii').split('\n'):
                    if re.search("Failed to commit",  line):
                        flag_commit_failed = 1
                        self.loggerEq.error('Fallo al aplicar el commit en %s' 
                                                          % (self.router_name))

                        self.connection.write(('abort \n').encode('ascii'))

                        self.loggerEq.error('Se aborta configuracion en %s'
                                                        % (self.router_name))
                if flag_commit_failed == 0:
                    self.loggerEq.debug("Commit aplicado en %s" 
                                                        % (self.router_name))

            self.connection.write((ctrl_z + '\n').encode('ascii'))
            self.loggerEq.debug("Terminal cerrada en %s" % (self.router_name))

            return failed_commands

        except Exception as err:
            error = ("El metodo configure ha generado una excepcion: %s" 
                                                                % (str(err)))
            self.loggerEq.error(error)
            raise Exception("Error: en " + __class__.__name__ + " %s " %
                                                                   (error))

    #Funcion para ejecutar los comandos en el equipo
    def execute_command(self, command, command_format=None, time_to_sleep=1):

        """
        Método utilizado para ejecutar comandos en el equipo.

        Args:
            :param arg1: Comando a ejecutar.
            :param arg2: Tiempo de espera para obtener la salida del comando

        Returns:
            Salida del comando ejecutado.

        Raises:
            :Exception: Si ocurre un problema al realizar la ejecución
            de comandos en el equipo.
        """
        
        try:
            ind, obj, response = None, None, None
            self.loggerEq.debug("Llega a EXECUTE-COMMAND")
            self.loggerEq.debug("time_to_sleep %s" % (time_to_sleep))

            hostname = self.router_name.split('.')[0]

            hostname = hostname+"#"
            hostname = hostname.encode()
            self.loggerEq.debug("CADENA A ESPERAR: %s" % (hostname))

            #self.connection.write((command + '\n').encode('ascii'))

            if "clear counters" in command:
                self.connection.write((command + '\n\n').encode('ascii'))
            elif "monitor interface" in command:
                self.connection.write((command + '\n').encode('ascii'))
                time.sleep(5)
                self.connection.write(('q\n').encode('ascii'))
            else:
                self.connection.write((command + '\n').encode('ascii'))
            
            response = self.connection.read_until(hostname, 300)

            self.loggerEq.debug("EXPRESION: %s" % (EXP_REG_REMOVE_CHAR))                                 

            response = re.search(EXP_REG_REMOVE_CHAR, response.decode('ascii', 
                                                            errors="ignore"))

            self.loggerEq.debug("ejecuta %s en %s" % (command,
                                                            self.router_name))

            self.loggerEq.debug("------------------------------------")
            self.loggerEq.debug("%s" % (response.group()))
            self.loggerEq.debug("------------------------------------")

            return response.group()

        except Exception as err:
            error = ("El metodo execute_command ha generado " +
                                       "una excepcion: %s" % (str(err)))
            self.loggerEq.error(error)
            raise Exception("Error: en " + __class__.__name__ + " %s " %
                                                                     (error))

    def command_check_success(self, input_Data, regEx, last_lines):

        """
        Método utilizado para validar el resultado de los comandos ejecutados
        en el equipo.

        Args:
            :param arg1: Buffer que contiene la salida del comando.
            :param arg2: Expresión regular a buscar.
            :param arg2: Bandera que indica si se busca en todo el buffer o 
             en las últimas líneas.
             Default = todo el buffer.

        Returns:
            True Si la ejecución del comando fue exitosa o False en otro caso.

        Raises:
            :Exception: Si ocurre un problema al realizar la busqueda del
             patron en el buffer.
        """

        try:
            result = False
            input_to_process = []

            if last_lines == 0:
                #Toma todas las lineas del buffer
                input_to_process = input_Data
            else:
                #Toma las ultimas lineas del buffer
                input_to_process = input_Data[last_lines:]

            self.loggerEq.debug("INPUT TO PROCESS %s" % (input_to_process))

            #si la regex solo es una busca en el buffer la cadena
            if type(regEx) is str:
                for res_line in input_to_process.split('\n'):
                    self.loggerEq.debug("check-regex %s" % (regEx))
                    self.loggerEq.debug("RESLINE %s" % (res_line))
                    if re.search(regEx, res_line):
                        result = True
                        break
            #si la regex es una lista busca en el buffer las cadenas
            elif type(regEx) is list:
                tmp_regex_result = []
                local_result = False

                for each_regex in regEx:
                    for res_line in input_to_process.split('\n'):
                        self.loggerEq.debug("check-regex %s" % (regEx))
                        self.loggerEq.debug("RESLINE %s" % (res_line))
                        if re.search(regEx, res_line):
                            tmp_regex_result.append(True)
                            break

                #Regresa TRUE si todas las validaciones fueron correctas
                #de lo contrario regresa False
                result = all(tmp_regex_result)

            else:
                error = "Fallo al buscar xpath en salida de comando"
                raise Exception("Error: en " + __class__.__name__ +
                                                          "  %s " % (error))

            return result

        except Exception as err:
            error = ("El metodo command_check_success ha generado " +
                                       "una excepcion: %s" % (str(err)))
            self.loggerEq.error(error)
            raise Exception("Error: en " + __class__.__name__ + " %s " %
                                                                   (error))

    #Funcion que sirve para iniciar la instalacion
    def install_ios_commands(self, icommand, time_sleep, iXpath, ipkg):

        """
        Método utilizado para realizar la instalación del OS o SMU
        en el equipo.

        Args:
            :param arg1: Comando a ejecutar.
            :param arg2: Tiempo de espera.
            :param arg3: Expresión regular (Patrón de búsqueda).
            :param arg4: Nombre de paquete o imagen a instalar.

        Returns:
            True si todos los comandos de instalación fueron exitosos o False
            en otro caso.
            Salida (logs) de los comandos ejecutados.

        Raises:
            :Exception: Si ocurre un problema al realizar la instalación de 
             OS o SMU en el equipo.
        """
        
        try:
            comando_data = []
            pkg_no_actualizados = []
            comando_response = False
            try_reconnection = False

            #si el comando es PROBE inicia el testing
            #garantizar que probe no es el primer comando de la lista
            if re.search('probe', icommand, re.I):
                self.loggerEq.debug("En INSTALL ejecuta PROBE ")
                tiempo = 0
                res = False
                comando_data = ["PROBE " + str(res) + "\n"]

                self.loggerEq.info(self.router_name +
                                        ' Esperando tiempo de recuperacion')

                #TO-DO revisar el logger ya que esta erronmeo
                while res is False:
                    self.loggerEq.debug("En while del PROBE ")
                    res = self.probe_junos(1)
                    comando_response = res
                    tiempo = tiempo + 1

                    #Habilita la reconexion al router
                    if tiempo > 60:
                        try_reconnection = True
                        self.loggerEq.debug("Se necesita hacer la reconexion")

                    if tiempo == time_sleep:
                        self.loggerEq.debug("Tiempo maximo alcanzado " +
                                                                    time_sleep)
                        self.loggerEq.info(self.router_name +
                        'Error: tiempo maximo alcanzado durante upgrade ' +
                                                                       ipkg)

                        pkg_no_actualizados.append(ipkg)
                        self.loggerEq.debug("No se pudo actualizar " + ipkg)
                        self.loggerEq.info(self.router_name +
                        'Error: tiempo maximo alcanzado durante upgrade ' +
                                                                        ipkg)
                        resultado = "Error: tiempo maximo alcanzado" + \
                                                   " durante upgrade " + ipkg

                        self.data_for_db["idMetodo"] = id_metodo
                        self.data_for_db['idComando'] = self.id_comando
                        self.data_for_db['salida'] = 'No aplica'
                        self.data_for_db['resultado'] = resultado
                        #self.conDB.insert_data(INSERT_UPGRADE,
                                                          #self.data_for_db)
                        #El comando responde como falso
                        comando_response = res
                        comando_data = ["PROBE expiro el timer de espera\n"]

                        self.loggerEq.debug("PROBE EXPIRO")
                        exit(0)

                self.loggerEq.info(self.router_name +
                        ' Fin del tiempo de recuperacion, equipo alcanzable')

                #se valida si se requiere realizar la reconexion al router
                if try_reconnection is True:
                    self.open_connection('show')
                    self.loggerEq.debug("REALIZA la reconexion")

            else:

                self.loggerEq.debug("En INSTALL ejecuta COMANDO " + icommand)

                #Se ejecuta comando x comando
                comando_data = self.execute_command(icommand, time_sleep)

                self.loggerEq.debug("Validando COMANDO de la instalacion")

                #guarda los resultados para ser logueados
                #self.output_install.extend(idata)

                #TO-DO insertar a la db cada salida

                #Valida si la salida de cada comando es la esperada
                #El tercer paramentro indica que busca en todo el buffer
                comando_response = self.command_check_success(comando_data,
                                                               iXpath, 0)

            self.loggerEq.debug("INSTALL-IOS regresa response: " +
                                                        str(comando_response))
            self.loggerEq.debug("INSTALL-IOS regresa data: " +
                                                            str(comando_data))

            return comando_response, comando_data

        except Exception as e:
            error = ("El metodo install_ios_commands " +
                              "ha generado la excepcion: %s" % (str(e)))
            self.loggerEq.error(error)
            raise Exception("Error: en " + __class__.__name__ + " %s " %
                                                                   (error))

    def execute_command_copy_prp(self, command, time_to_sleep):

        """
        Método utilizado para realizar la copia de la imagen entre procesadoras
        en el equipo.

        Args:
            :param arg1: Comando a ejecutar.
            :param arg2: Tiempo de espera.

        Returns:
            True si la copia fue exitosa o False en otro caso.
            Salida (logs) de los comandos ejecutados.

        Raises:
            :Exception: Si ocurre un problema al realizar la copia de la 
             imagen entre procesadoras del equipo.
        """

        try:
            cont_bucle = 0
            flag = True
            flag_no_bucle = True
            response_val = False
            aux_response = ""
            self.connection.write((command + '\n').encode('ascii'))
            self.connection.write(('' + '\n').encode('ascii'))
            while flag:
                time.sleep(3)
                response = self.connection.read_very_eager().decode('ascii')
                exp_reg = re.search('bytes copied', response)
                exp_reg_error = re.search('Error | error', response)
                print (response)
                if exp_reg:
                    flag = False
                    response_val = True
                elif exp_reg_error:
                    response_val = False
                    break
                else:
                    self.loggerEq.info("Inicia configuracion en " + 
                                                            self.router_name)

            return response_val, response

        except Exception as e:
            error = ("El metodo execute_command_copy_prp " +
                              "ha generado la excepcion: %s" % (str(e)))
            self.loggerEq.error(error)
            raise Exception("Error: en " + __class__.__name__ + " %s " %
                                                                   (error))

    def delete_file(self, command, file, time_to_sleep):

        """
        Método utilizado para borrar archivos en el equipo.

        Args:
            :param arg1: Comando a ejecutar.
            :param arg2: Tiempo de espera.

        Returns:
            Salida (logs) de los comandos ejecutados.

        Raises:
            :Exception: Si ocurre un problema al borrar el archivo en 
             el equipo.
        """

        try:
            ruta = command + file
            self.connection.write((command + '\n').encode('ascii'))
            #guarda los resultados en un buffer
            self.connection.read_until(b"Delete ")
            self.connection.write(("\n").encode('ascii'))
            time.sleep(time_to_sleep)
            response = self.connection.read_very_eager().decode('ascii')
            return response

        except Exception as err:
            error = ("El metodo delete_file " +
                              "ha generado la excepcion: %s" % (str(err)))
            self.loggerEq.error(error)
            raise Exception("Error: en " + __class__.__name__ + " %s " %
                                                                   (error))
    
    def get_config(self, formato, filtro=None, to_sleep=2, source='running'):

        """
        Método utilizado para obtener configuracion del equipo.

        Args:
            :formato: N/A 

            :source: Nombre de la configuración que se desea consultar, 
                    por default es 'running'

            :filtro: Filtra la configuracion; el filtro tiene que ser en xml 

        Raises:
            :Exception: Si ocurre un problema al obtener configuracion
                del equipo.

        Returns:
            configuración obtenida.
        """

        try:
            
            if filtro is None: 
                config = self.execute_command("show running-config", 2)
            else:
                config = self.execute_command(filtro, to_sleep)

            return config

        except Exception as e:
            error = "Se ha generado una excepcion: %s" % (str(e))
            self.loggerEq.error(error)
            raise Exception(error)


    #Funcion que sirve para cerrar la conexion TELNET
    def close_connection(self):

        """
        Método utilizado para cerrar la conexion via Telnet al equipo.

        Raises:
            :Exception: Si ocurre un problema al cerrar la conexion 
             en el equipo.
        """

        self.connection.write(('end' + '\n').encode('ascii'))
        self.connection.close()
        self.loggerEq.info("Conexion cerrada a " + self.router_name)
