t = int(input())
for test in range(t):
    n = int(input())
    s = input()

    cnt = 0
    if s[0] == '1':
        cnt += 1
    for i in range(1, n):
        if s[i] == '0':
            print('+', end="")
        else:
            cnt += 1
            if cnt % 2:
                print('+', end="")
            else:
                print('-', end="")
    print()