# Python3 program to implement
# the above approach

# Function to find minimum number of
# operations to go back to main folder
def minOperations(arr, N):
	
	# Stores path of
	# the current folder
	st = []

	for i in range(N):
		
		# If stack is not empty and
		# the value of arr[i] is "../"
		if (arr[i] == "../" and len(st) != 0):
			
			# Pop top element of
			# the stack
			st.pop(-1)

		# If the value of arr[i]
		# is like "F/"
		elif (arr[i] != "./"):
			
			# Push arr[i] on top element
			# of the stack
			st.append(arr[i])

	# Return count of elements left
	# into the stack
	return len(st)

# Driver code
if __name__ == '__main__':
	
	# Given array
	arr = [ "x/", "y/", "../",
			"z/", "./" ]

	# Size of the array
	N = len(arr)

	# Function Call
	print(minOperations(arr, N))

# This code is contributed by Shivam Singh
