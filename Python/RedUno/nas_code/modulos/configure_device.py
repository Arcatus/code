# -*- coding: utf-8 -*-
__author__ = 'Jair Paredes, Arturo Herrera, Arturo Sánchez'
__copyright__ = 'Copyright 2019, UniNet'
__version__ = '2.0.0'
__email__ = 'jparedes@reduno.com.mx, arturohv@reduno.com.mx,' \
                                                    'arturosm@reduno.com.mx'
__status__ = 'Production'

from utilidades.utilities import probe_connection, \
                                 insert_error, probe_telnet_connection
from conexion.connection_device import ConnectionDevice
from conexion.connection_database import ConnectionDataBase
from base_datos.queries import  INSERT_VALIDATION_XPATH
from utilidades.constantes import USER_DB, PASSWORD_DB, HOST_DB, DATABASE            
from utilidades.log import Log


class ConfigureDevice:

    """
    Clase que realiza la configuracion en el router.

    .. note::
        Los logs asociados al comportamiento de la funcion son depositados
        en la ruta script/nas_log/ConfiguracionLog.log.
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

        self.logConf = Log()
        self.loggerConf = self.logConf.setup_logger("logConf_%s" %
                        (self.hostname), "/script/nas_log/EquiposLog.log")

        #Diccionarios con la info necesaria para realizar los
        #insert en la db
        self.data_for_db = {"id_historico": self.id_historico,
                            "id_accion": self.id_ejecucion,
                            "usuario_actualizacion": self.usuario}

    def configuration(self, flujo_list, id_metodo):
        """
        Método utilizado para realizar la configuracion en los equipos.
        Aqui se van ejecutando los comandos derivados del flujo seleccionado
        por el usuario.

        Args:
            command_list_to_validate: Lista de comandos con su xpath para
                realizar la validacion.
            id_metodo:  Id del metodo a ejecutar

        Raises:
            :Exception: Si ocurre un problema durante la ejecución de
            actividades.

        Returns:
            Mensaje de acción correcta o con error.
        """

        try:
            self.loggerConf.debug("INICIA::ConfigureDevice::configuration")

            #Se crea conexion a la DB
            connection_db = ConnectionDataBase(USER_DB, PASSWORD_DB, HOST_DB,
                                                        DATABASE)

            #Se crea conexion al equipo
            connections_factory = ConnectionDevice(self.hostname, self.ip,
                                           self.user_device, self.pass_device)

            #Se prueba conectividad al equipo (NETCONF)
            cxn_netconf = probe_connection(self.ip, 830)
            cxn_telnet = probe_connection(self.ip,23)
            flag_COU = False
            
            self.loggerConf.debug("Conectividad via NETCONF %s, Telnet %s en %s" 
                         % (str(cxn_netconf), str(cxn_telnet), self.hostname))


            if cxn_telnet is True:
                
                if "Comandos COU" in self.nombreAccion:
                    flag_COU = True
                
                #Se abre la conexion al equipo
                if flag_COU is True and self.proveedor == "Juniper":
                    connection_dev = connections_factory.get_connection(
                                                                self.proveedor)
                elif flag_COU is False and cxn_netconf is True:
                    connection_dev = connections_factory.get_connection(
                                                                self.proveedor)
                else:
                    connection_dev = connections_factory.get_connection(
                                                                "Cisco_telnet")
                
                connection_dev.open_connection('show')
                
                for flujo in flujo_list:
                    #Se obtiene los comandos
                    command_list = flujo.comandos
                    id_comando = command_list[0].idComando
                    config_to_execute = []

                    for each_command in command_list:
                        config_to_execute.append(each_command.comando)
    
                    self.loggerConf.debug("Configurando equipo..., %s"
                                                             % (self.hostname))

                    connection_dev.configure(config_to_execute)

                resultado = "Los comandos se configuraron exitosamente."

                self.data_for_db["id_comando"] = id_comando
                self.data_for_db["resultado"] = resultado
                self.data_for_db["id_metodo"] = id_metodo
                self.data_for_db["salida"] = "N/A"
                
            else:
                self.loggerConf.error("No se puede conectar a equipo,  %s" 
                                                            % (self.hostname))

                raise Exception("No se puede conectar a equipo,  %s" 
                                                            % (self.hostname))

            connection_db.insert_data(INSERT_VALIDATION_XPATH, self.data_for_db)

            json_response = {"error": False}
            
            self.loggerConf.debug("FIN::ConfigureDevice::configuration")

            return json_response

        except Exception as error:
            self.loggerConf.error("Se ha generado una excepcion" +
                                            " en configuracion %s" % (error))

            if id_comando is not None:
                insert_error(self.hostname, "Alta", id_comando, 
                                            id_metodo, error,  self.data_for_db)

            raise Exception("Se ha generado una excepcion en %s, %s." % 
                                                    (self.hostname, str(error)))

        finally:
            #Se cierra la conexion si esta fue abierta.
            if connection_dev is not None:
                connection_dev.close_connection()