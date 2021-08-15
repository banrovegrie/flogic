n, k = map(int, input().split())
a = list(map(int, input().split()))
INF = int(1e18 + 7)

dp = [0] * n
for i in range(n):
    dp[i] = INF
    for j in range(1, k + 1):
        if i - j >= 0:
            dp[i] = min(dp[i], dp[i - j] + abs(a[i] - a[i - j]))
    if dp[i] == INF:
        dp[i] = 0

print(dp[n - 1])
