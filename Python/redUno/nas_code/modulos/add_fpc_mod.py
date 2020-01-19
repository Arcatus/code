import time
import re
from utilidades.log import Log
from utilidades.utilities import update_status_historico, insert_error
from conexion.connection_device import ConnectionDevice
from conexion.connection_database import ConnectionDataBase
from utilidades.constantes import CATALOGOS, USER_DB, PASSWORD_DB, \
                                                            HOST_DB, DATABASE
from base_datos.queries import *
from utilidades.xpath import Xpath
from utilidades.card_utilities import probe_tarjeta

class AddFpcMod():

    def __init__(self, device_data):

        super(AddFpcMod, self).__init__()
        self.ip = device_data[0].ip
        self.ci = device_data[0].ci
        self.hostname = device_data[0].host
        self.proveedor = device_data[0].proveedor
        self.id_ejecucion = device_data[0].idAccion
        self.id_historico = device_data[0].historico
        self.usuario = device_data[0].usuarioActualizacion
        self.user_device = device_data[1]
        self.pass_device = device_data[2]
        self.data = device_data
        self.conexion = None
        self.conDB = None
        self.id_tipo_ejecucion = None
        self.logEquipo = Log()
        self.loggerEq = self.logEquipo.setup_logger("logEquipo_%s" %
                        (self.hostname), "/script/nas_log/EquiposLog.log")

        self.data_for_db = {
                "id_historico": self.id_historico,
                "id_accion": self.id_ejecucion,
                "usuario_actualizacion": device_data[0].usuarioActualizacion,
                "salida": "No aplica"}

        self.data_db_interfaces = {
                "id_historico": self.id_historico
                }

        self.dataError_for_db = {"hostname": self.hostname,
                "usuario_actualizacion": device_data[0].usuarioActualizacion,
                "severidad": "Alta"}

    def validate_fpc(self, flujo_list, id_metodo):

        """
        Método utilizado para validar el estado de la fpc, valida si la tarjeta
        pasa del estado present a online. Si pasa a online antes de 10 minutos
        accion exitosa de lo contrario, regresa mensaje de error.

        Args:

        Returns:
            Acción correcta o con error.
        """
        try:
            self.loggerEq.info(self.hostname +
                                            ' Inicia validate_fpc')
            id_status_task = CATALOGOS["INICIO"]
            self.loggerEq.debug("Estatus del historico %s historico %s" 
                                         % (id_status_task, self.id_historico))
            update_status_historico(self.id_historico, id_status_task)
            val_xpath = Xpath()
            each_xpath = None
            connections_factory = ConnectionDevice(self.hostname, self.ip,
                                            self.user_device, self.pass_device)
            self.conexion = connections_factory.get_connection(self.proveedor)
            self.conexion.open_connection('show')
            for each_element_flow in flujo_list:
                self.command_list = each_element_flow.comandos 
                for each_cmd in self.command_list:

                    self.loggerEq.info("Ejecutando %s en %s" % (
                                        each_cmd.comando, self.hostname))                    
                    command = each_cmd.comando
                    if each_cmd.validaciones:

                        output_xml = self.conexion.execute_command(
                                                                command, 'xml')
                        for each_xpath in each_cmd.validaciones:
                            res_xpath = val_xpath.get_data(output_xml,
                                          each_xpath.validacion, self.proveedor,
                                                            each_cmd.comando)                        
                            res_probe = probe_tarjeta(self.conexion,
                                                self.proveedor, 600, command,
                                                        each_xpath.validacion)
                            if res_probe == True:
                                self.loggerEq.info(self.hostname +
                                                        ', [OK] Probes exitoso')
                                res_int = '[OK] Probe exitoso'
                                self.insert_datas_db(each_cmd.idComando,
                                                            id_metodo, res_int)
                            elif res_probe == False:
                                self.loggerEq.info(self.hostname +
                                                ', [Error] Probe no exitoso')
                                res_int = ('[Error] Probe no exitoso: ')
                                self.insert_datas_db(each_cmd.idComando,
                                                            id_metodo, res_int)
                                id_status_task = CATALOGOS["Fail"]
                                update_status_historico(self.id_historico,
                                                                id_status_task)
                                #data = (id_status_task, self.id_historico)
                                #self.conDB.update_data(UPDATE_STATUS_HISTORICO,
                                #                                        data)
                                
                                #self.loggerEq.debug("Se actualiza estado tarea\
                                #                            %s" % (str(data)))
                                return '[Error] Validacion fcp no exitosa'
                    else:
                        self.loggerEq.info(self.hostname +
                                    ', [Error] No contiene xpath el comando')

            id_status_task = CATALOGOS["OK"]
            update_status_historico(self.id_historico, id_status_task)
            return '[Ok] Validacion fcp exitosa'

        except Exception as e:
            id_status_task = CATALOGOS["Fail"]
            update_status_historico(self.id_historico, id_status_task)
            error = str(e)
            self.loggerEq.error("Se ha generado una excepcion" +
                                                  " en validacion %s" % (error))
            return "[Error] error en validate_fpc %s" % error

    def get_ports(self, flujo_list, id_metodo):

        """
        Método utilizado obtener las interfaces del equipo que va a ser
        configuradas asi como su velocidad con la cual van a ser configuradas.

        Args:

        Returns:
            Acción True o Fasle.
        """
        try:
            self.loggerEq.info(self.hostname +
                                            ' Inicia get_ports')
            id_status_task = CATALOGOS["INICIO"]
            self.loggerEq.debug("Estatus del historico %s historico %s" 
                                        % (id_status_task, self.id_historico))
            update_status_historico(self.id_historico, id_status_task)
            val_xpath = Xpath()
            each_xpath = None
            self.loggerEq.info(self.hostname +
                                    ', Obteniendo los puertos con su velocidad')
            for each_element_flow in flujo_list:
                self.command_list = each_element_flow.comandos 
                for each_cmd in self.command_list:

                    self.loggerEq.info("Ejecutando %s en %s" % (
                                        each_cmd.comando, self.hostname))                    
                    command = each_cmd.comando
                    if each_cmd.validaciones:

                        output_xml = self.conexion.execute_command(
                                                                command, 'xml')
                        for each_xpath in each_cmd.validaciones:
                            res_xpath = val_xpath.get_data(output_xml,
                                        each_xpath.validacion, self.proveedor,
                                                            each_cmd.comando) 
                            ports = verify_ports(self.proveedor, res_xpath)

            id_status_task = CATALOGOS["Ok"]
            update_status_historico(self.id_historico, id_status_task)
            return ports

        except Exception as e:
            id_status_task = CATALOGOS["Fail"]
            update_status_historico(self.id_historico, id_status_task)
            error = str(e)
            self.loggerEq.error("Se ha generado una excepcion" +
                                                  " en validacion %s" % (error))
            return "[Error] error en get_ports %s" % error
    
    
    def request_fpc(self, flujo_list, id_metodo):

        """
        Método utilizado para realizar un reuqest a la fpc para reiniciarl
        tambien valida que la tarjeta encienda y se encuentre en el estado 
        online.

        Args:

        Returns:
            Acción True o Fasle.
        """
        try:
            self.loggerEq.info(self.hostname +
                                            ' Inicia request_fpc')
            id_status_task = CATALOGOS["INICIO"]
            self.loggerEq.debug("Estatus del historico %s historico %s" 
                                        % (id_status_task, self.id_historico))
            update_status_historico(self.id_historico, id_status_task)
            val_xpath = Xpath()
            each_xpath = None
            pattern_fpc = '[0-9]+'
            connections_factory = ConnectionDevice(self.hostname, self.ip,
                                self.user_device, self.pass_device)
            self.conexion = connections_factory.get_connection(self.proveedor)
            self.conexion.open_connection('show')
            self.loggerEq.info(self.hostname +
                                        ' Antes de  flujo_list')
            self.loggerEq.info(self.hostname +
                                        ' ' + str(flujo_list))
            for each_element_flow in flujo_list:
                self.loggerEq.info(self.hostname +
                                                        ' Pasa flujo_list')
                self.command_list = each_element_flow.comandos 
                for each_cmd in self.command_list:
                    #LLAMA AL PRUBE
                    self.loggerEq.info(self.hostname +
                                ' Pasa command_list')
                    obj_command = each_cmd.comando
                    if each_cmd.validaciones:
                        self.loggerEq.info(self.hostname +
                                ' Pasa validaciones')
                        for each_xpath in each_cmd.validaciones:
                            self.loggerEq.info(self.hostname +
                                ' Pasa each_xpath')
                            pass
                    else:
                        if 'request' in obj_command:
                            if re.search(pattern_fpc, obj_command):
                                fpc = re.search(pattern_fpc,
                                                    obj_command).group()
                                print ('Entro al request')
                                self.loggerEq.info(self.hostname +
                                ', Ejecutando comando ' + obj_command)
                                #self.conexion.reboot_rpc(self, fpc)
                            else:
                                print ('Entro al request')
                                self.loggerEq.info(self.hostname +
                                        ' El comando no contiene la fpc')
                                return '[Error] El comando no contiene fpc'

            id_status_task = CATALOGOS["OK"]
            update_status_historico(self.id_historico, id_status_task)
            return '[Ok] Etapa request_fpc exitosa'

        except Exception as e:
            id_status_task = CATALOGOS["Fail"]
            update_status_historico(self.id_historico, id_status_task)
            error = str(e)
            self.loggerEq.error("Se ha generado una excepcion" +
                                                " en add_fpc_mod %s" % (error))
            return "[Error] error en request_fpc %s" % error

    def loop_test(self, id_metodo, flujo_list):

        """
        Método utilizado para realizar prueba de loops sobre los puertos de la
        fpc, si la prueba resulata exitosa se quita el puerto en la db, de lo
        contrario no se retira ese puerto de la db.

        Args:

        Returns:
            Acción True o Fasle.
        """

        try:
            self.loggerEq.info(self.hostname +
                                            ' Inicia loop_test')
            id_status_task = CATALOGOS["INICIO"]
            self.loggerEq.debug("Estatus del historico %s historico %s" 
                                        % (id_status_task, self.id_historico))
            update_status_historico(self.id_historico, id_status_task)
            val_xpath = Xpath()
            each_xpath = None
            pattern_loop = '(xe-|ge-|et-)([0-9]*\/*)*:*[0-9]*'
            puerto_in_db = self.conDB.get_data(OBTIENE_INTERFACES,
                                                           (self.id_historico,))
            long_base = len(puerto_in_db)
            list_full_ports = puerto_in_db[0][0]
            connections_factory = ConnectionDevice(self.hostname, self.ip,
                                            self.user_device, self.pass_device)
            self.conexion = connections_factory.get_connection(self.proveedor)
            self.conexion.open_connection('show')
            for each_element_flow in flujo_list:

                self.command_list = each_element_flow.comandos 
                for each_cmd in self.command_list:

                    self.loggerEq.info("Ejecutando %s en %s" % (
                                        each_cmd.comando, self.hostname))                    
                    command = each_cmd.comando
                    if each_xpath.validaciones:

                        output_xml = self.conexion.execute_command(
                                                                command, 'xml')
                        for each_xpath in each_cmd.validaciones:
                            res_xpath = val_xpath.get_data(output_xml,
                                          each_xpath.validacion, self.proveedor,
                                                            each_cmd.comando) 
                            self.loggerEq.info(self.hostname +
                                ', Prueba de loop al puerto: ' + 
                                                            each_cmd.comando)
                            if res_xpath == True:

                                if re.search(pattern_loop, command):
                                    each = re.search(pattern_loop, 
                                                                command)
                                    ##PONER EL JSON BIEN EN LOS PUERTOS
                                    port = each_cmd.puerto
                                    speed = each_cmd.speed
                                    port_speed = port + "%" + speed
                                    if ':' in port:

                                        port_wo_dots = port.split(":")[0]
                                        self.loggerEq.info(self.hostname +
                                                    'Eliminando puerto: ' + 
                                                            port_wo_dots)
                                        list_full_ports.replace(
                                                        port_wo_dots, "")
                                    else:

                                        self.loggerEq.info(self.hostname +
                                                    'Eliminando puerto: '
                                                            + port_speed)
                                        list_full_ports.replace(
                                                            port_speed, "")

                                    self.loggerEq.info(self.hostname +
                                    ' [OK] Prueba de loop: ' + each.group())
                                resultado_loop = ('[OK] Prueba de loop: ' +
                                                            each.group())
                                self.insert_datas_db(each_cmd.idComando,
                                                id_metodo, resultado_loop)
                            elif res_xpath == False:
                                pass
            list_full_ports = list_full_ports.split(",")
            string_to_db = ""
            for each_element in list_full_ports:
                    if each_element == "":
                        pass
                    else:
                        string_to_db = string_to_db + each_element + ","
            string_to_db = string_to_db.strip(",")
            self.data_db_interfaces['interfaces'] = string_to_db
            self.conDB.insert_data(INTERFACES_INSERTA,
                                                    self.data_for_db_interfaces)
            id_status_task = CATALOGOS["OK"]
            update_status_historico(self.id_historico, id_status_task)
            return '[ok] Etapa loop_test exitosa'

        except Exception as e:
            id_status_task = CATALOGOS["Fail"]
            update_status_historico(self.id_historico, id_status_task)
            error = str(e)
            self.loggerEq.error("Se ha generado una excepcion" +
                                                " en add_fpc_mod %s" % (error))
            return '[Error] Etapa loop_test no exitosa'

    def insert_datas_db(self, id_command, id_metodo, resulado):
        """
        Método utilizado para ingresar los datos en la db.

        Args:
            :param arg1: Commando a ejecutar
            :param arg2: Xpath del comando
            :param arg3: Contador de cada ciclo del probe
            :param arg4: Tiempo que se va a quedar dormido el probe

        Returns:
            Acción True o Fasle.
        """
        self.conDB = ConnectionDataBase(USER_DB, PASSWORD_DB,
                                                              HOST_DB, DATABASE)
        self.data_for_db['id_comando'] = id_command
        self.data_for_db["id_metodo"] = id_metodo
        self.data_for_db['resultado'] = resulado
        self.conDB.insert_data(INSERT_VALIDATION_XPATH, self.data_for_db)