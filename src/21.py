def sum_factors(n):
    result = []
    for i in range(1, int(n**0.5) + 1):
        if n % i == 0:
            result.append(i)
            result.append(n // i)
    return sum(set(result) - set([n]))


def amicable_pair(number):
    result = []
    for x in range(1, number + 1):
        y = sum_factors(x)
        if sum_factors(y) == x and x != y:
            result.append(tuple(sorted((x, y))))
    return set(result)


pairs = amicable_pair(10001)

sum = 0
for x, y in pairs:
    sum += x + y
print(sum)
