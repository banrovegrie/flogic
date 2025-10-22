r = [0 for i in range(11)]
b = [0 for i in range(11)]
l = len(r)

n, x, y = map(int, input().split())
r[n] = 1

while True:
    flag = True
    for i in range(2, l):
        if r[i] > 0:
            r[i - 1] += r[i]
            b[i] += x * r[i]
            r[i] = 0
            flag = False            
        if b[i] > 0:
            r[i - 1] += b[i]
            b[i - 1] += y * b[i]
            b[i] = 0
            flag = False
    # print(f"r = {r}\n b = {b}\n")
    if flag:
        break
print(b[1])