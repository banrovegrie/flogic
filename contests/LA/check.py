from sympy import *

M = Matrix(
    [[1, 1, 1, 6, 7], [1, 2, 2, 11, 10], [2, 3, -4, 3, 3]]
)

print("Matrix : {} ".format(M))

# Use sympy.rref() method
M_rref = M.rref()
print(
    "The Row echelon form of matrix M and the pivot columns : {}".format(M_rref)
)
