# -*- coding: utf-8 -*-
__author__ = 'Jair Paredes, Arturo Herrera, Arturo Sánchez'
__copyright__ = 'Copyright 2019, UniNet'
__version__ = '2.0.0'
__email__ = 'jparedes@reduno.com.mx, arturohv@reduno.com.mx,' \
                                                    'arturosm@reduno.com.mx'
__status__ = 'Production'

from utilidades.log import Log
from utilidades.constantes import USER_DB, PASSWORD_DB, HOST_DB, DATABASE
from modulos.actions import Actions
from base_datos.queries import USUARIO_EQUIPOS, PASSWORD_EQUIPOS
from conexion.connection_database import ConnectionDataBase
import concurrent.futures
import time


class Concurrency:

    """
    Clase que realiza la ejecución de acciones por cada usuario en el router.

    .. note::
        Los logs asociados al comportamiento de la funcion son depositados
        en la ruta script/nas_log/ProgramaLog.log.
        El nivel de severidad definido es INFO.
    """

    def __init__(self, datos):
        self.num_tareas = len(datos)
        self.informacion = datos
        self.clog = Log()
        self.loggerProg = self.clog.setup_logger("logProg",
                                           "/script/nas_log/ProgramaLog.log")

    #Creación de tareas concurrentes, recibe como parametro
    #una lista de tareas
    def make_threads(self):

        """
        Método utilizado para ejecutar las tareas de cada usuario en los
        equipos de manera concurrente.
        Aquí se van ejecutando las acciones del flujo seleccionado por el
        usuario.

        Args:
            :param arg1: Lista de tareas

        Raises:
            Exception: Si ocurre un problema durante la ejecución de
            actividades.

        Returns:
            JSON: Se indica si la solicitud fue
            exitosa u ocurrio algún error.
        """

        try:
            return_message = {"routers": []}
            t0 = time.time()

            self.loggerProg.debug("INICIO::Concurrency::make_threads")
            self.loggerProg.debug("Se crean %s hilos" % (str(self.num_tareas)))

            #Se obtiene las credenciales para conectarse al router
            con_db = ConnectionDataBase(USER_DB, PASSWORD_DB, HOST_DB, DATABASE)

            user_dev = con_db.get_data(USUARIO_EQUIPOS)[0][0]
            pass_dev = con_db.get_data(PASSWORD_EQUIPOS)[0][0]

            actions = Actions(user_dev, pass_dev)

            #Se crean los threads correspondientes al numero de routers.
            #La funcion que ejecutara los modulos es make_tasks
            with concurrent.futures.ThreadPoolExecutor(
                                    max_workers=self.num_tareas) as executor:

                future_to_values = {
                        executor.submit(actions.execute_methods,
                                    router.metodos, router.datosEquipo):
                                          router for router in self.informacion
                        }

                for future in concurrent.futures.as_completed(future_to_values):
                    task = future_to_values[future]  # Tareas completadas
                    
                    if task.datosEquipo.nombreAccion is None:
                        task.datosEquipo.nombreAccion = "Null"

                    info_task = "%s - %s - %s" % (task.datosEquipo.host,
                                            task.datosEquipo.ip, 
                                 task.datosEquipo.nombreAccion.encode('utf-8'))

                    try:
                        data = future.result()  # Valor regresado por cada hilo

                        if type(data) is dict:
                            return_message["routers"].append(data)

                    except Exception as exc:
                        self.loggerProg.error('%s generated an exception: %s'
                                                     % (info_task, str(exc)))

                    else:
                        #las tareas exitosas son logueadas al archivo de log
                        self.loggerProg.info('%s tarea procesada' % (info_task))

            t1 = time.time()

            self.loggerProg.info("Tiempo de ejecucion: " + str(t1 - t0) + 
                                                                        " sec")
            self.loggerProg.debug("FIN::Concurrency::make_threads")

            return return_message

        except Exception as error:
            self.loggerProg.error("Se ha generado una excepcion en " +
                                            " concurrencia, %s" % (str(error)))