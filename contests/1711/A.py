tests = int(input())
for test in range(tests):
    n = int(input())
    print(n, end=" ")
    for i in range(2, n + 1):
        print((i - 1), end=" ")
    print()