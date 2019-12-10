import requests
import json

def update_ci_queus():
    peticion_json, db_dict = {}, {}

    respuesta_nas = requests.post('http://10.108.198.6:8081/consultarRoutersSM', 
                                                            json = peticion_json)

    for element in respuesta_nas.json()['datos']: 
        db_dict[element['ciRouter']] = element['hostname']

    with open('dbCI.json', 'w') as json_file:
        json.dump(db_dict, json_file)

update_ci_queus()