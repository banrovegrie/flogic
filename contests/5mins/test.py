
one = 0
two = 0
updater = 0

arr = []
while True:
    i = int(input())
    two = (one & i) | two
    one = one ^ i # works if a number comes once or twice
    # imagine this is the third occurence of the number
    # one <- num
    updater = (one & two)
    print(f"intersection = {updater} and one = {one} and two = {two}")
    arr.append(i)
    print(arr)
    # Updated denotes the third number
    # num
    # common = ~ (one & two)
    one = one & ~ (updater)
    two = two & ~ (updater)