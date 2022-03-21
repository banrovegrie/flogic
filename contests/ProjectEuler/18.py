def func(i, j, triangle):
    if i >= len(triangle) or j >= len(triangle[i]):
        return 0
    if f[i][j] != -1:
        return f[i][j]
    f[i][j] = (
        max(func(i + 1, j, triangle), func(i + 1, j + 1, triangle)) + triangle[i][j]
    )
    return f[i][j]


triangle = []
f = []
for i in range(0, 100):
    triangle.append(list(map(int, input().split())))
    f.append([-1 for _ in triangle[i]])
# print(triangle)
# print(f)

print(func(0, 0, triangle))
