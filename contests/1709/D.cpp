#include <bits/stdc++.h>

using namespace std;

// ########################################### BEGIN TEMPLATE ###########################################
#define ll long long
#define ft first
#define sc second
#define pb push_back
#define ins insert
#define io                            \
	ios_base::sync_with_stdio(false); \
	cin.tie(NULL);                    \
	cout.tie(NULL)
#define all(v) v.begin(), v.end()
#define Sort(v) sort(all(v))
#define sortarr(a, n) sort(a, a + n)
#define tt     \
	ll tc;     \
	cin >> tc; \
	while (tc--)
#define tt2    \
	ll tc;     \
	cin >> tc; \
	rep(z, 1, tc + 1, 1)
// iterate in [start,end) with interval
#define rep(var, start, end, interval) for (ll var = start; (interval > 0 and var < end) or (interval < 0 and var > end); var += interval)
#define each(x, v) for (auto &x : v)
#define takearr0(a) \
	each(x, a)      \
			cin >>  \
		x;
#define takearr1(a)                                    \
	for (auto it = a.begin() + 1; it != a.end(); ++it) \
		cin >> *it;
typedef pair<ll, ll> pll;
typedef pair<ll, int> pli;
typedef pair<int, ll> pil;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<bool> vb;
typedef vector<vb> vvb;
typedef vector<char> vc;
typedef vector<vc> vvc;
typedef vector<string> vs;
typedef vector<vs> vvs;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef vector<pii> vpii;
typedef vector<vpii> vvpii;
typedef vector<pll> vpll;
typedef vector<vpll> vvpll;
typedef set<int> si;
typedef set<vi> svi;
typedef set<ll> sll;
typedef set<vll> svll;
typedef set<pii> spii;
typedef set<vpii> svpii;
typedef set<pll> spll;
typedef set<vpll> svpll;
typedef vector<si> vsi;
typedef vector<sll> vsll;
typedef vector<spii> vspii;
typedef vector<spll> vspll;
// ------------------------ DEBUG START --------------------------------
#ifndef ONLINE_JUDGE // if ONLINE_JUDGE is not defined (when compiling on our pc, this is true)
template <class T1, class T2>
ostream &operator<<(ostream &os, const pair<T1, T2> &p)
{
	return os << '{' << p.first << ", " << p.second << '}';
}

template <class T, class = decay_t<decltype(*begin(declval<T>()))>,
		  class = enable_if_t<!is_same<T, string>::value>>
ostream &operator<<(ostream &os, const T &c)
{
	os << '[';
	for (auto it = c.begin(); it != c.end(); ++it)
		os << &", "[2 * (it == c.begin())] << *it;
	return os << ']';
}
// support up to 5 args
#define _NTH_ARG(_1, _2, _3, _4, _5, _6, N, ...) N
#define _FE_0(_CALL, ...)
#define _FE_1(_CALL, x) _CALL(x)
#define _FE_2(_CALL, x, ...) \
	_CALL(x)                 \
	_FE_1(_CALL, __VA_ARGS__)
#define _FE_3(_CALL, x, ...) \
	_CALL(x)                 \
	_FE_2(_CALL, __VA_ARGS__)
#define _FE_4(_CALL, x, ...) \
	_CALL(x)                 \
	_FE_3(_CALL, __VA_ARGS__)
#define _FE_5(_CALL, x, ...) \
	_CALL(x)                 \
	_FE_4(_CALL, __VA_ARGS__)
#define FOR_EACH_MACRO(MACRO, ...)                                           \
	_NTH_ARG(dummy, ##__VA_ARGS__, _FE_5, _FE_4, _FE_3, _FE_2, _FE_1, _FE_0) \
	(MACRO, ##__VA_ARGS__)
// Change output format here
#define out(x) #x " = " << x << "; "
#define dbg(...) cerr << "Line " << __LINE__ << ": " FOR_EACH_MACRO(out, __VA_ARGS__) << "\n"
#else
#define dbg(...) // else, when defined (most modern CP sites have this defined), define dbg(...). \
				 // this basically just would do nothing on seeing dbg() and thus no need to remove dbg() while submitting.
#endif
// ------------------------ DEBUG END ----------------------------------
const ll mod = 1e9 + 7;

ll modpow(ll a, ll b, ll m = mod) // a^b (mod m)
{
	ll ans = (a != 0);
	while (b)
	{
		if (b & 1)
			ans = (ans * a) % m;
		a = (a * a) % m;
		b >>= 1;
	}
	return ans;
}

ll modinv(ll a, ll m = mod) // a^(-1) (mod m)
{
	if (a == 0)
		dbg("ALERT: modinv of 0");
	return modpow(a, m - 2, m);
}

ll gcd(ll a, ll b)
{
	assert(a >= 0 and b >= 0);
	if (a < b)
		swap(a, b);
	while (b)
	{
		ll t = a % b;
		a = b;
		b = t;
	}
	return a;
}

ll lcm(ll a, ll b)
{
	assert(a >= 0 and b >= 0);
	return (a * b) / gcd(a, b);
}

void gen_perm(vll &perm, ll n, ll m = mod) // permutations from 0..n generated (mod m)
{
	assert(n >= 0);
	perm[0] = 1;
	rep(i, 1, n, 1) perm[i] = (perm[i - 1] * i) % m;
}

void gen_perm(vll &perm, vll &perm_inv, ll n, ll m = mod) // permutations from 0..n generated (mod m)
{
	assert(n >= 0);
	perm[0] = perm_inv[0] = 1;
	rep(i, 1, n, 1)
	{
		perm[i] = (perm[i - 1] * i) % m;
		perm_inv[i] = modinv(perm[i], m);
	}
}

ll C(vll &perm, vll &perm_inv, ll n, ll k, ll m = mod) // modular combinatorial choose (mod m)
{
	assert(n >= 0 and k >= 0);
	if (n < k)
		return 0LL;
	return (perm[n] * ((perm_inv[k] * perm_inv[n - k]) % m)) % m;
}

ll P(vll &perm, vll &perm_inv, ll n, ll k, ll m = mod) // modular combinatorial perm (mod m)
{
	assert(n >= 0 and k >= 0);
	if (n < k)
		return 0LL;
	return (perm[n] * perm_inv[n - k]) % m;
}

vb get_primes(ll n) // get boolean vector indicating prime numbers (with true) till n. Method used: Sieve of Eratosthenes
{
	assert(n > 1);
	vb prime(n + 1, true);
	prime[0] = prime[1] = false;
	rep(i, 2, n + 1, 1) if (prime[i]) rep(j, i + i, n + 1, i) prime[j] = false;
	return prime;
}

class DSU
{
public:
	int n;			 // number of elements
	int cc;			 // number of connected components
	vector<int> par; // parent of each element

	DSU(int num)
	{
		n = num;
		par.resize(num);
		par.assign(num, -1);
		cc = num;
	}

	int get_par(int x) // x is 0-based
	{
		assert(0 <= x and x < n);
		if (par[x] == -1)
			return x;
		return par[x] = get_par(par[x]);
	}

	void merge(int x, int y) // x and y are 0-based
	{
		assert(0 <= x and x < n);
		assert(0 <= y and y < n);
		x = get_par(x);
		y = get_par(y);
		if (x == y)
			return;
		if (y < x)
			swap(x, y);
		par[y] = x;
		--cc;
	}
};
// ########################################### END TEMPLATE ###########################################

ll max_q(vvll &sptb, vll &log_arr, ll x, ll y)
{
	if (x > y)
		swap(x, y);

	if (x == y)
		return sptb[x][0];

	return max(sptb[x][log_arr[y - x]], sptb[y - (1 << log_arr[y - x])][log_arr[y - x]]);
}

int main()
{
	io;
	ll n, m, q;
	cin >> n >> m;
	vll a(m);
	takearr0(a);
	vll log_arr(m + 1, 0);
	log_arr[0] = -1e18;
	ll val = 1, pw = 0;
	rep(i, 1, m + 1, 1)
	{
		if (i >= val * 2)
		{
			val <<= 1;
			++pw;
		}
		log_arr[i] = pw;
	}
	vvll sptb(m, vll(log_arr[m] + 1, n + 5));
	rep(i, 0, m, 1) sptb[i][0] = a[i];
	rep(j, 1, log_arr[m] + 1, 1)
	{
		rep(i, 0, m, 1)
		{
			if (i + (1 << j) <= m)
				sptb[i][j] = max(sptb[i][j - 1], sptb[i + (1 << (j - 1))][j - 1]);
			else
				sptb[i][j] = sptb[i][j - 1];
		}
	}
	cin >> q;
	while (q--)
	{
		ll xs, ys, xf, yf, k;
		cin >> xs >> ys >> xf >> yf >> k;
		--ys, --yf;
		ll mx = max_q(sptb, log_arr, ys, yf);
		bool flag = true;
		flag &= (abs(xs - xf) % k == 0);
		flag &= (abs(ys - yf) % k == 0);
		flag &= (xs + ((mx - xs) / k + 1) * k <= n);
		if (flag)
			cout << "YES\n";
		else
			cout << "NO\n";
	}
	return 0;
}
