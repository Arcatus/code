# -*- coding: utf-8 -*-
__author__ = 'Jair Paredes, Arturo Herrera, Arturo Sánchez'
__copyright__ = 'Copyright 2019, UniNet'
__version__ = '2.0.0'
__email__ = 'jparedes@reduno.com.mx, arturohv@reduno.com.mx,' \
                                                    'arturosm@reduno.com.mx'
__status__ = 'Production'


from conexion.juniper_connection import JuniperConnection
from conexion.cisco_connection import CiscoConnection
from conexion.cisco_tn_connection import CiscoTelnetConnection
from utilidades.log import Log


class ConnectionDevice:

    """
    Clase donde se realiza la instancia de las conexiones. (Factory)

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
        self.logCon = Log()
        self.loggerConEq = self.logCon.setup_logger("logEquipos",
                                             "/script/nas_log/EquiposLog.log")

    def get_connection(self, provider):

        """
        Método que realiza la instancia de la conexion dependiendo del
        proveedor.

        Args:
            :param arg1: Proveedor del equipo.

        Raises:
            :Exception: Si ocurre un problema con la creacion del objeto.

        Returns:
             :Regresa el objeto en base al proveedor.
        """

        try:
            self.loggerConEq.debug("INICIA::ConnectionDevice::get_connection")
            self.loggerConEq.debug("Provider %s" % (provider))

            if provider == "Cisco":
                return CiscoConnection(self.router_name, self.ip_address,
                                                  self.username, self.password)
            elif provider == "Juniper":
                return JuniperConnection(self.router_name, self.ip_address,
                                                  self.username, self.password)
            elif provider == "Cisco_telnet":
                return CiscoTelnetConnection(self.router_name, self.ip_address,
                                                  self.username, self.password)
            else:
                raise Exception("Error: No se especifico ninguna conexion "
                                             + " para %s" % (self.router_name))

            self.loggerConEq.debug("FIN::ConnectionDevice::get_connection")

        except Exception as e:
            self.loggerConEq.error("Se ha generado una excepcion en "
                                             + "get_connection, %s" % (str(e)))
