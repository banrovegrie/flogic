T = int(input())
for t in range(1, T + 1):
    n = int(input())
    s = input()

    upper = 0
    lower = 0
    digit = 0
    sc = 0
    for c in s:
        if c.islower():
            lower += 1
        elif c.isupper():
            upper += 1
        elif c.isdigit():
            digit += 1
        else:
            sc += 1

    if upper == 0:
        s += 'A'
    if lower == 0:
        s += 'a'
    if digit == 0:
        s += '1'
    if sc == 0:
        s += '*'
    
    for i in range(len(s), 7):
        s += '1'
    print(f"Case #{t}: {s}")