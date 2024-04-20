T = int(input())
for t in range(1, T + 1):
    print(f"Case #{t}:", end=" ")
    
    s = input()
    ans = ""
    for i in range(len(s) - 1):
        ans += s[i]
        if s[i] < s[i + 1]:
            ans += s[i]
        elif s[i] == s[i + 1]:
            flag = False
            for j in range(i + 1, len(s)):
                if (s[j] < s[i]):
                    flag = False
                    break
                elif (s[j] > s[i]):
                    flag = True
                    break
            if flag:
                ans += s[i]
    ans += s[len(s) - 1]
    print(ans)