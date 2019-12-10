# -*- coding: utf-8 -*-
__author__ = 'Josué Cirilo, Arturo Herrera'
__copyright__ = 'Copyright 2019, UniNet'
__version__ = '1.0.0'
__email__ = 'jcirilo@reduno.com.mx, arturohv@reduno.com.mx'
__status__ = 'Production'

from utilidades.utilities import insert_error, validation, probe_connection
from conexion.connection_device import ConnectionDevice
from conexion.connection_database import ConnectionDataBase
from base_datos.queries import INSERT_VALIDATION_XPATH
from utilidades.constantes import USER_DB, PASSWORD_DB, HOST_DB, DATABASE, \
                                  EXP_REG_REMOVE_CHAR, \
                                  ID_PING_COMMAND_TELNET
from utilidades.log import Log
import json

class PingModule:
    """
    Clase que realiza pings en los routers.

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
        self.nombreAccion = device_data[0].ayuda
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


    def ping(self, flujo_list, id_metodo):
        """
        Método utilizado para realizar pruebas de ping vía NETCONF y CLI en
        equipos Cisco y Juniper.

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

            flag_COU = False

            self.loggerExc.debug("INICIA::PingModule::ping")

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

            #Se usa cxn_telnet para validar que el equipo este operativo

            if "Comandos COU" in self.nombreAccion:
                flag_COU = True

            if cxn_telnet is True:

                if flag_COU is True and self.proveedor == "Juniper":
                    connection_dev = connections_factory.get_connection(
                                                                self.proveedor)
                elif flag_COU is False and cxn_netconf is True:
                    connection_dev = connections_factory.get_connection(
                                                                self.proveedor)
                else:
                    connection_dev = connections_factory.get_connection(
                                                                "Cisco_telnet")


                #Se abre conexion
                connection_dev.open_connection('show')

                for flujo in flujo_list:
                    #Se obtiene los comandos
                    self.loggerExc.info("INICIO de Ejecucion de ping:: flujo \
                            %s, equipo %s"% (flujo.nombreFlujo, self.hostname))

                    command_list = flujo.comandos

                    for each_command in command_list:
                        registro_db = str()

                        self.loggerExc.debug("Se ejecuta %s en %s"
                                        % (each_command.comando, self.hostname))


                        if each_command.idComando == ID_PING_COMMAND_TELNET:
                            self.loggerExc.debug("Ejecucion CLI en %s"
                                                              % (self.hostname))

                            resp = connection_dev.execute_command(
                                                    each_command.comando)

                            registro_db = resp

                        else:
                            self.loggerExc.debug("Ejecucion Netconf en %s"
                                                              % (self.hostname))

                            resultado = []

                            #Se convierte a diccionario la cadena
                            ping_dict = json.loads(each_command.comando)
                            resp_ = connection_dev.ping(ping_dict)

                            #Inicia la validacion del comando.
                            for validacion in each_command.validaciones:
                                res_val = validation(resp_,
                                                validacion.validacion,
                                                validacion.tipoValidacion.\
                                                            idCatalogoNivelUno,
                                                self.proveedor)

                                self.loggerExc.debug("\n\nSe valido, " +
                                        "%s -> %s en %s \n" %
                                            (validacion.validacion, res_val,
                                                                self.hostname))
                                if type(res_val) is bool:
                                    resultado.append("%s\n%s" %
                                                (validacion.descripcion,
                                                        str(res_val) + "\n\n"))
                                else:
                                    for val in res_val:
 
                                        resultado.append("%s %s" %
                                                (validacion.descripcion,
                                                        val.text + "\n"))

                            registro_db = "".join(resultado)

                        
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

            self.loggerExc.debug("FIN::PingModule::ping")

            return json_response

        except Exception as error:
            self.loggerExc.error("Se ha generado una excepcion" +
                                                  " en ping %s" % (error))

            if each_command.idComando is not None:
                insert_error(self.hostname, "Alta", each_command.idComando,
                                            id_metodo, error,  self.data_for_db)

            raise Exception("Se ha generado una excepcion en %s, %s." %
                                                    (self.hostname, str(error)))

        finally:
            #Se cierra la conexion si esta fue abierta.
            if connection_dev is not None:
                connection_dev.close_connection()
