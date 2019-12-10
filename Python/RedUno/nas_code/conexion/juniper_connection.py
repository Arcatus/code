# -*- coding: utf-8 -*-
__author__ = 'Jair Paredes, Arturo Herrera, Arturo Sánchez'
__copyright__ = 'Copyright 2019, UniNet'
__version__ = '2.0.0'
__email__ = 'jparedes@reduno.com.mx, arturohv@reduno.com.mx,' \
                                                    'arturosm@reduno.com.mx'
__status__ = 'Production'


from jnpr.junos import Device
import jnpr.junos.exception
from utilidades.log import Log
from jnpr.junos.utils.sw import SW
from jnpr.junos.utils.config import Config
from jnpr.junos.utils.start_shell import StartShell
from lxml import etree


class JuniperConnection:

    """
    Clase en donde se realizan las conexiones a los equipos de red.

    .. note::
        Los logs asociados al comportamiento de la funcion son depositados
        en la ruta script/dnos_log/EquiposLog.log.
        El nivel de severidad definido es INFO.
    """

    def __init__(self, router_name, ip_address, username, password):

        """
        Contructor de la clase ConnectionDevice

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
        self.dispositivo = None
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

        #seteamos el timer para un probe de conexion a 3s
        Device.auto_probe = 3
        self.dispositivo = Device(host=self.ip_address, user=self.username,
                                                        password=self.password)

        try:
            self.loggerEq.info("Iniciando conexion a %s" % (self.router_name))

            #Abre la conexion netconf al equipo
            self.dispositivo.open()

            #Se valida si la accion es de carga u obtencion de comandos
            if action == 'upload':
                self.dispositivo.timeout = 1200
            elif action == 'show':
                self.dispositivo.timeout = 60

            self.loggerEq.info("Conexion establecida a %s" %
                                                           (self.router_name))

        except jnpr.junos.exception.ConnectError as err:
            self.loggerEq.error("Cannot connect to device: %s %s"
                                             % (self.router_name, format(err)))

            raise Exception("Error: No se puede conectar al equipo.")


    def execute_command(self, command, command_format='xml',
                                                        time_to_sleep=None):

        """
        Método utilizado para executar comandos en los equipos, se utiliza la
        bandera de formato de comando para indicar si se extrae la informacion
        via XML o en salida estandar (show).

        Args:
            :param arg1: Comando a ejecutar.
            :param arg2: Formato de comando, (xml o show), default es xml

        Raises:
            Exception: Si ocurre un problema al obtener la información.

        Returns:
            Resultado del comando ejecutado.
        """

        try:
            response = self.dispositivo.rpc.cli(command, format=command_format)
            self.loggerEq.debug("COMANDO: %s, formato: %s" % (command, 
                                                                command_format))
            self.loggerEq.debug("RESPONSE: %s" % (response))
            return response

        except jnpr.junos.exception.RpcTimeoutError as e:
            error = "Se supero el tiempo de espera para recibir la " + \
                                           "respuesta del equipo, %s" % (str(e))
            self.loggerEq.error(error)
            raise Exception("Error: Se supero el tiempo de espera para " +
                                             "recibir la respuesta del equipo")

        except jnpr.junos.exception.PermissionError as e:
            error = "El equipo no permite ejecutar RPCs, %s" % (str(e))
            self.loggerEq.error(error)
            raise Exception("Error: El equipo no permite ejecutar RPCs.")

        except jnpr.junos.exception.RpcError as e:
            error = "%s ha generado una excepcion: %s" % (command, str(e))
            self.loggerEq.error(error)
            raise Exception("Error: Existe un error en la respuesta del "
                                                                   + "equipo.")


    def copy_file_to_processor(self, origen, destino, archivo):

        """
        Método utilizado para realizar la copia de la imagen al disco duro
        del equipo.

        Args:
            :param arg1: Path de origen.
            :param arg2: Path de destino.
            :param arg3: Nombre del archivo.
        Raises:
            Exception: Si ocurre un problema al realizar la copia de
                    la imagen.
        Returns:
            Indica si la copia fue exitosa o fallida.
        """

        try:
            copy_response = self.dispositivo.rpc.file_copy(source=origen +
                                                  archivo, destination=destino)
            return copy_response

        except Exception as e:
            error = "Se ha generado una excepcion: %s" % (str(e))
            self.loggerEq.error(error)
            raise Exception("Error: Fallo la copia del archivo.")

    def delete_file_to_device(self, ruta):

        """
        Método utilizado para realizar el borrado de archivos del disco duro
        del equipo.

        Args:
            :param arg1: ruta

        Raises:
            Exception: Si ocurre un problema al realizar el borrado de
                    archivos de la ruta indicada.
        Returns:
            Respuesta a la peticion de borrado.
        """

        try:
            delete_response = self.dispositivo.rpc.file_delete(path=ruta)
            return delete_response

        except Exception as e:
            error = "Se ha generado una excepcion: %s" % (str(e))
            self.loggerEq.error(error)
            raise Exception("Error: Fallo la eliminacion del archivo.")

    def reeboot_device(self):
        """
        Método utilizado para realizar el reinicio del equipo.

        Args:
            None
            :raises Exception si ocurre un problema al ejecutar el reinicio.
        Returns:
            None
        """

        try:
            self.loggerEq.info(self.router_name + ", reiniciando equipo..")
            sw = SW(self.dispositivo)
            sw.reboot()

        except Exception as e:
            error = "Se ha generado una excepcion: %s" % (str(e))
            self.loggerEq.error(error)
            raise Exception("Error: Fallo el reinicio del equipo.")

    def reboot_fpc(self, slot_fpc):
        """
            Método utilizado para reiniciar una FPC.

            Args:
                :slot_fpc: Slot de la fpc que se va a reiniciar

            Raises:
                :raises Exception si ocurre un problema al ejecutar el reinicio.

            Returns:
                None
        """
        try:

            self.dispositivo.rpc.request_chassis_fpc(slot=slot_fpc,
                                                             restart=True)
        except Exception as error:
            error = "Se ha generado una excepcion: %s" % (str(error))
            self.loggerEq.error(error)
            raise Exception("Error: Fallo el reboot de la fpc %s." % (slot_fpc))


    def configure(self, configuracion_list):

        """
        Método utilizado para realizar la configuración del equipo.

        Args:
            :param configuracion_list: Configuración a aplicar en el equipo.

        Raises:
            :Exception: Si ocurre un problema al aplicar configuración.

        Returns:
            None
        """

        try:
            configuracion = "\n".join(configuracion_list)

            with Config(self.dispositivo, mode='exclusive') as cu:
                self.loggerEq.info("Cargando configuracion en %s"
                                                         % (self.router_name))
                cu.load(configuracion)

                self.loggerEq.info("Configuracion cargada \n%s en %s" %
                                             (configuracion, self.router_name))

                dif = cu.diff()
                self.loggerEq.info("Dif: %s en %s"
                                                % (str(dif), self.router_name))

                commit_check = cu.commit_check()
                self.loggerEq.info("Commit check: %s en %s"
                                        % (str(commit_check), self.router_name))

                if commit_check:
                    self.loggerEq.info("Realizando commit.... en %s"
                                                           % (self.router_name))
                    cu.commit(sync=True, ignore_warning=True)

                    self.loggerEq.info("Commit realizado en %s"
                                                        % (self.router_name))
                else:
                    print ('PONER ROLLBACK')
                    self.loggerEq.info("Commit check fallido en %s"
                                                          % (self.router_name))

        except jnpr.junos.exception.LockError as err:
            self.loggerEq.error("Error no se puede ingresar a modo exclusive: \
                                                              {0}".format(err))
            raise Exception("Error no se puede ingresar a modo exclusive: \
                                                               {0}".format(err))
        except jnpr.junos.exception.ConfigLoadError as err:
            self.loggerEq.error("Error al ingresar la configuracion: \
                                                             {0}".format(err))
            raise Exception("Error al ingresar la configuracion:\
                                                               {0}".format(err))
        except jnpr.junos.exception.CommitError as err:
            self.loggerEq.error("Error al hacer el commit: {0}".format(err))
            raise Exception("Error al hacer el commit: {0}".format(err))
        except Exception as err:
            self.loggerEq.error("Se ha generado una excepcion al configurar \
                                                    el router: %s" % (str(err)))
            raise Exception("Error, Se ha generado una excepcion al configurar \
                                                    el router: %s" % (str(err)))

    def install_junos_to_device(self, pkg, ruta, hash):

        """
        Método utilizado para realizar la actualización del equipo.

        Args:
            :param arg1: Nombre de los paquetes a instalar.
            :param arg2: Path en donde se encuentran los paquetes.
            :param arg3: Hash de los paquetes a instalar.

        Raises:
            :Exception: Si ocurre un problema al realizar la instalación.

        Returns:
            Respuesta a la instalación y output de lo que se va ejecutando.
        """

        try:
            sw = SW(self.dispositivo)
            response = sw.install(package=pkg, validate=False,
                 progress=self.update_progress, remote_path=ruta,
                                             no_copy=True, all_re=True)

            return response, self.output_install

        except Exception as e:
            error = "Se ha generado una excepcion: %s" % (str(e))
            self.loggerEq.error(error)
            raise Exception("Error: " + (str(e)))

    def get_config(self, formato, filtro=None, to_sleep=None,
                                                        source='committed'):

        """
        Método utilizado para obtener configuracion del equipo.

        Args:
            :formato: Formato de configuración, puede ser text, xml,
                        set o json (Solo Juniper), para Cisco solo es xml

            :source: Nombre de la configuración que se desea consultar,
                     por default es 'committed'

            :filtro: Filtra la configuracion; el filtro tiene que ser en xml

        Raises:
            :Exception: Si ocurre un problema al obtener configuracion
                    del equipo.

        Returns:
            configuración obtenida.
        """

        try:

            #formato puede ser text, xml, set o json
            if 'committed' in source:
                opciones = {'database': source, 'format': formato}
            else:
                del opciones['database']

            if filtro is not None:
                filtro = etree.XML(filtro)

            config = self.dispositivo.rpc.get_config(filter_xml=filtro,
                                                          options=opciones)

            return config

        except Exception as e:
            error = "Se ha generado una excepcion: %s" % (str(e))
            self.loggerEq.error(error)
            raise Exception(error)

    def ping(self, ping_parameters):

        try:

            ping_ = self.dispositivo.rpc.ping(**ping_parameters)

            return ping_

        except Exception as e:
            error = "Se ha generado una excepcion en ping: %s" % (str(e))
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

        self.dispositivo.close()
        self.loggerEq.info("Conexion cerrada a " + self.router_name)

    def update_progress(self, dispositivo, report):

        """
        Método utilizado para manda al log el estatus de la actualización
        del equipo.

        Args:
            :param arg1: Nombre del dispositivo.
            :param arg2: Nombre del archivo en donde se genera el reporte.
        """

        self.loggerEq.info(self.router_name + '> ' + str(report))
        self.output_install.append(str(report))
        print (self.router_name, '> ', report)

    def clear_interfaces_statistics(self, commando):
        try:
            interfaz = commando.split()[-1]

            rpc = self.dispositivo.rpc.clear_interfaces_statistics(
                                                 interface_name= interfaz)
            
            if rpc is True:
                response = "Se limpiaron los contadores correctamente."
            else:
                response = "No pudo limpiar los contadores."

            return response

        except Exception as e:
            error = "Se ha generado una excepcion en " + \
                                  "clear interfaces statistics: %s" % (str(e))
            self.loggerEq.error(error)
            raise Exception(error)     

    def clear_arp_interface(self, commando):
        try:
            interfaz = commando.split()[-1]

            part1 = """
            <rpc>
            <clear-arp-table>
                <interface>"""

            part2 = """</interface>
            </clear-arp-table>
            </rpc>
            """
            comando_ = 'cli -c "%s"' % (commando)
            with StartShell(self.dispositivo) as ss:
                monitor_traffic = str(ss.run(comando_))

            if monitor_traffic[0] is True:
                response = "Se borro ARP correctamente."
            else:
                response = "No se pudo borrar el ARP." 
                
            return(monitor_traffic.replace('\\n','\n').replace('\\r','\r'))

        except Exception as e:
            error = "Se ha generado una excepcion en " + \
                                  "clear arp interface: %s" % (str(e))
            self.loggerEq.error(error)
            raise Exception(error)            
    
    def monitor_traffic_count_l2(self, commando):
        try:
            comando_ = 'cli -c "%s"' % (commando)

            with StartShell(self.dispositivo) as ss:
                monitor_traffic = str(ss.run(comando_))
                
            return(monitor_traffic.replace('\\n','\n').replace('\\r','\r'))

        except Exception as e:
            error = "Se ha generado una excepcion en " + \
                                  "monitor traffic count l2: %s" % (str(e))
            self.loggerEq.error(error)
            raise Exception(error) 
        


