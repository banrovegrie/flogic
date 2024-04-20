t = int(input())
while t > 0:
    t -= 1
    n = int(input())
    for i in range(n, 3, -1):
        print(i, end=" ")
    if n % 2 == 0:
        print("1 3 2")
    else:
        print("3 2 1")    