t = int(input())
for tests in range(t):
    # Take integers n and x
    n, x = map(int, input().split())
    h = list(map(int, input().split()))
    h.sort()

    # Divide h into two arrays
    h1 = h[:n]
    h2 = h[n:]
     

    # Check if each element in h2 is greater than 
    # the corresponding element in h1 by x

    # print(h1, h2)

    for i in range(len(h2)):
        if h2[i] - h1[i] < x:
            # print(h2[i], h1[i])
            print("NO")
            break
    else:
        print("YES")