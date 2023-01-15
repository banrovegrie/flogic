t = int(input())
for _ in range(t):
    x = int(input())
    v = list(map(int, input().split()))
    if v[0] == 1 or v[1] == 2 or v[2] == 3 or v[x - 1] == 0:
        print("NO")
    else: 
        print("YES")