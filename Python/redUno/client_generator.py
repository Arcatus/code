# -*- coding: utf-8 -*-

__author__ = 'Josué Cirilo Cruz'
__copyright__ = 'Copyright 2019, UniNet'
__version__ = '1.0.0'
__email__ = 'jcirilo@reduno.com.mx'
__status__ = 'Production'

#Permite manejar las variables que seran recibidos por los metodos post y get
import requests

#Necesario para serializar y deserializar
import json

#Utilidades de python
from collections import namedtuple
import random, time

n = 0
null = None
#while True:
for x in range(1):
    n  = n + 1
    PS = 'PS'+str(n)
    
    #Generamos un numero aleatorio entre 0-3 con diferencias de 1
    temp = random.randrange(0,3,1)

    #Creamos la lista de los equipos
    equipo = [  "ipdsl-nvl-santafe-23-prov",
                "ipdsl-ags-vinedo-14-prov", 
                "ipdsl-cam-campeche-12", 
                "ipdsl-hgo-tula-3"]

    #Creamos un diccionario de listas de python
    bras_json = {
    "datos": [
        {
            "datosEquipo": {
                "ci": "c777",
                "ip": "201.154.0.11",
                "host": "inet-mex-nextengo-154",
                "proveedor": "Cisco",
                "modelo": "M-GSR10/200",
                "version": "IOS XR 4.3.2[Default]",
                "servicio": "IDE",
                "historico": 2,
                "idAccion": 62,
                "nombreAccion": "Asociación PM a la interface",
                #"nombreAccion": "",
                "usuarioActualizacion": "JAIR_PUTON_MARICON"
            },
            "metodos": [
                {
                    "idMetodo": 54,
                    "nombreMetodo": "modulos.configure_device,ConfigureDevice,configuration",
                    "flujos": [
                        {
                            "idFlujo": 70,
                            "nombreFlujo": "Asociación SP  a la interface - CLI",
                            "comandos": [
                                {
                                    "idComando": 118,
                                    "proveedor": null,
                                    "comando": "interface GigabitEthernet0/1/0/9.140",
                                    "nombreComando": null,
                                    "descripcion": "Nombre de la subinterface",
                                    "tipoComando": {
                                        "idCatalogoNivelUno": 4,
                                        "nombreCatalogoNivelUno": "Configuración",
                                        "valor": null,
                                        "estado": null,
                                        "ayuda": null,
                                        "orden": null,
                                        "usuarioActualizacion": null,
                                        "fechaActualizacion": null
                                    },
                                    "cambioVariable": {
                                        "idCatalogoNivelUno": 0,
                                        "nombreCatalogoNivelUno": "sinCambio",
                                        "valor": null,
                                        "estado": null,
                                        "ayuda": null,
                                        "orden": null,
                                        "usuarioActualizacion": null,
                                        "fechaActualizacion": null
                                    },
                                    "estado": null,
                                    "segundos": null,
                                    "usuarioActualizacion": null,
                                    "fechaActualizacion": null,
                                    "orden": 1,
                                    "validaciones": []
                                },
                                {
                                    "idComando": 119,
                                    "proveedor": null,
                                    "comando": "bandwidth 50000",
                                    "nombreComando": null,
                                    "descripcion": "Ancho de Banda",
                                    "tipoComando": {
                                        "idCatalogoNivelUno": 4,
                                        "nombreCatalogoNivelUno": "Configuración",
                                        "valor": null,
                                        "estado": null,
                                        "ayuda": null,
                                        "orden": null,
                                        "usuarioActualizacion": null,
                                        "fechaActualizacion": null
                                    },
                                    "cambioVariable": {
                                        "idCatalogoNivelUno": 0,
                                        "nombreCatalogoNivelUno": "sinCambio",
                                        "valor": null,
                                        "estado": null,
                                        "ayuda": null,
                                        "orden": null,
                                        "usuarioActualizacion": null,
                                        "fechaActualizacion": null
                                    },
                                    "estado": null,
                                    "segundos": null,
                                    "usuarioActualizacion": null,
                                    "fechaActualizacion": null,
                                    "orden": 2,
                                    "validaciones": []
                                },
                                {
                                    "idComando": 120,
                                    "proveedor": null,
                                    "comando": "service-policy input PRUEBA_TELNET_NAS_In",
                                    "nombreComando": null,
                                    "descripcion": "Asociación de service-policy IN",
                                    "tipoComando": {
                                        "idCatalogoNivelUno": 4,
                                        "nombreCatalogoNivelUno": "Configuración",
                                        "valor": null,
                                        "estado": null,
                                        "ayuda": null,
                                        "orden": null,
                                        "usuarioActualizacion": null,
                                        "fechaActualizacion": null
                                    },
                                    "cambioVariable": {
                                        "idCatalogoNivelUno": 0,
                                        "nombreCatalogoNivelUno": "sinCambio",
                                        "valor": null,
                                        "estado": null,
                                        "ayuda": null,
                                        "orden": null,
                                        "usuarioActualizacion": null,
                                        "fechaActualizacion": null
                                    },
                                    "estado": null,
                                    "segundos": null,
                                    "usuarioActualizacion": null,
                                    "fechaActualizacion": null,
                                    "orden": 3,
                                    "validaciones": []
                                },
                                {
                                    "idComando": 121,
                                    "proveedor": null,
                                    "comando": "service-policy output PRUEBA_TELNET_NAS_Out",
                                    "nombreComando": null,
                                    "descripcion": "Asociación de service-policy OUT",
                                    "tipoComando": {
                                        "idCatalogoNivelUno": 4,
                                        "nombreCatalogoNivelUno": "Configuración",
                                        "valor": null,
                                        "estado": null,
                                        "ayuda": null,
                                        "orden": null,
                                        "usuarioActualizacion": null,
                                        "fechaActualizacion": null
                                    },
                                    "cambioVariable": {
                                        "idCatalogoNivelUno": 0,
                                        "nombreCatalogoNivelUno": "sinCambio",
                                        "valor": null,
                                        "estado": null,
                                        "ayuda": null,
                                        "orden": null,
                                        "usuarioActualizacion": null,
                                        "fechaActualizacion": null
                                    },
                                    "estado": null,
                                    "segundos": null,
                                    "usuarioActualizacion": null,
                                    "fechaActualizacion": null,
                                    "orden": 4,
                                    "validaciones": []
                                }
                            ]
                        }
                    ]
                }
            ]
        }
    ]
}

#Pasamos de diccionario a string
#print (f"type of bras_json {type( bras_json )} \n\n")
    
request_json_bras = json.dumps(bras_json,indent=4)

#print (f"type of request_json_bras {type( request_json_bras )} \n\n")
print(request_json_bras)

#json.loads() parsea la string json encoded a objeto python
#objeto_json = json.loads(request_json_bras, object_hook \
    #= lambda d : namedtuple('json', list( d.keys()))(*list(d.values())))
    #= lambda d : print( *list( d.keys() ) ))

#objeto_json = json.loads(request_json_bras, object_hook \
    #= lambda d : namedtuple('json', list( d.keys())) (*list(d.values())))

#JSON string serialized to python dict (Deserialize)
diccionario_json=json.loads(request_json_bras)

#serializing json
serialized_json=json.dumps(bras_json)


print (f"type of objeto_json{type( serialized_json )} atributes { dir( serialized_json ) } \n\n")

r=requests.post('http://localhost:5000/queues/nas', json=serialized_json)

time.sleep(2)

print(r)