# -*- coding: utf-8 -*-

__author__ = 'Jair Paredes, Arturo Herrera, Arturo Sánchez'
__copyright__ = 'Copyright 2019, UniNet'
__version__ = '2.0.0'
__email__ = 'jparedes@reduno.com.mx, arturohv@reduno.com.mx,' \
                                                    'arturosm@reduno.com.mx'
__status__ = 'Production'


from flask import Flask, request, jsonify
from collections import namedtuple
from flask_cors import CORS
from test.support import resource
from utilidades.concurrency import Concurrency
from utilidades.padlock import PadLock
from utilidades.log import Log
import json


app = Flask(__name__)
cors = CORS(app, resource={r"/api/*": {"origins": "*"}})

"""
    Éste codigo ilustra la manera en la que se genera la API en python que
    escucha peticiones REST.
    """


@app.route('/api/nas', methods=['POST'])
def nas():
    """
        Metodo en donde se define la ruta a la cual en FrontEnd envía las
        peticiones REST.

        Args:
            :param arg1: URL
            :param arg2: Default es POST.

        Returns:
            JSON que indica si la solicitud fue
            exitosa u ocurrio algún error.

         .. note::
            Los logs asociados al comportamiento de la funcion son depositados
            en la ruta script/nas_log/ProgramaLog.log.
            El nivel de severidaddefinido es INFO.
    """
    try:
        #se genera la instancia en donde se depositan los logs, dado que el
        #nivel de
        naslog = Log()
        loggerMain = naslog.setup_logger("logProg",
                                             "/script/nas_log/ProgramaLog.log")
        loggerMain.debug("INICIO::NAS::nas")
        print("INICIO::NAS::nas")

        reply_message = {}

        json_front_end = request.get_json()
        json_front_end_str = json.dumps(json_front_end)

        loggerMain.debug("JSON recibido %s" % (json_front_end_str))

        #el JSON es transformado a un objeto
        objeto_json = json.loads(json_front_end_str, object_hook=lambda d:
                    namedtuple('json', list(d.keys()))(*list(d.values())))

        #Se instancia el objeto que realiza la validacionde tareas duplicadas
        validacion = PadLock()
        message = validacion.valida_accion_repetida(objeto_json)

        #Instanciamos el objeto concurrencia y le pasamos la lista de
        #objetos routers los objetos Routers contienen las tareas que
        #se van a realizar.
        if validacion.devices_to_execute and \
                                    len(validacion.devices_to_execute) <= 20:
            worker = Concurrency(validacion.devices_to_execute)
            threads_response = worker.make_threads()

            #Agrega la respuesta de los modulos al json
            reply_message.update(threads_response)

            if message:
                reply_message.update(message)

            objeto_json = None

            print("FIN::NAS::nas")
            loggerMain.debug("FIN::NAS::nas")

            return jsonify(reply_message)

        else:
            reply_message["Error"] = "Cantidad de equipos nulo o mayor " + \
                                                            " a lo esperado\n"
            reply_message.update(message)

            print("FIN::Cantidad de equipos nulo mayor a lo esperado\n")

            loggerMain.debug("FIN::Cantidad de equipos nulo mayor a lo " +
                                                               "esperado\n")
                                                               
            return jsonify(reply_message), 400

        #libera espacio en memoria del objeto
        objeto_json = None

    except Exception as e:
        if naslog:
            loggerMain.error("%s" % (str(e)))
        else:
            print("log no existe")

        reply_message["Error"] = "%s" % (str(e))

        return jsonify(reply_message), 400


#app.run(host='10.94.5.111', debug=False)
app.run(host='172.17.0.2', debug=True)
