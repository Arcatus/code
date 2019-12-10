import time
import re
from utilidades.log import Log
from conexion.connection_device import ConnectionDevice
from conexion.connection_database import ConnectionDataBase
from utilidades.constantes import *
from base_datos.queries import *
from utilidades.xpath import Xpath

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
        self.val_xpath = Xpath()
        self.conDB = None
        self.logEquipo = Log()
        self.loggerEq = self.logEquipo.setup_logger("logEquipo_%s" %
                        (self.hostname), "/script/nas_log/EquiposLog.log")

        self.data_for_db = {
                "idHistorico": self.id_historico,
                "idTipoEjecucion": self.id_ejecucion,
                "usuarioActualizacion": device_data[0].usuarioActualizacion,
                "salida": "No aplica"}

        self.data_db_interfaces = {
                "idHistorico": self.id_historico
                }

        self.dataError_for_db = {"hostname": self.hostname,
                "usuarioActualizacion": device_data[0].usuarioActualizacion,
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
            val_xpath = Xpath()
            connections_factory = ConnectionDevice(self.hostname, self.ip,
                                            self.user_device, self.pass_device)
            self.conexion = connections_factory.get_connection(self.proveedor)
            self.conexion.open_connection('show')
            for each_element_flow in flujo_list:
                self.command_list = each_element_flow.comandos 
                for each_cmd in self.command_list:
                    obj_command = each_cmd.comando
                    for each_xpath in each_cmd.validaciones:
                        if each_xpath.validacion != 'None':
                            self.loggerEq.info(self.hostname +
                                    ', Ejecutando comando ' + obj_command)
                            output_xml = self.conexion.execute_command(
                                                        obj_command, 'xml')
                            output_text = self.conexion.execute_command(
                                                        obj_command, 'text')

                            res_xpath = val_xpath.get_data(output_xml,
                                                        each_xpath.validacion,
                                                                    obj_command)
                            if res_xpath == bool:
                                res_probe = self.probe_slots(self, obj_command,
                                                each_xpath.validacion, 600, 1)
                                if res_probe == True:
                                    self.loggerEq.info(self.hostname +
                                                            ', [OK] Probes exitoso')
                                    res_int = '[OK] Probe exitoso'
                                    insert_datas_db(self, self.id_comando, id_metodo,
                                                                            res_int)
                                elif res_probe == False:
                                    self.loggerEq.info(self.hostname +
                                                    ', [Error] Probe no exitoso')
                                    res_int = ('[Error] Probe no exitoso: ')
                                    insert_datas_db(self, self.id_comando, id_metodo,
                                                                            res_int)
                                    id_status_task = self.get_task_status("Fail")
                                    data = (id_status_task, self.id_historico)
                                    self.conDB.update_data(UPDATE_STATUS_HISTORICO,
                                                                            data)
                                    self.loggerProg.debug("Se actualiza estado tarea\
                                                                %s" % (str(data)))
                                    return '[Error] Validacion fcp no exitosa'
                            else:
                                output_xml = self.conexion.execute_command(
                                                            obj_command, 'xml')
                                output_text = self.conexion.execute_command(
                                                            obj_command, 'text')
                                res_xpath = val_xpath.get_data(output_xml,
                                                obj_command.validaciones[0].validacion,
                                                                obj_command.comando)
                                string_to_db = self.json_pic_mod(self.conexion, 
                                                                        res_xpath)
                                self.data_db_interfaces['interfaces'] = string_to_db
                                self.conDB.insert_data(INTERFACES_INSERTA,
                                                        self.data_db_interfaces)
                    else:
                        print ('')
            id_status_task = self.get_task_status("OK")
            data = (id_status_task, self.id_historico)
            self.conDB.update_data(UPDATE_STATUS_HISTORICO, data)
            self.loggerEq.debug("Se actualiza estado de la tarea %s."
                                                                  % (str(data)))
            return '[Ok] Validacion fcp exitosa'

        except Exception as e:
            error = str(e)
            self.loggerEq.error("Se ha generado una excepcion" +
                                                  " en validacion %s" % (error))

    def request_fpc(self):

        """
        Método utilizado para realizar un reuqest a la fpc para reiniciarl
        tambien valida que la tarjeta encienda y se encuentre en el estado 
        online.

        Args:

        Returns:
            Acción True o Fasle.
        """

        try:
            val_xpath = Xpath()
            pattern_fpc = '[0-9]+'
            connections_factory = ConnectionDevice(self.hostname, self.ip,
                                self.user_device, self.pass_device)
            self.conexion = connections_factory.get_connection(self.proveedor)
            self.conexion.open_connection('show')
            for each_element_flow in flujo_list:
                self.command_list = each_element_flow.comandos 
                for each_cmd in self.command_list:
                    #LLAMA AL PRUBE
                    obj_command = each_cmd.comando
                    for each_xpath in each_cmd.validaciones:
                        if each_xpath.validacion != 'None':
                            if 'request' in obj_command.comando:
                                if re.search(pattern_fpc,obj_command):
                                    fpc = re.search(pattern_fpc,
                                                        obj_command).group()
                                    print ('Entro al request')
                                    self.loggerEq.info(self.hostname +
                                    ', Ejecutando comando ' + obj_command)
                                    #self.conexion.reboot_rpc(self, fpc)
                                else:
                                    print ('Entro al request')
                                    self.loggerEq.info(self.hostname + ' El comando\
                                                            no contiene la fpc')
                                    return '[Error] El comando no contiene la fpc'
                            else:

                                self.loggerEq.info(self.hostname +
                                    ', Ejecutando comando ' + obj_command.comando)
                                output_xml = self.conexion.execute_command(
                                                        obj_command, 'xml')
                                output_text = self.conexion.execute_command(
                                                        obj_command, 'text')

                                res_xpath = val_xpath.get_data(output_xml,
                                            each_xpath.validacion, obj_command)
                                res_probe = self.probe_slots(self, obj_command,
                                                each_xpath.validacion, 600, 1)
                                if res_probe == True:
                                    res_val_conf = "[Ok] Puertos ok offline/online"
                                    insert_datas_db(self, self.id_comando, id_metodo,
                                                                    res_val_conf)
                                elif res_probe:
                                    res_val_conf = "[Error] Puertos fuera de\
                                                                    offline/online"
                                    insert_datas_db(self, self.id_comando, id_metodo,
                                                                    res_val_conf)
                                    data = (ERROR_ACT_SO, self.id_historico)
                                    self.conDB.update_data(UPDATE_STATUS_HISTORICO,
                                                                            data)
                                    return "[Error] Puertos fuera de offline/online"

            data = (ACT_SO_OK, self.id_historico)
            self.conDB.update_data(UPDATE_STATUS_HISTORICO, data)

            id_status_task = self.get_task_status("OK")
            data = (id_status_task, self.id_historico)
            self.conDB.update_data(UPDATE_STATUS_HISTORICO, data)
            self.loggerEq.debug("Se actualiza estado de la tarea %s."
                                                                  % (str(data)))
            return '[Ok] Etapa exitosa'

        except Exception as e:
            error = str(e)
            self.loggerEq.error("Se ha generado una excepcion" +
                                                  " en validacion %s" % (error))

    def loop_test(self):

        """
        Método utilizado para realizar prueba de loops sobre los puertos de la
        fpc, si la prueba resulata exitosa se quita el puerto en la db, de lo
        contrario no se retira ese puerto de la db.

        Args:

        Returns:
            Acción True o Fasle.
        """

        try:
            val_xpath = Xpath()
            pattern_loop = '(xe-|ge-|et-)([0-9]*\/*)*:*[0-9]*'
            puerto_in_db = self.conDB.get_data(OBTIENE_INTERFACES,
                                                           (self.id_historico,))
            long_base = len(puerto_in_db)
            list_p_s =[]
            list_full_ports = puerto_in_db[0][0]
            loop_ok_ports = ""
            connections_factory = ConnectionDevice(self.hostname, self.ip,
                                            self.user_device, self.pass_device)
            self.conexion = connections_factory.get_connection(self.proveedor)
            self.conexion.open_connection('show')
            for each_element_flow in flujo_list:
                self.command_list = each_element_flow.comandos 
                for each_cmd in self.command_list:
                    obj_command = each_cmd.comando
                    for each_xpath in each_cmd.validaciones:
                        if each_xpath.validacion != 'None':
                            self.loggerEq.info(self.hostname +
                                ', Ejecutando comando ' + obj_command.comando)
                            output_xml = self.conexion.execute_command(
                                                    obj_command.comando, 'xml')
                            res_xpath = val_xpath.get_data(output_xml,
                                                        each_xpath.validacion,
                                                            obj_command)
                            self.loggerEq.info(self.hostname +
                                ', Prueba de loop al puerto: ' + 
                                                            obj_command)
                            if res_xpath is bool:
                                if res_xpath == True:
                                    if re.search(pattern_loop, obj_command):
                                        each = re.search(pattern_loop, 
                                                                    obj_command)
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
                                    insert_datas_db(self, self.id_comando,
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
            self.data_for_db_interfaces['interfaces'] = string_to_db
            self.conDB.insert_data(INTERFACES_INSERTA,
                                        self.data_for_db_interfaces)
            id_status_task = self.get_task_status("OK")
            data = (id_status_task, self.id_historico)
            self.conDB.update_data(UPDATE_STATUS_HISTORICO, data)

            self.loggerEq.debug("Se actualiza estado de la tarea %s."
                                                                    % (str(data)))
        except Exception as e:
            error = str(e)
            self.loggerEq.error("Se ha generado una excepcion" +
                                                  " en validacion %s" % (error))

    def probe_slots(self, command, xpath, time_for, time_sleep):

        """
        Método utilizado para actualizar el estado en la DB, dependiendo si
        fue exitosa u ocurrio algun fallo durante el apagado o encendido de
        interfaces.

        Args:
            :param arg1: Commando a ejecutar
            :param arg2: Xpath del comando
            :param arg3: Contador de cada ciclo del probe
            :param arg4: Tiempo que se va a quedar dormido el probe

        Returns:
            Acción True o Fasle.
        """
        try:
            val_xpath = Xpath()
            res_xpath = False
            tiempo = 0
            while res_xpath is False:
                output_xml = self.conexion.execute_command(command, 'xml')
                res_xpath = val_xpath.get_data(output_xml, xpath, command)
                tiempo = tiempo + 1
                if tiempo == time_for:
                    self.loggerEq.info(self.hostname +
                                            ', [Error]: Resultado no esperado ')
                    return False
                time.sleep(time_sleep)
            self.loggerEq.info(self.hostname +
                                                           ', Probe terminado ')
            return True
        except Exception as e:
            error = str(e)
            self.loggerEq.error("Se ha generado una excepcion" +
                                                  " en validacion %s" % (error))

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
        self.data_for_db['idComando'] = id_command
        self.data_for_db["idMetodo"] = id_metodo
        self.data_for_db['resultado'] = resulado
        self.conDB.insert_data(INSERT_UPGRADE, self.data_for_db)

    def get_task_status(self, status):

        """
        Método utilizado para actualizar el estado en la DB, dependiendo si
        fue exitosa u ocurrio algun fallo durante el apagado o encendido de
        interfaces.

        Args:
            :param arg1: Valor de estatus de la accion (OK o Fail)

        Returns:
            Acción correcta o con error.
        """
        task_status = None

        #Asigna el id del catalogo de validacion
        if status == "OK":
            if self.id_tipo_ejecucion == ACT_SO_ID:
                task_status = ACT_SO_OK

            elif self.id_tipo_ejecucion == ROLLBACK_ID:
                task_status = ROLLBACK_OK

        elif status == "Fail":
            if self.id_tipo_ejecucion == ACT_SO_ID:
                task_status = ERROR_ACT_SO

            elif self.id_tipo_ejecucion == ROLLBACK_ID:
                task_status = ERROR_ROLLBACK

        return task_status

def json_pic_mod(self,conexion, ports):
    ##PONER UN TRY
    """
    Método utilizado para separar la interfaces de una lista separados
    como pares interface/velocidad, regresa una cadena esta metodo.

    Args:
        :param arg1: Conexion que se hace a los equipos
        :param arg2: Lista de puertos

    Returns:
        Acción correcta o con error.
    """
    val_xpath = Xpath()
    port = ""
    pattern= '[0-9]*(GE|G|g|ge)'
    cmd_des_port = "show chassis hardware detail"
    xp_des_port = "//chassis-module[name=  variable_Slot]\
                                /chassis-sub-module[name= variable_Subslot]\
                                        /chassis-sub-sub-module/description"
    cmd_des_pic = "show chassis hardware detail"
    xp_des_pic = "//chassis-module[name= variable_Slot]/chassis-sub-module\
                                        [name= variableSubslot]/description"

    for each_int in ports:
        port = port + each_int +"%"
        if re.search("et", each_int):
            print (each_int)
            for each_element_flow in flujo_list:
                self.command_list = each_element_flow.comandos 
                for each_cmd in self.command_list:
                    obj_command = each_cmd.comando
                    for each_xpath in each_cmd.validaciones:
                        if each_xpath.validacion != 'None':
                            self.loggerEq.info(self.hostname +
                                    ', Ejecutando comando ' + obj_command)
                            output_xml = self.conexion.execute_command(
                                                        obj_command, 'xml')
                            res_xpath = val_xpath.get_data(output_xml,
                                                        each_xpath.validacion,
                                                                   obj_command)
                            res_xpath = "".join(output_xml)
                            if re.search(pattern, res_xpath):
                                result = re.search(pattern, res_xpath).group()
                                result = result.lower()
                                port = port + result + ","
                            else:
                                return "[Error] No se encontro el tipo de puerto"

        elif re.search("ge|xe|xle|fte", each_int):
            print ('interface:    ' + each_int)
            for each_element_flow in flujo_list:
                self.command_list = each_element_flow.comandos 
                for each_cmd in self.command_list:
                    obj_command = each_cmd.comando
                    for each_xpath in each_cmd.validaciones:
                        if each_xpath.validacion != 'None':
                            self.loggerEq.info(self.hostname +
                                ', Ejecutando comando ' + obj_command)
                            output_xml = self.conexion.execute_command(
                                                    obj_command, 'xml')
                            res_xpath = val_xpath.get_data(output_xml,
                                            each_xpath.validacion,
                                                                obj_command)
                            if re.search(pattern, output_text):
                                result = re.search(pattern, output_text).group()
                                result = result.lower()
                                port = port + result + ","
                            else:
                                return "[Error] No se encontro el tipo de puerto"
    port = port.rstrip(",")
    return port