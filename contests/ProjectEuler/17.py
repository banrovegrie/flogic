import num2words

sum = 0
for i in range(1, 6):
    print(num2words.num2words(i, to="ordinal").replace(" ", "").replace("-", ""))
    sum += len(num2words.num2words(i, to="ordinal").replace(" ", "").replace("-", ""))
print(sum)
