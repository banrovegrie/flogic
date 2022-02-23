t = int(input())

while t:
    t -= 1
    st = input()
    r = 0
    g = 0
    b = 0
    s = 0
    for ch in st:
        if ch == 'r': r = 1
        if ch == 'g': g = 1
        if ch == 'b': b = 1

        if (ch == 'R' and r == 0) or (ch == 'G' and g == 0) or (ch == 'B' and b == 0):
            print("NO")
            s = 1
            break
    
    if s == 0:
        print("YES")
