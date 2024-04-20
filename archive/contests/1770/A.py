t = int(input())
for _ in range(t):
    n, m = map(int, input().split())
    a = list(map(int, input().split()))
    b = list(map(int, input().split()))
    a.extend(b)
    ans = a[:n+m-1]
    ans.sort()
    ans.append(a[n + m - 1])
    ans.reverse()
    print(sum(ans[:n]))
