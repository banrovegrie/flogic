n = int(input())
a = list(map(int, input().split()))


dp = [0] * n
for i in range(n):
    if i > 0:
        dp[i] = dp[i - 1] + abs(a[i] - a[i - 1])
    if i - 1 > 0:
        dp[i] = min(dp[i], dp[i - 2] + abs(a[i] - a[i - 2]))

print(dp[n - 1])
