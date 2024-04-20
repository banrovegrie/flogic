def is_prime(num):
    # if (num + 1) % 8 != 0:
    #     return False
    if num > 1:
        for i in range(2, num):
            if (num % i) == 0:
                return False
    return True

def long_division(n):
    num = 1
    digits = []
    mem = {}
    period_start = None
    while True:
        if num in mem:
            period_start = mem[num]
            break
        mem[num] = len(digits)
        digits.append((num * 10) // n)
        num = (num * 10) % n
    prefix = ''.join(f'{d}' for d in digits[:period_start])
    period = ''.join(f'{d}' for d in digits[period_start:])
    return len(period)
    return f'0.{prefix}({period})'

mx = 0
for i in range(1, 1001):
    # if (is_prime(i)):
        print(i, ": ", long_division(i))
        mx = max(mx, long_division(i))

print("The max period is: ", mx)