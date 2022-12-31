t = int(input())
for tests in range(t):
    n = int(input())
    mod = (10 ** 9 + 7)
    res = (2 * n * (n + 1) * (2 * n + 1) // 6) % mod + (n * (n + 1) // 2) % mod 
    res = (res - n * (n + 1)) % mod
    res = (2022 * res) % mod
    print(res)