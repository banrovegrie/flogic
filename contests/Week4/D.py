def print_chars(count):
    result = []
    for i in range(26):
        while count[i] > 0:
            result.append(chr(i + ord('a')))
            count[i] -= 1
    return ''.join(result)

s = input().strip()

l, n = len(s), len(s) // 2
count, distinct_count, max_count, max_count_idx = [0] * 26, 0, 0, 0

for char in s:
    idx = ord(char) - ord('a')
    if count[idx] == 0:
        distinct_count += 1
    count[idx] += 1
    if max_count <= count[idx]:
        max_count_idx = idx
        max_count = count[idx]

if n <= 2 and distinct_count == 2 and max_count == n:
    output = "YES\n" + print_chars(count)
elif max_count >= l - 1:
    output = "NO"
elif max_count == l - 2 and distinct_count == 2:
    output = "NO"
elif max_count <= n:
    output = "YES\n" + print_chars(count)
else:
    result = []
    for i in range(26):
        if i == max_count_idx:
            continue
        if count[i] > 0:
            result.append(chr(i + ord('a')))
            count[i] -= 1
            break
    for _ in range(n):
        result.append(chr(max_count_idx + ord('a')))
    count[max_count_idx] -= n
    for i in range(26):
        if i == max_count_idx:
            continue
        if count[i] > 0:
            result.append(chr(i + ord('a')))
            count[i] -= 1
            break
    while count[max_count_idx] > 0:
        result.append(chr(max_count_idx + ord('a')))
        count[max_count_idx] -= 1
    result.extend(print_chars(count))
    output = "YES\n" + ''.join(result)

print(output)

