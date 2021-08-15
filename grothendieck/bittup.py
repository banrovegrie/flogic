T = int(input())
mod = int(1e9 + 7)

for t in range(T):
    a = list(map(int, input().split()))
    print(pow(((pow(2, a[0], mod) + mod - 1)) % mod, a[1], mod) % mod)
