# -*- coding: utf-8 -*-
__author__ = 'Jair Paredes, Arturo Herrera, Arturo Sánchez'
__copyright__ = 'Copyright 2019, UniNet'
__version__ = '2.0.0'
__email__ = 'jparedes@reduno.com.mx, arturohv@reduno.com.mx,' \
                                                    'arturosm@reduno.com.mx'
__status__ = 'Production'

from ncclient import manager
from utilidades.log import Log
from lxml import etree
import socket
import datetime
import time
import xml.etree.ElementTree as ETL


class CiscoConnection:

    """
    Clase en donde se realiza la conexion Netconf a los equipos Cisco de la red.

    .. note::
        Los logs asociados al comportamiento de la funcion son depositados
        en la ruta script/dnos_log/EquiposLog.log.
        El nivel de severidad definido es INFO.
    """

    def __init__(self, router_name, ip_address, username, password):

        """
        Contructor de la clase CiscoConnection

        Args:
            :param arg1: Nombre del equipo al que se desea conectar.
            :param arg2: IP del equipo al que se desea conectar
            :param arg3: User con permisos de conexion al equipo.
            :param arg4: Password del usuario con permisos de conexion al
                         equipo.
        """

        self.router_name = router_name
        self.ip_address = ip_address
        self.username = username
        self.password = password
        self.connection = None
        self.output_install = []
        self.logDevice = Log()
        self.loggerEq = self.logDevice.setup_logger("logEquipos",
                                             "/script/nas_log/EquiposLog.log")

    #Funcion para abrir la conexion via NETCONF
    def open_connection(self, action):

        """
        Método en donde se define la apertura de la conexion a los equipos.

        Args:
            :param arg1: Define si se realiza una carga o un show,
                        dependiendo de la accion se  da un tiempo de espera.

        Raises:
            Exception: Si ocurre un problema con la conexión al equipo.

        Returns:
             None
        """

        try:
            self.loggerEq.info("Iniciando conexion a %s" % (self.router_name))

            #Por default el timeout es 30
            timeout_ = 30

            #Se valida si la accion es de carga u obtencion de comandos
            if action == 'upload':
                timeout_ = 1200
            elif action == 'show':
                timeout_ = 60

            #Abre la conexion netconf al equipo
            self.connection = manager.connect(host=self.ip_address,
                                              username=self.username,
                                              password=self.password,
                                              timeout=timeout_,
                                              device_params={'name': 'iosxr'})

            self.loggerEq.info("Conexion establecida a %s" %
                                                           (self.router_name))

        except Exception as err:
            self.loggerEq.error("Cannot connect to device: %s %s"
                                             % (self.router_name, format(err)))

            raise Exception("Error: No se puede conectar al equipo.")


    #Funcion para ejecutar los comandos en el equipo
    def execute_command(self, command, command_format=None, time_to_sleep=None):

        """
        Método utilizado para executar comandos en los equipos, se utiliza la
        bandera de formato de comando para indicar si se extrae la informacion
        via XML o en salida estandar (show).

        Args:
            :param arg1: Comando a ejecutar.
            :param arg2: Formato de comando, (xml o text), default es xml

        Raises:
            Exception: Si ocurre un problema al obtener la información.

        Returns:
            Resultado del comando ejecutado.
        """

        try:
            if command_format == 'text':
                response = "N/A"
            else:
                resp_getReply = self.connection.get(('subtree', command))
                response = resp_getReply.data

            return response

        except Exception as err:
            error = "%s ha generado una excepcion: %s" % (command, str(err))
            self.loggerEq.error(error)
            raise Exception("Error: Existe un error en la respuesta del "
                                                                   + "equipo.")

    def configure(self, configuracion_list):

        """
        Método utilizado para realizar la configuración del equipo.

        Args:
            :param arg1: Configuración a aplicar en el equipo.

        Raises:
            :Exception: Si ocurre un problema al aplicar configuración.

        Returns:
            None
        """

        try:
            configuracion_list.insert(0, "<config xmlns:xc='urn:ietf:params:xml:ns:netconf:base:1.0' xmlns='urn:ietf:params:xml:ns:netconf:base:1.0'>")
            configuracion_list.append("</config>")
            configuracion = "\n".join(configuracion_list)
            configuracion_xml = etree.XML(configuracion)

            self.loggerEq.info("Bloqueando configuracion candidata, %s" %
                                                            (self.router_name))

            with self.connection.locked(target='candidate'):
                
                self.loggerEq.info("Cargando configuracion, %s" %
                                                            (self.router_name))
                
                self.loggerEq.info("Configuracion a cargar %s en %s" %
                                            (configuracion,self.router_name))



                self.connection.edit_config(target='candidate',
                                            config=configuracion_xml,
                                            error_option='rollback-on-error',
                                                                format = 'xml')

                self.loggerEq.info("Configuracion cargada \n%s en %s" %
                                      (configuracion_xml, self.router_name))

                self.loggerEq.info("Validando configuracion... en %s"
                                                         % (self.router_name))

                validate_result = self.connection.validate()

                if validate_result.ok is True:
                    self.loggerEq.info("Configuracion validada, %s en %s" 
                                      % (validate_result.ok, self.router_name))

                    self.loggerEq.info("Realizando commit...., %s" %
                                                            (self.router_name))
                    self.connection.commit()

                    self.loggerEq.info("Commit realizado, %s" %
                                                            (self.router_name))
                else:
                    self.loggerEq.info("Fallo la validacion, %s, %s en %s" %
                                            (configuracion,
                                                validate_result.errors,
                                                            self.router_name))

        except Exception as err:
            self.loggerEq.error("Se ha generado una excepcion al configurar: %s"
                                                                 % (str(err)))

            raise Exception("Se ha generado una excepcion al configurar: %s" 
                                                                 % (str(err)))


    def get_config(self, formato, filtro=None, to_sleep=None, source="running"):

        """
        Método utilizado para obtener configuracion del equipo.

        Args:
            :formato: Formato de configuración, puede ser text, xml,
                        set o json (Solo Juniper), para Cisco solo es xml
                        
            :source: Nombre de la configuración que se desea consultar, 
                     por default es "running"
        
            :filtro: Filtra la configuracion; el filtro tiene que ser en xml 

        Raises:
            :Exception: Si ocurre un problema al obtener configuracion
                    del equipo.

        Returns:
            configuración obtenida.
        """

        try:
            filter_ = "<filter>%s</filter>" % (filtro)
            config = self.connection.get_config(source, filter=filter_)

            self.loggerEq.info("Response equipo....%s en  %s" %
                                                    (config,self.router_name))

            return config.data

        except Exception as e:
            error = "Se ha generado una excepcion: %s" % (str(e))
            self.loggerEq.error(error)
            raise Exception(error)

    def ping(self, ping_parameters):

        """
        Método utilizado para realizar pruebas de ping a otros equipos.

        Parameters:
            :ping_parameters: lista de opciones del ping

        Returns:
            No
        """

        try: 
            root = ETL.Element("destination")

            for element in ping_parameters:
                if ping_parameters[element] != None:
                    ETL.SubElement(root, element).text = ping_parameters[element]

            ping_xml = ETL.tostring(root).decode("utf-8") 

            ping_xml ='<ping xmlns=\
                            "http://cisco.com/ns/yang/Cisco-IOS-XR-ping-act">' \
                                         + ping_xml + '</ping>'

            ping_replay = self.connection.dispatch(ET.fromstring(ping_xml))

            return ping_replay
            
        except Exception as e:
            error = "Se ha generado una excepcion: %s" % (str(e))
            self.loggerEq.error(error)
            raise Exception(error)

    #Funcion que sirve para cerrar la conexion NETCONF
    def close_connection(self):

        """
        Método utilizado para cerrar la conexion al equipo.

        Parameters:
            None

        Returns:
            None
        """

        self.connection.close_session()
        self.loggerEq.info("Conexion cerrada a " + self.router_name)