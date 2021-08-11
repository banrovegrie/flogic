#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
#define int long long int
#define ll int
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
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
	cerr <<"[ "<< *it << " = " << a << " ]"<< endl;
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



signed main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);	
	tc(T) {
		// lvi sizes;
		priority_queue<int,vi,greater<int>> sizes;
		ll n;
		cin >> n;
		ll cost = 0;
		for (int i = 0; i < n; ++i)
		{
			ll k;
			cin >> k;
			lvi a(k);
			for (int j = 0; j < k; ++j)
			{
				cin >> a[j]; 
			}
			ll max1 = 1;
			for(int j = 0; j < k; j++) {
				int cnt = 1;
				while((j + 1) < k and a[j + 1] >= a[j]) {
					cnt++;
					j++;
				}
				max1 = max(max1, (ll)cnt);
				cost += cnt;
				sizes.push(cnt);
			}
			cost -= max1;
		}
		while(sizes.size() > 1) {
			auto curr = sizes.top();
			sizes.pop();
			auto next = sizes.top();
			sizes.pop();
			cost += (curr + next);
			sizes.push(curr + next);
		}
		cout << cost << endl;
	}
	return 0;
}	

