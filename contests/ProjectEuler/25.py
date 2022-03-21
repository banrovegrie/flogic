f = [1] * 10005
f[1] = 1
f[2] = 1
f[3] = 2
for i in range(4, 5005):
    f[i] = f[i - 1] + f[i - 2]
    if (len(str(f[i]))) >= 1000:
        print(i)
        break
