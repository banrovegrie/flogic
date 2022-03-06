import bisect
t = int(input())

a = [0 for i in range(16)]
a[0] = 1
for i in range(1, 16):
    a[i] = i * a[i - 1]

s = []
for i in range(2 ** 12):
    s.append(format(i, '#010b')[2:])

ss = []
for c in s:
    sum = 0
    times = 0
    c = c[::-1]
    for i in range(0, len(c)):
        if c[i] == '1':
           sum += a[i + 3]
           times += 1
    ss.append((sum, times))
# print(ss[:5])

def countSetBits(num):
    count = 0
    while (num):
        count += num & 1
        num >>= 1
    return count

while t > 0:
    t -= 1
    n = int(input())
    N = n  

    mn = 66
    for x, y in ss:
        if (n >= x):
            # print("hi", x)
            mn = min(mn, countSetBits(n - x) + y)
    if mn == 66:
        print(-1)
    else:
        print(mn)