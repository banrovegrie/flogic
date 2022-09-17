n = int(input())
mod = 998244353

f = [1 for i in range(500**2 + 5)]
inv = [1 for i in range(500**2 + 5)]
for i in range(1, 500**2 + 5):
    f[i] = (f[i - 1] * i) % mod
inv[n * n] = pow(f[n * n], mod - 2, mod)
for i in range(n**2, -1, -1):
    inv[i - 1] = (inv[i] * i) % mod

ans = (
    n
    * n
    * f[n * n]
    % mod
    * inv[n * n - 2 * n + 1]
    % mod
    * inv[2 * n - 1]
    % mod
    * f[n - 1]
    % mod
    * f[n - 1]
    % mod
    * f[n * n - 2 * n + 1]
    % mod
)
ans = (f[n * n] - ans + mod) % mod
print(ans)
