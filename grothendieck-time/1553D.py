# import itertools
import string

T = int(input())

for tries in range(0, T):
    s = input()
    t = input()

    if len(t) > len(s):
        print("NO")
        continue

    m = {}
    for i in list(string.ascii_lowercase):
        m[i] = []

    for i in range(0, len(s)):
        m[s[i]].append(i)
