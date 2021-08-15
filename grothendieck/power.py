def solution(xs):
    ans = 1
    min_neg = 0

    zeros = 0
    pos = 0
    negs = 0

    for i in xs:
        if i == 0:
            zeros += 1
        elif i > 0:
            pos += 1
        else:
            negs += 1

        if i != 0:
            ans *= i
        if i < 0:
            if min_neg == 0:
                min_neg = i
            min_neg = max(i, min_neg)

    if min_neg != 0 and ans < 0:
        ans //= min_neg

    if pos == 0:
        if negs == 1:
            if zeros > 0:
                return "0"
            else:
                return str(min_neg)
        if negs == 0:
            return "0"

    return str(ans)


n = int(input())
a = []
for i in range(0, n):
    a.append(int(input()))
print(solution(a))
