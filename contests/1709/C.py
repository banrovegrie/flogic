from copy import deepcopy


t = int(input())
for _ in range(t):
    s = input()
    s = list(s)

    o = s.count("(")
    c = s.count(")")
    f = s.count("?")

    t = deepcopy(s)
    t[0] = "("
    t[-1] = ")"
    for i in range(1, len(s) - 1):
        if s[i] == "?":
            if o > c:
                t[i] = ")"
                o -= 1
            else:
                t[i] = "("
                c -= 1

    o = s.count("(")
    c = s.count(")")
    f = s.count("?")
    l = deepcopy(s)
    l[0] = "("
    l[-1] = ")"
    for i in range(1, len(s) - 1):
        if s[i] == "?":
            if o < c:
                l[i] = "("
                c -= 1
            else:
                l[i] = ")"
                o -= 1

    if "".join(l) == "".join(t):
        print("YES")
    else:
        print("NO")
