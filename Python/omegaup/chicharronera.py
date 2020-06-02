import math
a, b, c = map(int, input().split())
x = (- b + math.sqrt( (b*b) - (4*a*c) ) ) / (2*a)
y = (- b - math.sqrt( (b*b) - (4*a*c) ) ) / (2*a)
print(f"{x} {y}")