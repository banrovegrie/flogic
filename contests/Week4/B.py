import math

n, s1, s2 = map(int, input().split())
ans = [[math.inf] * (1001) for _ in range(s1)]
ans[0][0] = 0
suff = [[math.inf] * (1001) for _ in range(n + 1)]
suff[n][0] = 0

data = [list(map(int, input().split())) for _ in range(n)]
x, t, y, r = zip(*data)
v = sorted(range(n), key=lambda i: x[i])

for i in range(n - 1, -1, -1):
    for j in range(1001):
        if suff[i + 1][j] != math.inf:
            suff[i][j] = min(suff[i][j], suff[i + 1][j])
            if y[v[i]] + j <= 1000:
                suff[i][y[v[i]] +
                        j] = min(suff[i][y[v[i]] + j], suff[i + 1][j] + r[v[i]])

for i in range(n + 1):
    for j in range(1000, 0, -1):
        suff[i][j - 1] = min(suff[i][j - 1], suff[i][j])

min_minutes = math.inf
for i in range(n):
    dp = [[math.inf] * (1001) for _ in range(s1)]
    for j in range(s1):
        for k in range(1001):
            if ans[j][k] != math.inf:
                if x[v[i]] + j >= s1:
                    min_minutes = min(
                        min_minutes, ans[j][k] + t[v[i]] + suff[i + 1][max(0, s1 + s2 - (x[v[i]] + j) - k)])
                if x[v[i]] + j < s1:
                    dp[x[v[i]] + j][k] = min(dp[x[v[i]] + j]
                                             [k], ans[j][k] + t[v[i]])
                if y[v[i]] + k <= 1000:
                    dp[j][y[v[i]] + k] = min(dp[j]
                                             [y[v[i]] + k], ans[j][k] + r[v[i]])
    ans = [[min(ans[j][k], dp[j][k]) for k in range(1001)]
           for j in range(s1)]

print(-1 if min_minutes == math.inf else min_minutes)
