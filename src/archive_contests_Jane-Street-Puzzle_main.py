import sys
sys.setrecursionlimit(1500)

def run_recursion(a, b, c, d):
    new_a, new_b, new_c, new_d = abs(a - b), abs(b - c), abs(c - d), abs(d - a)
    if (new_a + new_b + new_c + new_d == 0):
        return 1
    return 1 + run_recursion(new_a, new_b, new_c, new_d)

def get_recursion(a, b, c, d):
    print(a, b, c, d)
    new_a, new_b, new_c, new_d = abs(a - b), abs(b - c), abs(c - d), abs(d - a)
    if (new_a + new_b + new_c + new_d == 0):
        return 1
    return 1 + get_recursion(new_a, new_b, new_c, new_d)


def generate(n):
    max_depth = 0
    arr = []
    min_sum = 4 * n
    ans = ""
    for a in range(0, n):
        for b in range(0, n):
            for c in range(0, n):
                depth = run_recursion(a, b, c, 0)
                if depth == max_depth:
                    if min_sum > (a + b + c):
                        min_sum = a + b + c
                        ans = f"{a};{b};{c};0: {depth} ({a + b + c})"
                    arr.append(f"{a};{b};{c};0: {depth} ({a + b + c})")
                elif depth > max_depth:
                    max_depth = depth
                    min_sum = a + b + c
                    ans = f"0;{a};{b};{c}: {depth} ({a + b + c})"
                    arr = []

    print(ans)
    # [print(i) for i in arr]
    # print(get_recursion(0, 44, 20, 7))

for i in range(1, 60):
    generate(i)