# -*- coding: utf-8 -*-

__author__ = 'Josué Cirilo Cruz'
__copyright__ = 'Copyright 2019, UniNet'
__version__ = '1.0.0'
__email__ = 'jcirilo@reduno.com.mx'
__status__ = 'Production'

import persistqueue
from persistqueue import FIFOSQLiteQueue
import os
from utilidades.load_json_constructor import load_json_constructor
from sqlitedict import SqliteDict
import requests
import json

directory = '/home/carlos/Documentos/code/Python/RedUno/'

def update_ci_queues():

    """
    Método que actualiza la DB de equipos de Uninet.
    Args:
        None.
    Returns:
        DB_json: Archivo json con los CI actualizados desde SM.
    """

    peticion_json, db_dict = {}, {}

    respuesta_nas = requests.post('http://10.108.198.6:8082/consultarRoutersSM', \
        json=peticion_json)

    for element in respuesta_nas.json()['datos']:
        db_dict[element['ciRouter']] = element['hostname']

    with open('dbCI.json', 'w') as json_file:
        json.dump(db_dict, json_file)

def init_colas():

    """
    Método inicializador de colas: sensores, principal e individuales.

    Args:
        None.

    Returns:
        Colas: sensores, principal e individuales.
    """
    global directory

    equipos_queue_json = load_json_constructor(directory+'utilidades/dbCI.json')

    #print (equipos_queue_json)

    for x in equipos_queue_json:
        q_individual = persistqueue.SQLiteQueue(directory+'Queues_app/'+
                                equipos_queue_json[x].split('.')[0].replace('-',
                                                    '_'),auto_commit=True)
                                                    
    q_sensores = persistqueue.SQLiteQueue(directory+"Queues_app/Q_Sensors", 
                                                        multithreading=True)
    q_prin = persistqueue.SQLiteQueue(directory+'Queues_app/Queue_Prin', 
                                                            auto_commit=True)
    q_block = SqliteDict(directory+"Queues_app/Queue_block", autocommit=True)
    
    for x in equipos_queue_json:
        q_block[x] = 0

    return  q_prin, q_individual, q_sensores, q_block

def referencia_cola():

    """
    Método creador de colas temporal, que hace referencia a la principal.

    Args:
        None.

    Returns:
        Referencia a la cola principal.
    """
    global directory
    q_prin = persistqueue.SQLiteQueue(directory+'Queues_app/Queue_Prin', 
                                                            auto_commit=True)
    return q_prin