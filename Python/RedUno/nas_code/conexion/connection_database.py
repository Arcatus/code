# -*- coding: utf-8 -*-
__author__ = 'Jair Paredes, Arturo Herrera, Arturo Sánchez'
__copyright__ = 'Copyright 2019, UniNet'
__version__ = '2.0.0'
__email__ = 'jparedes@reduno.com.mx, arturohv@reduno.com.mx,' \
                                                    'arturosm@reduno.com.mx'
__status__ = 'Production'

from mysql.connector import errorcode
import mysql.connector as connector
from utilidades.log import Log


class ConnectionDataBase:

    """
    Clase encargada de realizan las conexiones a la DB.

    .. note::
        Los logs asociados al comportamiento de la funcion son depositados
        en la ruta script/dnos_log/BaseLog.log.
        El nivel de severidad definido es INFO.
    """

    def __init__(self, usuario, password, host, database):

        """
        Contructor de la clase ConnectionDataBase.

        Args:
            :param arg1: User con permisos de conexion a la DB.
            :param arg2: Password del usuario con permisos de conexion a la DB.
            :param arg3: IP del equipo en donde se aloja la DB.
            :param arg4: Nombre de la DB.
        """

        self.user = usuario
        self.password = password
        self.server = host
        self.database = database
        self.conexionDB = None
        self.cursor = None
        self.connLog = Log()
        self.loggerDB = self.connLog.setup_logger("logbase",
                                                "/script/nas_log/BaseLog.log")

    def open_connection(self):

        """
        Método en donde se define la apertura de la conexion a la DB.

        Args:
            None
            :raises Exception si ocurre un problema con la conexion a la DB.

        Returns:
            None
        """

        try:
            self.conexionDB = connector.connect(user=self.user,
                                password=self.password, host=self.server,
                                                    database=self.database)

            self.cursor = self.conexionDB.cursor()

            self.loggerDB.debug("Conexion establecida en %s" % (self.server))

        except connector.Error as err:
            if err.errno == errorcode.ER_ACCESS_DENIED_ERROR:
                self.loggerDB.error('User o Password incorrectos')
                raise Exception("Error: User o Password incorrectos (DB).")

            elif err.errno == errorcode.ER_BAD_DB_ERROR:
                self.loggerDB.error('La Base de datos no existe')
                raise Exception("Error: La Base de datos no existe.")
            else:
                self.loggerDB.error('%s' % (str(err)))
                raise Exception("Error: Problema con la DB.")

    def insert_data(self, query, data):

        """
        Metodo utilizado para realizar las inserciones a la DB.

        Args:
            :param arg1: Query a ejecutar.
            :param arg2: Datos de los indices necesarios.

        Raises:
            :Exception: Si ocurre un problema con la conexion a la DB.

        Returns:
            Datos insertados o None, Si no hay valor disponible
        """

        try:
            self.open_connection()
            self.loggerDB.debug("Insertando dato, \n %s \n %s\n" % (query, 
                                                                        data))
            self.cursor.execute(query, data)
            self.conexionDB.commit()

            idInserted = self.cursor.lastrowid
            self.loggerDB.debug("Dato insertado, \n%s\n" % (data))

            return idInserted

        except Exception as e:
            self.loggerDB.error('Se ha generado una excepcion en database: %s '
                                                                   % (str(e)))
            raise Exception("Error:Se genero una excepcion en database: %s"
                                                                   % (str(e)))
        finally:
            self.close_connection()

    def update_data(self, query, values):

        """
        Método utilizado para realizar updates a la DB.

        Args:
            :param arg1: Query a ejecutar.
            :param arg2: Datos a actualizar.

        Raises:
            :Exception: Si ocurre un problema con la conexion a la DB.
        """

        try:
            self.open_connection()
            self.loggerDB.debug("Actualizando dato...")
            self.cursor.execute(query, values)
            self.conexionDB.commit()
            self.loggerDB.debug("Dato actualizado.")

        except Exception as exc:
            self.conexionDB.rollback()
            self.loggerDB.error('Se ha generado una excepcion en database: %s '
                                                                % (str(exc)))
            raise Exception("Error:Se genero una excepcion en database: %s"
                                                                % (str(exc)))
        finally:
            self.close_connection()

    def delete_data(self, query, values):

        """
        Método utilizado para borrar datos de la DB.

        Args:
            :param arg1: Query a ejecutar.
            :param arg2: Datos a eliminar.
            :raises Exception si ocurre un problema con la conexion a la DB.
        """

        try:
            self.open_connection()
            self.loggerDB.debug("Eliminando dato...")
            self.cursor.execute(query, values)
            self.conexionDB.commit()
            self.loggerDB.debug("Datos eliminados.")

        except Exception as exc:
            self.conexionDB.rollback()
            self.loggerDB.error('Se ha generado una excepcion: %s'
                                                                % (str(exc)))
            raise Exception("Error:Se genero una excepcion en database: %s"
                                                                % (str(exc)))
        finally:
            self.close_connection()

    def get_data(self, query, values=None):

        """
        Metodo utilizado para obtener informacion de la DB.

        Args:
            :param arg1: Query a ejecutar.
            :param arg2: Datos a eliminar.

        Raises:
            :Exception: Si ocurre un problema con la conexion a la DB.

        Returns:
            Datos consultados.
        """

        try:
            self.open_connection()
            self.loggerDB.debug("Obteniendo dato...")
            self.cursor.execute(query, values)
            data = self.cursor.fetchall()
            self.loggerDB.debug("Datos obtenidos")

            return data

        except Exception as gde:
            self.loggerDB.error('Se ha generado una excepcion en database: %s '
                                                                 % (str(gde)))
            raise Exception("Error:Se genero una excepcion en database: %s"
                                                                 % (str(gde)))
        finally:
            self.close_connection()

    def close_connection(self):

        """
        Metodo utilizado para cerrar la conexion a la DB

        Args:
            None
        """

        self.cursor.close()
        self.conexionDB.close()
        self.loggerDB.debug("Conexion cerrada en %s" % (self.server))
