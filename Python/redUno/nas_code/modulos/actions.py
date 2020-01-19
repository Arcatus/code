# -*- coding: utf-8 -*-
__author__ = 'Jair Paredes, Arturo Herrera, Arturo Sánchez'
__copyright__ = 'Copyright 2019, UniNet'
__version__ = '2.0.0'
__email__ = 'jparedes@reduno.com.mx, arturohv@reduno.com.mx,' \
                                                    'arturosm@reduno.com.mx'
__status__ = 'Production'

from utilidades.reflection import Reflection
from utilidades.log import Log
from base_datos.queries import RELEASE_TAREA
from conexion.connection_database import ConnectionDataBase
from utilidades.utilities import update_status_historico
from utilidades.constantes import CATALOGOS, USER_DB, PASSWORD_DB, \
                                                            HOST_DB, DATABASE
import time


class Actions:

    """
    Clase que realiza la actualizacion del OS en el router.

    note::
    Los logs asociados al comportamiento de la funcion son depositados
    en la ruta script/nas_log/ProgramaLog.log.
    El nivel de severidad definido es INFO.
    """

    def __init__(self, user, password):
        #self.datos_list = data_list
        self.user = user
        self.password = password
        self.action_log = Log()
        self.loggerAction = self.action_log.setup_logger("logProg",
                                            "/script/nas_log/ProgramaLog.log")

    def execute_methods(self, method_list, device_data):

        """
        Método utilizado para realizar la instalacion del OS en el equipo,
        aquí es en donde se hacen las llamadas de las acciones de manera
        dinámica.

        Args:
            None

        Raises:
            :Exception: Si ocurre un problema durante la ejecución de
            actividades.

        Returns:
            Mensaje de acción exitosa o con error.

        """

        try:
            obj = None
            module = None
            sleep_flag = 0
            error_flag = False
            id_method = None

            data = [device_data, self.user, self.password]

            self.loggerAction.debug("INICIO::Actions::execute_methods")

            #Se crea objeto para la conexion a la DB
            connection_db = ConnectionDataBase(USER_DB, PASSWORD_DB, HOST_DB,
                                                        DATABASE)
            
            #Actualiza el estado de la tarea en la tabla Historico
            id_status_task = CATALOGOS["INICIO"]
            self.loggerAction.debug("Estatus del historico %s historico %s" 
                                    % (id_status_task, device_data.historico))
            update_status_historico(device_data.historico, id_status_task)

            for method in method_list:
                try:
                    #Se obtiene la ruta de la clase, el nombre de la clase y el
                    #nombre de la funcion que sera ejecutada.
                    method_info = method.nombreMetodo.split(",")
                    self.loggerAction.debug("Method Info: %s" % 
                                                            (str(method_info)))

                    ruta_archivo = method_info[0]
                    class_name = method_info[1]
                    function_name = method_info[2]
                    sleep_flag += 1
                    response = None

                    #Flujos utilizado por cada funcion
                    flujos = method.flujos

                    #ID del metodo
                    id_method = method.idMetodo

                    #Se crea objeto dinamico
                    self.loggerAction.debug("Se crea el modulo %s" % 
                                                                (class_name))

                    obj = Reflection(ruta_archivo, class_name, data)
                    module = obj.get_object()

                    #Se ejecutan las funciones dinamicamente
                    self.loggerAction.debug("Se ejecuta la funcion %s" %
                                                            (function_name))

                    response = getattr(module, function_name)(flujos, id_method)

                    if response.pop("error") is True:
                        error_flag = True

                    #Si el for ejecuto la ultima accion no se duerme
                    if sleep_flag < len(method_list):
                        self.loggerAction.debug("SLEEP_I:Actions::"
                               + "execute_methods en %s" % (device_data.host))

                        time.sleep(2)

                        self.loggerAction.debug("SLEEP_F:Actions::" 
                                 + "execute_methods en %s" % (device_data.host))

                except Exception as e:
                    self.loggerAction.error("Se ha generado una excepcion al " 
                                    +  " ejecutar la funcion %s, %s" %
                                                    (function_name, str(e)))
                    raise Exception(e)

            
            if error_flag is True:
                id_status_task = CATALOGOS["Fail"]
            else:
                id_status_task = CATALOGOS["OK"]
            
            #Actualiza el estado de la tarea en la tabla Historico
            self.loggerAction.debug("Estatus del historico %s historico %s" 
                                    % (id_status_task, device_data.historico))
            update_status_historico(device_data.historico, id_status_task)

            self.loggerAction.debug("FIN::Actions::execute_methods")

            return response

        except Exception as e:
            #Actualiza el estado de la tarea en la tabla Historico
            id_status_task = CATALOGOS["Fail"]
            self.loggerAction.debug("Estatus del historico %s historico %s" 
                                    % (id_status_task, device_data.historico))
            update_status_historico(device_data.historico, id_status_task)

            self.loggerAction.error("Se ha generado una excepcion en methods,%s"
                                                                         % (e))

            msj_err = {"Hostname": device_data.host, "Mensaje_Error": str(e)}

            return msj_err

        finally:
            #Se desbloquea el equipo
            connection_db.update_data(RELEASE_TAREA, (device_data.historico, ))
            self.loggerAction.debug("Se desbloquea %s." % (device_data.host))
