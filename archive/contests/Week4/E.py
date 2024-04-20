def min_cost(np, cc, mda, crc, mma, mrc, atc, mad, ag):
    ag.sort()
    min_cost = float('inf')

    ummc = sum(1 for age in ag if age + mad < mma)
    aib = sum(max(0, min(mad, age - mma)) for age in ag)
    adb = sum(max(0, min(mad, mma - age)) for age in ag)

    tc = np * mrc + adb * atc
    if ummc == 0 and aib >= adb:
        min_cost = tc

    left, right, ccnt = 0, np - 1, 0

    while (right - left + 1) >= cc:
        ccnt += 1
        for i in range(cc - 1):
            adb -= max(0, min(mad, mma - ag[i + left]))
            aib += min(mad, min(mma, ag[i + left]) - 1)
            if ag[i + left] + mad < mma:
                ummc -= 1

        adb += max(0, mda - max(mma, ag[right]))
        aib = aib - max(0, min(mad, ag[right] - mma)) + \
            max(0, min(mad, ag[right] - mda))
        if ag[right] + mad < mda:
            break
        tc = mrc * (np - ccnt * cc) + ccnt * crc + adb * atc
        if ummc == 0 and aib >= adb:
            min_cost = min(tc, min_cost)
        left += cc - 1
        right -= 1

    if ag[right] + mad >= mda:
        ccnt += 1
        for i in range(right - left):
            adb -= max(0, min(mad, mma - ag[i + left]))
            aib += min(mad, min(mma, ag[i + left]) - 1)
            if ag[i + left] + mad < mma:
                ummc -= 1
        adb += max(0, mda - max(mma, ag[right]))
        aib = aib - max(0, min(mad, ag[right] - mma)) + \
            max(0, min(mad, ag[right] - mda))
        tc = ccnt * crc + adb * atc
        if ummc == 0 and aib >= adb:
            min_cost = min(tc, min_cost)

    return -1 if min_cost == float('inf') else min_cost


n, k = map(int, input().split())
lc, pc, lm, pm = map(int, input().split())
t, d = map(int, input().split())
a = [int(x) for x in input().split()]
print(min_cost(n, k, lc, pc, lm, pm, t, d, a))
