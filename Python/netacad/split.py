def misplit(strng):
    lista = []
    st = ""
    pos = 0
    while pos < len(strng):
        if strng[pos]!=' ' and strng[pos]!='\t':
            st+=strng[pos]
        else:
            if len(st) > 0:
                lista.append(st)
            st = ""
        pos += 1

    if len(st) > 0 :
         lista.append(st)
    return lista


print(misplit("Ser o no ser, esa es la pregunta"))
print(misplit("Ser o no ser,esa es la pregunta"))
print(misplit("   "))
print(misplit(" abc "))
print(misplit(""))