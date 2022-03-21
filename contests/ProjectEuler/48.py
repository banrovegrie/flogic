sum = 0
mod = 10 ** 10
for i in range(1, 1001):
    sum += (i ** i) % (mod)
    sum %= mod
print(sum)