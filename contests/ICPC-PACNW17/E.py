import math
n, x, u = map(float, input().split())
n = int(n)

v_y_avg = 0
for i in range(n):
    l, r, v = map(float, input().split())
    v_y_avg += (r - l) / x * v

v_x = 0
if abs(v_y_avg) < u:
      v_x = math.sqrt(u ** 2 - v_y_avg ** 2)
if v_x < 0 or v_x * 2 < u:
    print("Too hard")
else:
    ans = x / v_x
    print('%.3f'%ans)