import numpy as np

t = int(input())

for test in range(1, t + 1):
    n, m = map(int, input().split())
    a = list(map(int, input().split()))
    a.sort()
    a.reverse()
    # print(a)

    sum = 0.0
    for i in range(m - 1):
        sum += a[i]
    a = a[m - 1:]
    # print(a)
    sum += np.median(np.array(a))
    print(f"Case #{test}: {sum}")
