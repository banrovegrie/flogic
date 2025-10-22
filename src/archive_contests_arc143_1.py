a = list(map(int, input().split()))
a.sort()

x = a[2]
if x >= (x - a[0]) + (x - a[1]) + (x - a[2]):
    print(a[2])
else:
    print(-1)