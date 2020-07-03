s = input()
while(True):
    try:
        v = int(input())
        if 1 <= v and v <= 25:
            break
        else:
            raise ValueError
    except:
        print("Ingresa un valor valido entre 1-25")

alf  = "abcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyz"
alfM = "abcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyz"
alfM = alfM.upper()
for i in s:
    if i.islower():
        ind = alf.find(i)
        print(alf[ind+v],end="")
    elif i.isupper():
        ind = alfM.find(i)
        print(alfM[ind+v],end="")
    else:
        print(i,end="")