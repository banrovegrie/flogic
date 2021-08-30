n = int(input())
l = []

for i in range(n):
    l.append(input())
l = sorted(l)

for x in range(n - 1):
    if l[x] == l[x + 1]:
        print("Yes")
        break
else:
    print("No")
