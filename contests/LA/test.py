from sympy import *
m = Matrix([
        [1, 1, 1, 6],
        [1, 2, 2, 11],
        [2, 3, -4, 3]])
M_rref = m.rref()
print("The Row echelon form of matrix M and the pivot columns : {}".format(M_rref))