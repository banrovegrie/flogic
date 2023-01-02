from random import randint
k = 0
print(1)
print(9)
a = []
while True:
    if k == 25:
        break
    x = randint(1, 500)
    if x % 2 and x not in a:
        k += 1
        print(x, end=" ")
        a.append(x)
print()