# -*- coding: utf-8 -*-
__author__ = 'Jair Paredes, Arturo Herrera, Arturo Sánchez'
__copyright__ = 'Copyright 2019, UniNet'
__version__ = '2.0.0'
__email__ = 'jparedes@reduno.com.mx, arturohv@reduno.com.mx,' \
                                                    'arturosm@reduno.com.mx'
__status__ = 'Production'

import importlib
from utilidades.log import Log


#Clase que se encarga de la creacion de objetos de manera dinamica
class Reflection:

    """
    Clase utilizada para crear objetos de manera dinámica.

    .. note::
        Los logs asociados al comportamiento de la funcion son depositados
        en la ruta script/dnos_log/ProgramaLog.log.
        El nivel de severidad definido es INFO.
    """

    def __init__(self, ruta_archivo, nombre_clase, arg=None):

        """
        Contructor de la clase Reflection.

        Args:
            :param argv1: Ruta en donde se encuentra el paquete.
            :param argv2:  Nombre de la clase a invocar.
            :param argv3:  El default es None
        """

        self.file = ruta_archivo
        self.clase = nombre_clase
        self.argumentos = arg
        self.logRefl = Log()
        self.loggerRefl = self.logRefl.setup_logger("logProg",
                                           "/script/nas_log/ProgramaLog.log")

    def get_object(self):

        """
        Método utilizado para la creación de objetos dinámicos que son
        invocados por el flujo dado.

        Args:
            None

        :Returns:
            Objeto dinámico.
        """

        try:
            self.loggerRefl.debug("INICIA::Reflection::get_object")

            module = importlib.import_module(self.file)
            class_ = getattr(module, self.clase)

            if self.argumentos is not None:
                objeto_dinamico = class_(self.argumentos)
            else:
                objeto_dinamico = class_()

            self.loggerRefl.debug("Objeto dinamico %s" %
                                                    (type(objeto_dinamico)))

            self.loggerRefl.debug("FIN::Reflection::get_object")

            return objeto_dinamico

        except Exception as e:
            self.loggerRefl.error("Excepcion en reflection, %s" % (e))
