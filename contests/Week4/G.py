n, m, h = map(int, input().split())
projection_front = [[int(c == '1') for c in input()] for _ in range(n)]
projection_left = [[int(c == '1') for c in input()] for _ in range(n)]

mx = []
mn = []

for i in range(n):
    front_sum = sum(projection_front[i])
    left_sum = sum(projection_left[i])

    if (front_sum == 0 and left_sum != 0) or (left_sum == 0 and front_sum != 0):
        print(-1)
        exit(0)

    x = [j for j, val in enumerate(projection_front[i]) if val]
    y = [k for k, val in enumerate(projection_left[i]) if val]

    mx.extend([(i, j, k) for j in x for k in y])

    j, k = len(x) - 1, len(y) - 1
    while j >= 0 or k >= 0:
        mn.append((i, x[j], y[k]))
        j, k = j - 1, k - 1
        if j < 0 and k < 0:
            break
        j, k = max(0, j), max(0, k)

mx.sort()
print(len(mx))
for i, j, k in mx:
    print(i, j, k)

mn.sort()
print(len(mn))
for i, j, k in mn:
    print(i, j, k)
