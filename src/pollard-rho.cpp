/* C++ program to find a prime factor of composite using
Pollard's Rho algorithm */
#include<bits/stdc++.h>
using namespace std;
std::mt19937 gen(std::chrono::system_clock::now().time_since_epoch().count());

using u64 = uint64_t;
using u128 = __uint128_t;

u64 binpower(u64 base, u64 e, u64 MOD) {
    u64 result = 1;
    base %= MOD;
    while (e) {
        if (e & 1)
            result = (u128)result * base % MOD;
        base = (u128)base * base % MOD;
        e >>= 1;
    }
    return result;
}

bool check_composite(u64 n, u64 a, u64 d, int s) {
    u64 x = binpower(a, d, n);
    if (x == 1 || x == n - 1)
        return false;
    for (int r = 1; r < s; r++) {
        x = (u128)x * x % n;
        if (x == n - 1)
            return false;
    }
    return true;
}

// Call this
bool MillerRabin(u64 n) { // returns true if n is prime, else returns false.
    if (n < 2)
        return false;

    int r = 0;
    u64 d = n - 1;
    while ((d & 1) == 0) {
        d >>= 1;
        r++;
    }

    for (u64 a : {2, 3, 5, 7}) {
        if (n == a)
            return true;
        if (check_composite(n, a, d, r))
            return false;
    }
    return true;
}

/* Function to calculate (base^exponent)%modulus */
long long int modular_pow(long long int base, int exponent,
						long long int modulus)
{
	/* initialize result */
	long long int result = 1;

	while (exponent > 0)
	{
		/* if y is odd, multiply base with result */
		if (exponent & 1)
			result = (result * base) % modulus;

		/* exponent = exponent/2 */
		exponent = exponent >> 1;

		/* base = base * base */
		base = (base * base) % modulus;
	}
	return result;
}

/* method to return prime divisor for n */
long long int PollardRho(long long int n)
{
	/* initialize random seed */
	srand (time(NULL));

	/* no prime divisor for 1 */
	if (n==1) return n;

	/* even number means one of the divisors is 2 */
	if (n % 2 == 0) return 2;

	/* we will pick from the range [2, N) */
	long long int x = (gen()%(n-2))+2;
	long long int y = x;

	/* the constant in f(x).
	* Algorithm can be re-run with a different c
	* if it throws failure for a composite. */
	long long int c = (gen()%(n-1))+1;

	/* Initialize candidate divisor (or result) */
	long long int d = 1;

	/* until the prime factor isn't obtained.
	If n is prime, return n */
	while (d==1)
	{
		/* Tortoise Move: x(i+1) = f(x(i)) */
		x = (modular_pow(x, 2, n) + c + n)%n;

		/* Hare Move: y(i+1) = f(f(y(i))) */
		y = (modular_pow(y, 2, n) + c + n)%n;
		y = (modular_pow(y, 2, n) + c + n)%n;

		/* check gcd of |x-y| and n */
		d = __gcd(abs(x-y), n);

		/* retry if the algorithm fails to find prime factor
		* with chosen x and c */
		if (d==n) return PollardRho(n);
	}

	return d;
}

/* driver function */
int main()
{
	for (int i = 2; i <= 1000; i++)
	{
		if (MillerRabin(i))
			cout << i << " ";
		else
			cout << PollardRho(i) << " ";
	}
	cout << endl;
	return 0;
}
