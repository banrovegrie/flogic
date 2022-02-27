import re

def simplify(expr):
    match = re.match('^(.*?)(\()(.*)(\))(.*?)$', expr)
    if match:
        parts = list(match.groups())
        parts[2] = simplify(parts[2])
        simplified = ''.join(parts[::2])
        if eval(simplified) == eval(expr):
            return simplified
        return ''.join(parts)
    return expr


s = simplify(input().replace("->", "-").replace("()", "0"))
words = []

count = 0
t = ""
for i in s:
    t += i
    if i == '(':
        count += 1
    elif i == ')':
        count -= 1
    elif i == '-' and count == 0:
        words.append(t)
        t = ""
words.append(t)
print(s)