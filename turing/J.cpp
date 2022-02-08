#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
#define ll long long int
#define ld long double
#define ordered_set tree < ll ,  null_type ,  less<ll> ,  rb_tree_tag ,  tree_order_statistics_node_update >
//added two more functions to set
//(1)*(set.find_by_order(k))[kth element in the sorted set] 
//(2)set.order_of_key(k)[count of elements strictly less than k]

// Uncomment when using kactl templates and change typedef of pair
// #define rep(i, a, b) for(int i = a; i < (b); ++i)
// #define sz(x) (int)(x).size()
// typedef pair<int, int> pii;

typedef vector< int > vi;
typedef vector<long long> lvi;
typedef vector< vector<int> > vvi;
typedef vector< vector<long long> > lvvi;
typedef pair< int,int > ii;
typedef pair< long long,long long > lii;
typedef vector<pair<int,int>> vii;
typedef vector<pair<long long,long long>> lvii;
typedef vector<vector<pair<int,int>>> vvii;
typedef vector<vector<pair<long long,long long>>> lvvii;
typedef vector<bool> vb;

mt19937 rng((unsigned int) chrono::steady_clock::now().time_since_epoch().count());
// usage: x = rng() % k; shuffle(all(v), rng);

#define all(c) (c).begin(),(c).end()
#define tc(t) int (t); cin>>(t);while((t)--)
#define ff first
#define pb push_back
#define ss second
#ifdef ONLINE_JUDGE
	#define error(args...) 0
#else
	#define error(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }
#endif
void err(istream_iterator<string> it) {cerr << endl;}
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
	cerr <<"[ "<< *it << " = " << a << " ]";
	err(++it, args...);
}

//-----------------------------------------------------------------------------------------------------------------------------------------------------------------
const long long mod = 1e9 + 7;
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------

long long mos() { return 0LL; }
template<typename T, typename... Args>
T mos(T a, Args... args) { return ((a + mos(args...))%mod + mod)%mod; }

long long mop() { return 1LL; }
template<typename T, typename... Args>
T mop(T a, Args... args) { return (a*mop(args...))%mod; }
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------

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



//function to find the power of two numbers
ll power(ll b, int e, ll m)
{
	//initialize answer
	ll answer = 1;

	while (e > 0)
	{
		//if n is odd, multiply b with answer
		if (e % 2 == 1)
			answer = (answer * b) % m;

		e = e/2;
		b = (b * b) % m;
	}
	return answer;
}

//method to return prime divisor for n
ll pollRh(ll n)
{
	// error(n);
	if(n < 2) return 0;
    // cout << "yes\n";
	if(MillerRabin(n)) return n;
	// cout << "no " << n << endl;
    // error(n);
	//initialize random seed
	srand(time(0));

	//no prime divisor for 1
	if (n==1) return n;

	//even number means one of the divisors is 2
	if (n % 2 == 0) return 2;

	//we will pick from the range [2, N)
	ll x = (gen()%(n-2))+2;
	ll y = x;

	//the constant in f(x).
	//Algorithm can be re-run with a different a
	//if it throws failure for a composite.
	ll a = (gen()%(n-1))+1;

	ll d = 1;

	//until the prime factor isn't obtained.
	//If n is prime, return n
	while (d==1)
	{
		// error(d);
		//second person move x(i+1)=fx(i))
		x = (power(x, 2, n) + a + n)%n;

		//first person move y(i+1) = f(f(y(i)))
		y = (power(y, 2, n) + a + n)%n;
		y = (power(y, 2, n) + a + n)%n;

		//check gcd of |x-y| and n
		d = __gcd(abs(x-y), n);

		// retry if the algorithm fails to find prime factor with chosen x and a
		if (d==n) return pollRh(n);
	}

	return d;
}

#define LL long long

LL mult(LL a, LL b, LL m) { // 64bit multiply 64bit
    a %= m, b %= m;
    LL ret = 0;
    for (; b; b >>= 1) {
        if (b & 1) ret = (ret + a) % m;
        a = (a + a) % m;
    }
    return ret;
}

LL pollard_rho(LL n, LL seed) { // pollard-rho divisors factorization
    LL x, y;
    x = y = rand() % (n - 1) + 1;
    LL head = 1, tail = 2;
    while (true) {
        x = mult(x, x, n);
        x = (x + seed) % n;
        if (x == y) return n;
        LL d = __gcd(max(x - y, y - x), n);
        if (1 < d && d < n) return d;
        if (++head == tail) y = x, tail <<= 1;
    }
}

LL factorize(LL n) {
    if (n == 1) return 0;
    if (MillerRabin(n)) return n;
    else {
        LL d = n;
        while (d >= n) d = pollard_rho(n, rand() % (n - 1) + 1);
        return factorize(d);
    }
}

signed main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);	
    auto check = [&](int x,int p) {
    	if(p > x or p == 0) return 0;
    	int m = 0;
    	while(x > 1) {
    		// error(x, p);
    		if(x % p != 0) return 0;
    		x /= p;
    		m++;
    	}
    	return m;
    };
	tc(T) {
		int k;
		cin >> k;
		int ans = 0;
		set<pair<int,ii>> st; // (n, p, m)
		for(int i = 1; i*i <= k; i++) {
			if(k % i != 0) continue;
			int x = i, y = k / i;
			// y >= x. always multiply on smaller.
			
			// y + 2 == x*p
			// y - 2 == x*p
			// error(x, y);
			if(((y + 2) % x) == 0) {
				int p = (y + 2) / x;
				int pr = factorize(p);
				// error(p, pr);
				int m = check(p, pr);
				if(m > 0) {
					// error()
					// cout << "1" << endl;
					// error(pr, m, x, y);
					st.insert({y + 1, {pr, m}});
				}
			}

			if(y - 2 >= 1 and ((y - 2) % x) == 0) {
				int p = (y - 2) / x;
				int pr = factorize(p);
				int m = check(p, pr);
				if(m > 0) {
					// cout << "2" << endl;
					// error(pr, m, x, y);
					st.insert({y - 1, {pr, m}});
				}
			}

			y *= 2;
			x *= 2;

            if(y - x == 2) {
				st.insert({y - 1, {2, 2}});
			}

			if(y - 2 >= 1 and ((y - 2) % x) == 0) {
				int p = (y - 2) / x;
				int pr = factorize(p);
				int m = check(p, pr);
				if(m > 0 and pr == 2) {
					// cout << "3" << endl;
					// error(pr, m, x, y);
					st.insert({y - 1, {pr, m+2}});
				}
			}

			if(((y + 2) % x) == 0) {
				int p = (y + 2) / x;
				int pr = factorize(p);
				int m = check(p, pr);
				if(m > 0 and pr == 2) {
					// cout << "3" << endl;
					// error(pr, m, x, y);
					st.insert({y + 1, {pr, m+2}});
				}

			}



			// y*2 + 2 == x*2*2^j
			// y*2 - 2 == x*2*2^j

		}
		// for(auto c : st) {
		// 	cout << c.ff << " " << c.ss.ff << " " << c.ss.ss << "\n";
		// }
		cout << st.size() << "\n";
	}
	return 0;
}	


// WA
// 1. overflow
// 2. re-initialize global variables for every test case.
// 3. edge cases like n=1

// Run time error
// 1. division by zero.
// 2. array bounds.

// TLE
// 1. uncomment that #define endl '\n' line