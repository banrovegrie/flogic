from collections import defaultdict
tests = int(input())
for test in range(tests):
    n, m = map(int, input().split())
    a = list(map(int, input().split()))
    d = defaultdict(int)
    friends = []
    pairs = defaultdict(int)

    for _ in range(m):
        x, y = map(int, input().split())
        d[x] += 1
        d[y] += 1
        friends.append((x, y))
        pairs[(x, y)] = 1
        pairs[(y, x)] = 1
    friends.sort()

    if m == 
    for i in range(n):
        