t = int(input())

while t > 0:
    t -= 1
    n = int(input())
    
    for i in range(1, n - 1):
        print(i, end=" ")
    print(n * (n - 1) / 2)

    arr = list(map(int, input().split()))
    arr = sorted(arr)