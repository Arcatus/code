n = int(input())
matriz = [[0 for x in range(n)] for y in range(n) ]
col = 0
cnt = 1
for i in range(n):
    matriz[i][col] = cnt
    cnt+=1
    col+=1
col = n-1
for i in range(n):
    if matriz[i][col] == 0:
        matriz[i][col] = cnt
        cnt+=1
    col-=1
print("Matriz X:")
for i in range(n):
    for j in range(n):
        print(matriz[i][j],end=' ')
    print()
print("La matriz X invertida es:")
for i in range(n):
    for j in range(n-1,-1,-1):
        print(matriz[i][j],end=' ')
    print()