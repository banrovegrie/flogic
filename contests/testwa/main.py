n = 2
A = [i + 1 for i in range(2**n)]

N = len(A)
F = [0 for i in range(2**N)]

for mask in range(0, len(F)):
    for i in range(0, len(A)):
        print(bin(mask), bin(1 << i), ((mask & (1 << i)) != 0))
        F[mask] += A[i] * ((mask & (1 << i)) != 0)

print(sum(F))