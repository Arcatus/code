# -*- coding: utf-8 -*-
"""
    Este codigo es utilizado para definir las consultas que se realizan
    a la DB del sistema
"""
__author__ = 'Jair Paredes, Arturo Herrera, Arturo Sánchez'
__copyright__ = 'Copyright 2019, UniNet'
__version__ = '2.0.0'
__email__ = 'jparedes@reduno.com.mx, arturohv@reduno.com.mx,' \
                                                    'arturosm@reduno.com.mx'
__status__ = 'Production'

#Validacion
INSERT_VALIDATION_XPATH = "INSERT INTO ejecucion( \
                                id_metodo,  \
                                id_comando,  \
                                id_historico,  \
                                id_accion,  \
                                resultado, \
                                salida,  \
                                usuario_actualizacion) VALUES ( \
                                        %(id_metodo)s, \
                                        %(id_comando)s, \
                                        %(id_historico)s, \
                                        %(id_accion)s, \
                                        %(resultado)s, \
                                        %(salida)s, \
                                        %(usuario_actualizacion)s)"

UPDATE_STATUS_HISTORICO = "UPDATE historico SET id_Estado = %s \
                                                        WHERE id_historico = %s"

INSERT_VALIDATION_ERROR = "INSERT INTO error(    \
                                    id_comando, \
                                    info,    \
                                    severidad, \
                                    hostname,  \
                                    usuario_actualizacion) VALUES( \
                                            %(id_comando)s, \
                                            %(info)s, \
                                            %(severidad)s, \
                                            %(hostname)s,  \
                                            %(usuario_actualizacion)s)"


INSERT_VALIDATION_ERROR_ID = "INSERT INTO ejecucion( \
                                    id_metodo, \
                                    id_comando, \
                                    id_historico, \
                                    id_accion,  \
                                    id_error,  \
                                    resultado, \
                                    salida,  \
                                    usuario_actualizacion) VALUES (   \
                                            %(id_metodo)s, \
                                            %(id_comando)s,  \
                                            %(id_historico)s, \
                                            %(id_accion)s, \
                                            %(id_error)s, \
                                            %(resultado)s,  \
                                            %(salida)s,  \
                                            %(usuario_actualizacion)s)"

#UPLOAD
UPDATE_STATUS_UPLOAD_SUCCESS = "UPDATE historico SET imagen_subida = 1 \
                                                      WHERE id_historico = %s"

DELETE_HISTORICO_UPLOAD = "DELETE FROM imagen_router WHERE id_historico = %s"

#Semaforo para manejo de tareas
VALIDA_TAREA = "SELECT IF(count(*)=1,true,false) FROM historico WHERE \
                                         en_ejecucion=1 AND id_historico=%s"

LOCK_TAREA = "UPDATE historico SET en_ejecucion = '1' \
                                                    WHERE id_historico in (%s)"

RELEASE_TAREA = "UPDATE historico SET en_ejecucion = '0' \
                                                    WHERE id_historico in (%s)"

#Conexion a los equipos
USUARIO_EQUIPOS = "SELECT AES_DECRYPT(  \
                        valor,'arturosm-arturohv-jparedes-rolivare-rcelis') \
                             AS valor FROM parametro WHERE estado = '1' AND \
                                  nombre_parametro = 'Usuario Equipos'"

PASSWORD_EQUIPOS = "SELECT AES_DECRYPT(  \
                        valor,'arturosm-arturohv-jparedes-rolivare-rcelis') \
                             AS valor FROM parametro WHERE estado = '1' AND \
                                  nombre_parametro = 'Password Equipos'"

#Interfaces
INTERFACES_INSERTA = "INSERT INTO interface (id_historico,interfaces) VALUES ( \
                                            %(id_historico)s, \
                                            %(interfaces)s)"

OBTIENE_INTERFACES = "SELECT interfaces FROM interface where id_historico = %s"

#Estado de validacion despues de algun metodo
MINIVAL_ROUTER = "SELECT (IF((SELECT count(*) FROM ejecucion \
                    WHERE id_historico= %s AND id_metodo=%s AND \
                        resultado REGEXP 'Error')=0, 'true', 'false')) AS valor"
