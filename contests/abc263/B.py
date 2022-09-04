n = int(input())
p = list(map(int, input().split()))

i = n - 2
count = 1
while p[i] != 1:
    p[i] = p[p[i] - 2]
    count += 1
print(count)
