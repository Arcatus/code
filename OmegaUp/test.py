
n = 0
r = 0
k = 0
n, r, k = map(int, input().split())
a = list(map(int, input().split()))
defensa = [None] * n
defensa[0] = 0
for i in range(0, min(n - 1, r) + 1):
    defensa[0] += a[i]

for i in range(1, n):
    defensa[i] = defensa[i - 1]
    if(i + r < n):
        defensa[i] += a[i + r]
    if(i - r - 1 >= 0):
        defensa[i] -= a[i - r - 1]

# for i in defensa:
#     print(i,end=" ")
# print()

min_global = min(defensa)
lo = min_global
hi = 10000000000000000000
b = [None]*n
while(lo < hi):
    mid = (hi + lo)//2 + 1
    print(lo, mid, hi)
    kt = k
    ok = True
    if(2*r + 1 >= n):
        if(min_global + k < mid):
            ok = False
    else:
        b = defensa.copy()
        for i in range(0, n):
            if(b[i] < mid):
                diff = mid - b[i]
                if(kt >= diff):
                    kt -= diff
                    for j in range(i, min(n, i + 2*r + 1)):
                        b[j] += diff
                else:
                    ok = False
                    break
    if(ok):
        lo = mid
    else:
        hi = mid - 1

print(lo)