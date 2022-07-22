n, m = map(int, input().split())
h = list(map(int, input().split()))

p = [0] * (n)
q = [0] * (n)

for i in range(1, n):
    if h[i] < h[i - 1]:
        p[i] = p[i - 1] + abs(h[i] - h[i - 1])
    else:
        p[i] = p[i - 1]
# print(p)

for i in range(n - 2, -1, -1):
    if h[i] < h[i + 1]:
        q[i] = q[i + 1] + abs(h[i] - h[i + 1])
    else:
        q[i] = q[i + 1]
# print(q)

for _ in range(m):
    s, t = map(int, input().split())
    s -= 1
    t -= 1
    if t >= s:
        print(p[t] - p[s])
    else:
        print(q[t] - q[s])