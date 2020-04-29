
class Coche():
    largoChasis = 250
    anchoChasis = 120
    ruedas = 4
    enmarcha = False  
    
    def arrancar(self):
        self.enmarcha = True
    
    def estado(self):
        if self.enmarcha:
            return "En marcha"
        else:
            return "Detenido"

micoche = Coche()

print( micoche.estado() )

micoche.arrancar()

print( micoche.estado() )