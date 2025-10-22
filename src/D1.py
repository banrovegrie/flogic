string_of_integers = input()

# Split the string into a list of integers

list_of_integers = list(set([int(num) for num in string_of_integers.split()]))

# Sort the list
list_of_integers.sort()


# Convert sorted list back to string
sorted_string_of_integers = ' '.join(map(str, list_of_integers))

# Print sorted string
print(sorted_string_of_integers, end="\n\n")

for i in range(64):
    if i not in list_of_integers:
        print(i, end=" ")