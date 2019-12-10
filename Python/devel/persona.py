
class Persona:
    def __init__(self, nombre, edad):
        self.nombre = nombre
        self.edad = edad
    
    def imprimir(self):
        print("Nombre:", self.nombre)
        print("edad:", self.edad)