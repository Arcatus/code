archivo = open('getnode_file', 'r')
linea = archivo.readlines()
archivo.close()
dict1 = {}
cont = 1

for x in linea:
    temp = x.split('\r')
    for y in temp:
        dict1[cont] = y.split(' ')[0]
        cont += 1

print(dict1)
