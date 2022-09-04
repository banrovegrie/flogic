n, m = map(int, input().split())


def f(i, path):
    x = path[-1]
    if i >= n:
        print(" ".join(map(str, path)))
        return
    elif x == m:
        return

    # print(x, end=" ")
    for y in range(x + 1, m + 1):
        # if i + 1 <= n:
        f(i + 1, path + [y])
    # print("meow")
    # f(i, x)


[f(1, [x]) for x in range(1, m + 1)]
