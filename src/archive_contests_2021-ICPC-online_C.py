t = int(input())
for test in range(t):
    n, x = map(int, input().split())
    s = input()
    arr = []
    
    ans = 0
    sol = 0
    
    for i in s:
        if i == "1":
            sol += 1
            if ans > 0:
                arr.append(ans)
            ans = 0
        else:
            ans += 1
    if ans > 0:
        arr.append(ans)
    arr.sort()

    arr = arr[::-1]
    for i in arr:
        if x <= 0:
            break
        if 2 * i + 1 > x:
            sol += max(0, (x - 1) // 2)
            break
        else:
            sol += i
            x -= (2 * i + 1)
    print(sol)