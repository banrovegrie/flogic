from itertools import accumulate
from math import inf

n, l, r = map(int, input().split())
a = list(map(int, input().split()))


def calc(a, x):
    f = [0] * (n + 1)
    for i in range(n):
        f[i + 1] = min(x * (i + 1), f[i] + a[i])
    return f


f = calc(a, l)
g = calc(a[::-1], r)[::-1]

ans = inf
for i in range(n + 1):
    ans = min(ans, f[i] + g[i])

print(ans)
