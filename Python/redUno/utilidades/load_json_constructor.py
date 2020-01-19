import json

def load_json_constructor(file_json):
    with open(file_json) as json_variable:
        data = json.loads(json_variable.read())
    return data