import math


def solution(pegs):
    diff = []
    net = 0
    for i in range(1, len(pegs)):
        diff.append(pegs[i] - pegs[i - 1])
        if i % 2:
            net += pegs[i] - pegs[i - 1]
        else:
            net -= pegs[i] - pegs[i - 1]

    if len(diff) % 2:
        ans = 2 * net / 3
        a = 2 * net
        b = 3
        if ans > 0:
            g = math.gcd(a, b)
            return [a // g, b // g]
        else:
            return [-1, -1]
    else:
        ans = 2 * net
        if ans > 0:
            return [ans, 1]
        else:
            return [-1, -1]


print(solution([4, 17]))
