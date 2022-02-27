# import itertools
import string

T = int(input())

for t in range(0, T):
    s = input()
    t = input()

    m = {}
    for i in list(string.ascii_lowercase):
        m[i] = []

    for i in range(0, len(s)):
        m[s[i]].append(i)

    ans = False
    for pos in m[t[0]]:
        ind = pos
        right = 0
        left = 0
        flag = True
        for i in range(1, len(t)):
            if ind + 1 < len(s) and s[ind + 1] == t[i] and right == 0:
                left = 1
                ind += 1
            elif ind - 1 >= 0 and s[ind - 1] == t[i] and left == 1:
                right = 1
                ind -= 1
            else:
                flag = False
                break
        if flag:
            ans = True
            break

    # # print(m)

    # a = []
    # # s1 = "".join(set(s))
    # for c in t:
    #     a.append(m[c])

    # # print(s1)
    # # print(a)

    # b = list(itertools.product(*a))
    # # print(b)

    # ans = False
    # for l in b:
    #     flag = True
    #     right = 0
    #     left = 0
    #     for i in range(1, len(l)):
    #         if l[i] - l[i - 1] == 1 and right == 0:
    #             left = 1
    #         elif l[i] - l[i - 1] == -1 and left == 1:
    #             right = 1
    #         else:
    #             flag = False
    #             break
    #     if flag == True:
    #         ans = True
    #         break

    if ans == True:
        print("YES")
    else:
        print("NO")
