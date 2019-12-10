# -*- coding: utf-8 -*-
__author__ = 'Jair Paredes, Arturo Herrera, Arturo Sánchez'
__copyright__ = 'Copyright 2019, UniNet'
__version__ = '2.0.0'
__email__ = 'jparedes@reduno.com.mx, arturohv@reduno.com.mx,' \
                                                    'arturosm@reduno.com.mx'
__status__ = 'Production'

from utilidades.utilities import insert_error, validation
from conexion.connection_device import ConnectionDevice
from conexion.connection_database import ConnectionDataBase
from base_datos.queries import INSERT_VALIDATION_XPATH
from utilidades.constantes import USER_DB, PASSWORD_DB, HOST_DB, DATABASE
from utilidades.log import Log


class ValidationDevice:

    """
    Clase que realiza la validación de acciones en el router.

    .. note::
        Los logs asociados al comportamiento de la funcion son depositados
        en la ruta script/dnos_log/ValidacionLog.log.
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

        self.logVal = Log()
        self.loggerVal = self.logVal.setup_logger("logVal_%s" %
                        (self.hostname), "/script/nas_log/ValidacionLog.log")

        #Diccionarios con la info necesaria para realizar los
        #insert en la db
        self.data_for_db = {"id_historico": self.id_historico,
                            "id_accion": self.id_ejecucion,
                            "usuario_actualizacion": self.usuario}

    #Funcion que realiza la validacion del equipo
    def validation(self, flujo_list, id_metodo):
        """
        Método utilizado para realizar las validaciones en los equipos.
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
            self.loggerVal.debug("INICIA::ValidationDevice::validation")

            error_val_xpath = False
            connection_dev = None
            flag_error_flow = False
            result_list = []
            flujo_list_response = []

            #Se crea objeto para la conexion a la DB
            connection_db = ConnectionDataBase(USER_DB, PASSWORD_DB, HOST_DB,
                                                        DATABASE)
                                                        
            #Se abre la conexion al equipo
            connections_factory = ConnectionDevice(self.hostname, self.ip,
                                self.user_device, self.pass_device)

            connection_dev = connections_factory.get_connection(self.proveedor)

            #Le indicamos que la conexion obtiene solo comandos show
            connection_dev.open_connection('show')

            for flujo in flujo_list:
                self.loggerVal.info("INICIO de validacion:: flujo %s, equipo %s"
                                    % (flujo.nombreFlujo, self.hostname))

                self.command_list = flujo.comandos

                result_list = []

                json_flujo = {
                        "Flujo": flujo.nombreFlujo
                    }

                for each_command in self.command_list:
                    resultado = []
                    registro_db = None

                    json_val = {
                            "comando": each_command.comando
                            }

                    self.loggerVal.info("Ejecutando %s en %s" % (
                                        each_command.comando, self.hostname))

                    #Comprueba si el comando tiene validaciones
                    if each_command.validaciones:
                        #Ejecuta el comando en el equipo
                        output_xml = connection_dev.execute_command(
                                                    each_command.comando, 'xml')

                        output_command = connection_dev.execute_command(
                                                   each_command.comando, 'text')

                        #Inicia la validacion del comando
                        for x_path in each_command.validaciones:
                            res_xpath = validation(output_xml,
                                    x_path.validacion, 
                                    x_path.tipoValidacion.idCatalogoNivelUno,
                                    self.proveedor, each_command.comando)

                            self.loggerVal.debug("\n\nSe valida XPATH," +
                                    "%s -> %s \n" % (x_path.validacion, 
                                                                    res_xpath))

                            if res_xpath is True:
                                resultado.append(str(x_path.descripcion) +
                                                                    ' [OK]\r\n')
                            elif res_xpath is False:
                                error_val_xpath = True
                                resultado.append(str(x_path.descripcion)
                                                            + ' [Error]\r\n')
                            else:
                                #Valida que res_xpath no este vacio.
                                #Puede ser vacio porque la etiqueta no existe
                                #en el xml.
                                if res_xpath:
                                    if type(res_xpath) is float:
                                        resultado.append(str(x_path.descripcion)
                                           + ': ' + str(int(res_xpath)) +
                                                                       '\r\n')
                                    elif type(res_xpath) is list:
                                        resultado.append(str(x_path.descripcion)
                                                                    + '\r\n\n')
                                        for x_path in res_xpath:
                                            resultado.append(x_path.text
                                                                     + "\r\n\n")
                                    else:
                                        resultado.append(str(x_path.descripcion)
                                         + ': ' + str(res_xpath[0].text).strip(
                                                                '\n') + '\r\n')
                                else:
                                    resultado.append(str(x_path.descripcion)
                                      + ': ' + "No se encontro ningun valor."
                                                                        + '\n')

                        registro_db = "".join(resultado)

                        self.data_for_db["id_comando"] = each_command.idComando
                        self.data_for_db["resultado"] = registro_db
                        self.data_for_db["id_metodo"] = id_metodo

                        if type(output_command) is str:
                            self.data_for_db["salida"] = output_command
                            json_val["salida_equipo"] = output_command
                        else:
                            self.data_for_db["salida"] = output_command.text
                            json_val["salida_equipo"] = output_command.text

                        connection_db.insert_data(INSERT_VALIDATION_XPATH,
                                                            self.data_for_db)

                        json_val["resultado_xpath"] = registro_db
                        result_list.append(json_val)

                    else:
                        res_text = connection_dev.execute_command(
                                                each_command.comando, 'text')

                        if res_text is True:
                            registro_db = "El comando no regreso ningun " + \
                                                             "resultado.\r\n"
                        else:
                            registro_db = res_text.text + '\n'

                        self.data_for_db["id_comando"] = each_command.idComando
                        self.data_for_db["resultado"] = registro_db
                        self.data_for_db["salida"] = registro_db
                        self.data_for_db["id_comando"] = id_metodo

                        connection_db.insert_data(INSERT_VALIDATION_XPATH,
                                                             self.data_for_db)

                        json_val["salida_equipo"] = registro_db
                        json_val["resultado_xpath"] = "N/A"
                        result_list.append(json_val)

                json_flujo["Resultado"] = result_list

                #Si error_flag es verdadero coloca flag_error_flow en true
                if error_val_xpath is True:
                    flag_error_flow = True

                flujo_list_response.append(json_flujo)

                self.loggerVal.info("Fin de validacion:: flujo %s, equipo %s"
                                    % (flujo.nombreFlujo, self.hostname))

            json_response = {
                "hostname": self.hostname,
                "ci": self.ci,
                "ip": self.ip,
                "resultados": flujo_list_response
                }

            if flag_error_flow is True:
                json_response["error"] = True
            else:
                json_response["error"] = False

            self.loggerVal.debug("FIN::ValidationDevice::validation")

            return json_response

        except Exception as error:
            self.loggerVal.error("Se ha generado una excepcion" +
                                                " en validacion %s" % (error))

            if each_command is not None:
                idComando = each_command.idComando
                insert_error(self.hostname, "Alta", idComando, 
                                            id_metodo, error,  self.data_for_db)

            raise Exception("Se ha generado una excepcion en %s, %s." % 
                                                    (self.hostname, str(error)))

        finally:
            #Se cierra la conexion al equipo
            connection_dev.close_connection()
