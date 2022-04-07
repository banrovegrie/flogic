import math

def func():
    x = 1
    y = 1
    while True:
        new_x = 3 * x + 4 * y
        new_y = 2 * x + 3 * y
        x, y = new_x, new_y
        print(x, y)
        
        n = (2 + math.sqrt(4 + 8 * (y ** 2 - 1))) / 4
        b = (2 + math.sqrt(4 + 8 * (n ** 2 - n))) / 4
        print(b)
        if (n > 1e12):
            exit(0)

func()