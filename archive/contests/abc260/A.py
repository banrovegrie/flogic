"""
You are given a string S of length 3.
Print a character that occurs only once in S.
If there is no such character, print -1 instead.
"""

s = input()
for c in s:
    if s.count(c) == 1:
        print(c)
        break
else:
    print(-1)