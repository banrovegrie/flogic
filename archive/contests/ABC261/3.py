from collections import defaultdict
n = int(input())
d = defaultdict(int)

for _ in range(n):
    s = input()
    if d[s] == 0:
        print(s)
    else:
        print(f"{s}({d[s]})")
    d[s] += 1
