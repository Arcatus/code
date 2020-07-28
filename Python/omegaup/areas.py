a = int(input())
ans = 0
for _ in range (a):
     b, c = map(int, input().split())
     ans += b*c
print(ans)
