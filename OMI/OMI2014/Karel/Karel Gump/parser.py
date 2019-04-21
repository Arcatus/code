import sys
from xml.dom import minidom
mundo = minidom.parse(sys.argv[1])

inicio = mundo.getElementsByTagName('programa')
x_karel = int(inicio[0].attributes['xKarel'].value)
y_karel = int(inicio[0].attributes['yKarel'].value)
d_karel = inicio[0].attributes['direccionKarel'].value

max_x, max_y = 0, 0
min_x, min_y = 100, 100

paredes = mundo.getElementsByTagName('pared')
for pared in paredes:
	if pared.attributes.getNamedItem('x2') != None:
		max_x = max(int(pared.attributes['x1'].value), max_x)
		max_x = max(int(pared.attributes['x2'].value), max_x)
		max_y = max(int(pared.attributes['y1'].value), max_y)
		min_x = min(int(pared.attributes['x1'].value), min_x)
		min_x = min(int(pared.attributes['x2'].value), min_x)
		min_y = min(int(pared.attributes['y1'].value), min_y)
		
	if pared.attributes.getNamedItem('y2') != None:
		max_x = max(int(pared.attributes['x1'].value), max_x)
		max_y = max(int(pared.attributes['y1'].value), max_y)
		max_y = max(int(pared.attributes['y2'].value), max_y)
		min_x = min(int(pared.attributes['x1'].value), min_x)
		min_y = min(int(pared.attributes['y1'].value), min_y)
		min_y = min(int(pared.attributes['y2'].value), min_y)
		
n = max_y - min_y
m = max_x - min_x

x_karel -= min_x
y_karel -= min_y

dir_karel = {
	'NORTE': 0,
	'OESTE': 1,
	'SUR'  : 2,
	'ESTE' : 3
}.get(d_karel)

matriz = []
for i in range(n):
	matriz.append([])
	for j in range(m):
		matriz[i].append(0)

montones = mundo.getElementsByTagName('monton')
for monton in montones:
	x = int(monton.attributes['x'].value) - min_x
	y = int(monton.attributes['y'].value) - min_y
	if x <= 0 or y <= 0 or x > m or y > n: continue
	matriz[y - 1][x - 1] = 1

print('%d %d %d %d %d' % (n, m, y_karel, x_karel, dir_karel))
for i in range(n):
	line = str(matriz[i][0])
	for j in range(1, m):
		line += ' %d' % matriz[i][j]
	print(line)
