import math
k, p, x = map(int, input().split())
n1 = math.floor(math.sqrt(k * p / x))
n2 = math.ceil(math.sqrt(k * p / x))
ans = min(x * n1 + k * p / n1, x * n2 + k * p / n2)
print ('%.3f'%ans)