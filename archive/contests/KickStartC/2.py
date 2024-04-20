T = int(input())
for t in range(1, T + 1):
    n, x, y = map(int, input().split())
    if (n * (n + 1) / 2) % (x + y) == 0:
        print(f"Case #{t}: POSSIBLE")
        x = x * n * (n + 1) / (2 * (x + y))

        arr = []
        sz = 0
        while x > 0:
            if x < n:
                arr.append(x)
                sz += 1
                break
            else:
                arr.append(n)
                x -= n
                sz += 1
                n -= 1
        print(sz)
        for i in arr:
            print(int(i), end=" ")
        print()
    else:
        print(f"Case #{t}: IMPOSSIBLE")