milista = [int(i) for i in input().split()]
ans = 0
for i in milista:
    ans += i
print(ans//len(milista))