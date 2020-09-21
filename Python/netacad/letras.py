nombre = input("Dame el nombre del archivo\n")
file = open(nombre, "rt")
ch = file.read(1)
h = [0]*26
while ch != '' and ch != '\n':
    ch = ch.lower()
    h[ord(ch) - ord('a')] += 1
    ch = file.read(1)
for i in range(len(h)):
    if h[i] > 0:
        print( chr(i + ord('a'))," -> ",h[i],sep=' ')
file.close()
