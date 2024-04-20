"""
N examinees took an entrance exam.
The examinee numbered i scored A_i points in math and

B_i points in English.

The admissions are determined as follows.

X examinees with the highest math scores are admitted.
Then, among the examinees who are not admitted yet,
Y examinees with the highest English scores are admitted.
Then, among the examinees who are not admitted yet,
Z examinees with the highest total scores in math and English are admitted.
Those examinees who are not admitted yet are rejected.

Here, in each of the steps 1. to 3., ties are broken by examinees' numbers: an examinee with the smaller examinee's number is prioritized. See also Sample Input and Output.

arr.append the examinees' numbers of the admitted examinees determined by the steps above in ascending order, separated by newlines.
"""

import copy
import numpy
from collections import defaultdict


n, x, y, z = map(int, input().split())
A = list(map(int, input().split()))
B = list(map(int, input().split()))

a = numpy.array(copy.deepcopy(A))
b = numpy.array(copy.deepcopy(B))
C = list(a + b)


A = [(A[i], -i - 1) for i in range(n)]
B = [(B[i], -i - 1) for i in range(n)]
C = [(C[i], -i - 1) for i in range(n)]


A.sort()
A.reverse()
B.sort()
B.reverse()
C.sort()
C.reverse()

d = defaultdict(int)

arr = []

# print(A)
# print(B)
# print(C)

count = 0
for i in range(n):
    if count == x:
        break
    arr.append(-A[i][1])
    count += 1
    d[A[i][1]] = 1

# print(arr)

count = 0
for i in range(n):
    if count == y:
        break
    if d[B[i][1]] == 0:
        arr.append(-B[i][1])
        d[B[i][1]] = 1
        count += 1

# print(arr)
# print(d)

count = 0
for i in range(n):
    # print(f"z = {z}, C[{i}] = {C[i]}, d[C[{i}][1]] = {d[C[i][1]]}")
    if count == z:
        break
    if d[C[i][1]] == 0:
        arr.append(-C[i][1])
        d[C[i][1]] = 1
        count += 1

arr.sort()
for i in arr:
    print(i)