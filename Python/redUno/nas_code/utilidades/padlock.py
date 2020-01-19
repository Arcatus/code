# -*- coding: utf-8 -*-
__author__ = 'Jair Paredes, Arturo Herrera, Arturo Sánchez'
__copyright__ = 'Copyright 2019, UniNet'
__version__ = '2.0.0'
__email__ = 'jparedes@reduno.com.mx, arturohv@reduno.com.mx,' \
                                                    'arturosm@reduno.com.mx'
__status__ = 'Production'

from utilidades.log import Log
from conexion.connection_database import ConnectionDataBase
from utilidades.constantes import USER_DB, PASSWORD_DB, HOST_DB, DATABASE
from base_datos.queries import VALIDA_TAREA, LOCK_TAREA
import json


class PadLock:

    """
    Clase que valida que una misma tarea no sea ejecutada por 2 o mas
    usuarios distintos.

    .. note::
        Los logs asociados al comportamiento de la funcion son depositados
        en la ruta script/nas_log/ProgramaLog.log.
        El nivel de severidad definido es INFO.
    """

    def __init__(self):
        self.padLog = Log()
        self.loggerPad = self.padLog.setup_logger("logProg",
                                            "/script/nas_log/ProgramaLog.log")
        self.devices_to_execute = []
        self.devices_refused = []
        self.tasks_not_executed = None

    def valida_accion_repetida(self, ObjetoJson):

        """
        Método utilizado para validar que no se lanzan acciones repetidas en
        el sistema.

        Args:
            :param arg1: JSON con acciones a ejecutar.
            :param arg2: Nombre de módulo.

        Raises:
            :Exception: Si ocurre un problema durante la ejecución de
            actividades.

        Returns:
            JSON que indica si fue exitoso u ocurrió algún problema.
        """

        try:
            conDB = ConnectionDataBase(USER_DB, PASSWORD_DB, HOST_DB, DATABASE)
            devices_to_block = tuple()

            #Se consulta que tareas tienen un estatus de ejecucion
            #esto se hace para no duplicar tareas
        
            #Se clasifican las tareas en 2 listas, las que se van
            #a ejecutar y las que no se pueden ejecutar
            for router in ObjetoJson.datos:
                self.tasks_not_executed = conDB.get_data(VALIDA_TAREA % 
                                              (router.datosEquipo.historico))

                self.loggerPad.debug("Tareas no ejecutadas:: %s en %s"
                                        % (router.datosEquipo.historico,
                                                str(self.tasks_not_executed)))

                if self.tasks_not_executed[0][0] == 0:
                    self.devices_to_execute.append(router)
                    devices_to_block += (router.datosEquipo.historico,)
                    self.loggerPad.info("Routers a ejecutar:: %s"
                                            % (router.datosEquipo.host))
                else:
                    self.devices_refused.append(router.datosEquipo.ci)

                    self.loggerPad.info("Routers rechazados:: %s"
                                                % (router.datosEquipo.host))

            #Si la lista contiene equipos se bloquean.
            if devices_to_block:
                ids = ",".join(["%s"] * len(devices_to_block))
                conDB.update_data(LOCK_TAREA % ids, devices_to_block)

            
            json_response = {}

            #Si la lista no esta vacia regresa el mensaje
            if self.devices_refused:
                json_response["Equipos_rechazados"] = self.devices_refused
                
            return json_response

        except Exception as e:
            self.loggerPad.error("Se ha generado una excepcion en padlock, %s "
                                                                         % (e))