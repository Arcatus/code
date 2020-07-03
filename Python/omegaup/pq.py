from sys import stdin

for line in stdin:
    a = line    
    a = a.split(" ")
    p = int(a[0])
    q = int(a[1])

    x = ( (p-2)*(p**2) + (q**4) )
    if x < 680 :
        print(f"{p} , {q}")
    else:
        print()