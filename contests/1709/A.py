tests = int(input())
for test in range(tests):
    flag = True
    x = int(input())
    val = list(map(int, input().split()))
    for i in range(len(val)):
        if val[i] == 0 and x == i + 1:
            flag  = False
            break
        elif val[i] == i + 1:
            flag = False
            break 
    if  flag:
        print("YES")
    else:
        print("NO")