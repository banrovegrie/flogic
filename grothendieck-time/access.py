def solution(l):

    m = [0] * len(l)

    for i in range(1, len(l) - 1):
        for j in range(i):
            if l[i] % l[j] == 0:
                m[i] += 1

    cnt = 0
    for i in range(2, len(l)):
        for j in range(1, i):
            if l[i] % l[j] == 0:
                cnt += m[j]

    print(cnt)


solution([1, 1, 1])
