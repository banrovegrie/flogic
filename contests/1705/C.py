from collections import defaultdict

d = defaultdict(tuple)

def find_index(arr, k):
    if k <= arr[0]:
        return k

    # Find the index of the first element in 
    # the array that is greater than or equal to k
    i = 0
    j = len(arr) - 1
    while i < j:
        mid = (i + j) // 2
        if arr[mid] >= k:
            j = mid
        else:
            i = mid + 1

    index = j
    l, _ = d[index]
    new_k = k - arr[index - 1] - 1  + l

    # print(index, k, new_k, l)
    return find_index(arr, new_k)

def solve():
    n, c, q = map(int, input().split())
    s = input()
    
    arr = [n - 1]
    d[0] = (0, n - 1)

    for i in range(c):
        l, r = map(int, input().split())
        arr.append(arr[-1] + r - l + 1)
        d[i + 1] = (l - 1, r - 1)
    
    # print(arr)

    for _ in range(q):
        k = int(input())
        index = find_index(arr, k - 1)
        print(s[index])

testcases = int(input())
for test in range(testcases):
    solve()
