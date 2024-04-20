l1, r1, l2, r2 = map(int, input().split())
if l1 <= l2:
    print(max(0, min(r1, r2) - l2))
else:
    print(max(0, min(r2, r1) - l1))