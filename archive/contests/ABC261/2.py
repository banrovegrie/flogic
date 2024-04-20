n = int(input())
A = [["-"] * n for i in range(n)]
for i in range(n):
    s = input()
    A[i] = list(s)

flag = True
for i in range(0, n):
    if A[i][i] != "-":
        flag = False
        break
    for j in range(i + 1, n):
        if (
            (A[i][j] == "W" and A[j][i] == "L")
            or (A[i][j] == "L" and A[j][i] == "W")
            or (A[i][j] == "D" and A[j][i] == "D")
        ):
            continue
        else:
            flag = False
            break
if flag:
    print("correct")
else:
    print("incorrect")
