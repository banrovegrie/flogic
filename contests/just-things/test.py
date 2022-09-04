from functools import lru_cache

@lru_cache(None)
def recurse(i, j):
    if j >= n:
        return int(i >= m)
    
    ans = 0
    if s[i] == "*":
        ans = max(ans, recurse(i, j+1), recurse(i+1, j+1))
    elif s[i] == "?":
        ans = max(ans, recurse(i+1, j+1))
    else:
        if s[i] == t[j]:
            ans = max(ans, recurse(i+1, j+1))
    
    return ans

s = input()
t = input()
i = j = 0
m, n = len(s), len(t)
print(recurse(0, 0))