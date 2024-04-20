tests = int(input())


def get_prefix_sum(arr):
    p = [0 for _ in arr]
    for i in range(len(arr)):
        p[i] = arr[i] + (p[i - 1] if i - 0 >= 0 else 0)
    return p


def get_suffix_sum(arr):
    arr.reverse()
    p = [0 for _ in arr]
    for i in range(len(arr)):
        p[i] = arr[i] + (p[i - 1] if i - 1 >= 0 else 0)
    arr.reverse()
    # p.reverse()
    return p


for t in range(1, tests + 1):
    ans = 0
    n = int(input())
    a = list(map(int, input().split()))
    m = int(input())
    b = list(map(int, input().split()))
    k = int(input())

    pre_a = [0] + get_prefix_sum(a)
    pre_b = [0] + get_prefix_sum(b)
    suf_a = [0] + get_suffix_sum(a)
    suf_b = [0] + get_suffix_sum(b)

    # print(pre_a, pre_b, suf_a, suf_b)

    dp_a = [0 for _ in range((min(n, k)) + 1)]
    dp_b = [0 for _ in range((min(m, k)) + 1)]

    for i in range(1, min(n, k) + 1):
        dp_a[i] = pre_a[i]
        for j in range(i):
            dp_a[i] = max(dp_a[i], pre_a[j] + suf_a[i - j])

    for i in range(1, min(m, k) + 1):
        dp_b[i] = pre_b[i]
        for j in range(i):
            dp_b[i] = max(dp_b[i], pre_b[j] + suf_b[i - j])

    # print(dp_a, dp_b)

    for i in range(0, k + 1):
        if i > n or k - i > m:
            continue
        ans = max(ans, dp_a[i] + dp_b[k - i])

    print(f"Case #{t}: {ans}")
