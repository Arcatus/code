def readint(prompt, min, max):
    while(True):
        num = input(prompt)
        try:
            a = int(num)
            if min <= a and a <= max:
                return a                
            else:
                print("Error: el valor no está dentro del rango permitido (-10..10)")
        except ValueError:            
            print("Error entrada Incorrecta")

v = readint("Ingresa un numero de -10 a 10: ", -10, 10)

print("El numero es:", v)