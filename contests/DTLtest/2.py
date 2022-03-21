from matplotlib import pyplot as plt

mn = 1e9

n = 10
m = 10

for i in range(1, n * m  + 1):
    for j in range(1, n * m  + 1):
        for k in range(1, n * m  + 1):
            for l in range(1, n * m  + 1):
                a = i / n
                b = j / n
                c = k / n
                d = l / n
                if ((a + c) * (b + d) == a * c + b * d):
                    ans = a / b + b / c + c / d + d / a
                    if (ans <= 8.035714285714285):
                        print(f"f({a}, {b}, {c}, {d}) = {ans}")
                        print((a ** 2 == c ** 2) or (b ** 2 == d ** 2))
                        print((2 * a * (b + d) == a ** 2 + b * d) or (2 * b * (a + c) == b ** 2 + a * c)) 
                    mn = min(mn, ans)
print(mn)