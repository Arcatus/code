# -*- coding: utf-8 -*-
__author__ = 'Jair Paredes, Arturo Herrera, Arturo Sánchez'
__copyright__ = 'Copyright 2019, UniNet'
__version__ = '2.0.0'
__email__ = 'jparedes@reduno.com.mx, arturohv@reduno.com.mx,' \
                                                    'arturosm@reduno.com.mx'
__status__ = 'Production'

import logging
from logging.handlers import RotatingFileHandler


class Log:

    """
    Clase que define la manera en que se crean los logs que genera la
    aplicación.
    """

    def __init__(self):
        self.logger = {}

    def setup_logger(self, name, log_file):

        """
        Método utilizado para crear los archivos de log que usa la aplicación,
        se crearan archivos de 200Mb y cada que se alcance ese tamanio se
        creara un archivo nuevo.

        Args:
            :param arg1: Nombre del handler.
            :param arg2: Nombre del archivo de log.

        Returns:
            Handler definido.

        .. note::
            El tamaño máximo total de logs que puede generar la aplicación son
            100 Gb
        """

        logging.getLogger(name).handlers.clear()
        self.logger = logging.getLogger(name)
        handler = RotatingFileHandler(log_file, maxBytes=200000000,
                                                                backupCount=50)
        formatter = logging.Formatter('%(asctime)s %(levelname)s %(message)s')
        handler.setFormatter(formatter)

        #Establece el umbral para que el logger muestre los niveles
        #iguales o superiores. (Como el log de los routers)
        self.logger.setLevel(logging.DEBUG)

        self.logger.addHandler(handler)

        return self.logger
