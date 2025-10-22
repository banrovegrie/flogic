a  = list(map(int, input().split()))
a.sort()

if (a[0] == a[1] == a[2] and a[3] == a[4] and a[2] != a[3]):
    print('Yes')
elif (a[0] == a[1] and a[2] == a[3] == a[4] and a[1] != a[4]):
    print('Yes')
else:
    print('No')