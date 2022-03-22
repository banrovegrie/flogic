# Python3 program to calculate
# discrete logarithm
import math;

# Iterative Function to calculate
# (x ^ y)%p in O(log y)
def powmod(x, y, p):

	res = 1; # Initialize result

	x = x % p; # Update x if it is more
			# than or equal to p

	while (y > 0):
		
		# If y is odd, multiply x with result
		if (y & 1):
			res = (res * x) % p;

		# y must be even now
		y = y >> 1; # y = y/2
		x = (x * x) % p;
	return res;

# Function to calculate k for given a, b, m
def discreteLogarithm(a, b, m):
	n = int(math.sqrt(m) + 1);

	value = [0] * m;

	# Store all values of a^(n*i) of LHS
	for i in range(n, 0, -1):
		value[ powmod (a, i * n, m) ] = i;

	for j in range(n):
		
		# Calculate (a ^ j) * b and check
		# for collision
		cur = (powmod (a, j, m) * b) % m;

		# If collision occurs i.e., LHS = RHS
		if (value[cur]):
			ans = value[cur] * n - j;
			
			# Check whether ans lies below m or not
			if (ans < m):
				return ans;
	
	return -1;

# Driver code
a = 2;
b = 4541949;
m = 4608347;
print(discreteLogarithm(a, b, m));

# a = 3;
# b = 7;
# m = 11;
# print(discreteLogarithm(a, b, m));

# This code is contributed by mits
