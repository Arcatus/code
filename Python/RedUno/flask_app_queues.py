# -*- coding: utf-8 -*-
# Para ejecutar, correr los siguientes comandos:
#       export FLASK_APP=flask_app_queues.py
#       python3.6 -m flask run, opcional --port=5001 --host=200.33.150.21

__author__ = 'Josué Cirilo Cruz'
__copyright__ = 'Copyright 2019, UniNet'
__version__ = '1.0.0'
__email__ = 'jcirilo@reduno.com.mx'
__status__ = 'Production'

from flask import Flask, request
import persistqueue
from utilidades.init_queues import init_colas, referencia_cola, update_ci_queues
import threading
import requests
import json
from collections import namedtuple
from utilidades.load_json_constructor import load_json_constructor
from persistqueue import FIFOSQLiteQueue
import random
import time

#update_ci_queues()

q_prin, q_individual, q_sensores, q_block = init_colas()
mutex = threading.Lock()
mutex_block = threading.Lock()
directory = '/home/carlos/Documentos/code/Python/RedUno/'

app = Flask(__name__)

def constructor_json_y_consulta_dnos(peticion_json):

    """
    Método que construye y envía el json al nas, según la acción.

    Args:
        host_name_mx: hostname de equipo al que se le aplicará la acción en el DNOS

    Returns:
        Respuesta de la acción hecha al DNOS.
    """

    respuesta_dnos = requests.post('http://200.33.150.59:5000/api/nas', 
                                                        json = peticion_json)
    return respuesta_dnos

def consulta_dnos_directa(resquest_json_direct):

    """
    Método que realiza una consulta al DNOS sin pasar por las colas.

    Args:
        resquest_json_direct: json de la consulta.

    Returns:
        Respuesta de la acción hecha al DNOS.
    """

    respuesta_dnos = constructor_json_y_consulta_dnos(resquest_json_direct)
    print(respuesta_dnos.json())
    return respuesta_dnos

def ejecucion_de_PS(i):

    """
    Método que ejecuta peticiones encoladas y reencola las fallidas

    Args:
        i: identificador del Thread.

    Returns:
        Respuesta de la acción hecha al DNOS.
    """

    global mutex, q_sensores, directory, q_block, mutex_block
    while True:
        equipos_queue_json = load_json_constructor(directory+
                                                        'utilidades/dbCI.json')
        block = 0
        temp_falla = None
        mutex.acquire()
        num_queue_unique = q_sensores.get()
        if num_queue_unique != 0:
            mutex_block.acquire()
            if q_block[num_queue_unique] == 0:
                q_block[num_queue_unique] = 1
                block = q_block[num_queue_unique]
            else:
                q_sensores.put(num_queue_unique)
            mutex_block.release()
        else:
            pass
        mutex.release()

        q_individual = persistqueue.SQLiteQueue(directory+'Queues_app/'+
                                equipos_queue_json[num_queue_unique].split(
                                    '.')[0].replace('-','_'), auto_commit=True)

        if len(q_individual) != 0 and num_queue_unique != 0:
            if block != 0:
                peticion_json = q_individual.get()
                dict_fallas = {"datos":[]}
                temp_falla = peticion_json
                respuesta_dnos = constructor_json_y_consulta_dnos(peticion_json)
                print("Respuesta NAS:", respuesta_dnos.json())
                print('Hilo: %s' % threading.current_thread().name,
                            'Hice la petición: %s' % peticion_json['datos'][0][
                                    'datosEquipo']['host'], num_queue_unique)
                if len(respuesta_dnos.json["Equipos_rechazados"]) == 0:                    
                    mutex_block.acquire()
                    q_block[num_queue_unique] = 0
                    mutex_block.release()
                else:
                    n = 0
                    for x in respuesta_dnos.json["Equipos_rechazados"]:
                        for y in temp_falla["datos"]:
                            if x == y["datosEquipo"]["ci"]:
                                dict_fallas["datos"].append(n)
                                dict_fallas["datos"][n] = y
                                n += 1
                            else:
                                pass
                    print(dict_fallas)
                    respuesta_dnos = constructor_json_y_consulta_dnos(dict_fallas)
                    mutex_block.acquire()
                    q_block[str(num_queue_unique)] = 0
                    mutex_block.release()
            else:
                pass
        else:
            pass

def daemon_sensors():

    """
    Método que crea y lanza Threads como demonios, encargados de sensar las colas.

    Args:
        None

    Returns:
        None
    """

    Hilos = [Hilos for Hilos in range(0, 2)]

    for i in Hilos:
        Hilos[i] = threading.Thread(target=ejecucion_de_PS, args=(i,))
        Hilos[i].daemon = True
        Hilos[i].start()

daemon_sensors()

@app.route('/queues/nas', methods = ['POST'])
def encolador_principal():

    """
    Método principal que recibe y encola los request hechos al NAS.

    Args:
        None.
    
    Returns:
        Respuesta de encolamiento completado.
    """

    global q_sensores

    q_prin = referencia_cola()
    #print(request.json) # serializado

    json_request = json.loads(request.json)

    if json_request['datos'][0]['datosEquipo']['nombreAccion']:
        
        #q_prin.put( request.json )
        q_prin.put(json_request)
        get_queue_prin = q_prin.get()

        q_individual = persistqueue.SQLiteQueue(directory+'Queues_app/'+
                get_queue_prin['datos'][0]['datosEquipo']['host'].replace(
                                                    '-','_'), auto_commit=True)
        q_individual.put(get_queue_prin)

        q_sensores.put(json_request['datos'][0]['datosEquipo']['ci'])
        
        response = 'PSCOMPLETE'
        print(f"Peticion: {json_request['datos'][0]['datosEquipo']['host']} atendida")
    else:
        #response = consulta_dnos_directa(json_request)
        #print ("null action detected...")
        response = ""

    return response

if __name__ == '__main__':
    app.run(host="localhost",port="5000",debug=True)
