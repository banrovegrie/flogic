t = int(input())
for _ in range(t):
    n, k = map(int, input().split())
    a = [i + 1 for i in range(n)]
    ans = []
    x =  1
    for i in range(n):
        if i % 2 == 0:
            ans.append(a[n - x])
            x += 1
        else:
            ans.append(a[x - 2])
    [print(i, end=" ") for i in ans]
    print()