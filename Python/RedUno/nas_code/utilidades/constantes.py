# -*- coding: utf-8 -*-

"""
Este codigo ilustra la definicion de constantes utilizadas por el programa
"""
__author__ = 'Jair Paredes, Arturo Herrera, Arturo Sánchez'
__copyright__ = 'Copyright 2019, UniNet'
__version__ = '2.0.0'
__email__ = 'jparedes@reduno.com.mx, arturohv@reduno.com.mx,' \
                                                    'arturosm@reduno.com.mx'
__status__ = 'Production'

DATABASE = 'gso'
HOST_DB = '10.100.100.3'
USER_DB = 'dnos'
PASSWORD_DB = 'dn0s'

EXP_REG_REMOVE_CHAR = r'[^show|\|][A-Z][a-z]{2}(.*\n*.*)*'
ID_COMANDO_CONF_JUN = 146
ID_PING_COMMAND_TELNET = 169

CATALOGOS = {"INICIO": 24, "OK": 25, "Fail": 26}

#ID del comando show configuration
ID_SH_CONFIG = 50

#ID del comando show configuration
ID_SH_CONFIG_CISCO = 113

#Numero de interfaces
NUMERO_INT = 5

#PATRON QUE BUSCA EL NOMBRE DE LAS IMAGENES
patron_imagenes = '((([a-zA-Z0-9]+_*(\.)*)*)[(\.)*][tar]+)|((([a-zA-Z0-9]+_*(\.)*)*)[(\.)*][pie]+)'
