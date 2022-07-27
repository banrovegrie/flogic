n, m = map(int, input().split())
x = list(map(int, input().split()))
y = [0] * (n + 1)
for i in range(m):
    c, val = map(int, input().split())
    y[c] = val

f = [[0] * (n + 1) for _ in range(n + 1)]

f[0][1] = x[0] + y[1]
for i in range(0, n - 1):
    for j in range(0, i + 2):
        f[i + 1][0] = max(f[i + 1][0], f[i][j])
        f[i + 1][j + 1] = f[i][j] + x[i + 1] + y[j + 1]

print(max(f[n - 1]))
