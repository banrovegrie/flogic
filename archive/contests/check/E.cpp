#include <bits/stdc++.h>
using namespace std;

#define int long long
#define st first
#define nd second
#define mp make_pair
#define pq priority_queue
#define cl(x, v) memset((x), (v), sizeof(x))
#define gcd(x, y) __gcd((x), (y))
#define pb push_back

// Comment the following when flushing.
#define endl "\n"

#define all(c) (c).begin(), (c).end()
#define range(c, r) (c).begin(), (c).begin() + (r)
#define present(c, x) ((c).find(x) != (c).end())
#define cpresent(c, x) (find(all(c), x) != (c).end())
#define run(x, c) for ((x) = (c).begin(); (x) != (c).end(); (x)++)
#define rep(i, n) for (i = 0; i < n; i++)
#define REP(i, k, n) for (i = k; i <= n; i++)
#define REPR(i, k, n) for (i = k; i >= n; i--)

// Ordered set adds two new functions to set -
// (set).find_by_order([kth element based on zero indexing])
// and, order_of_key()
// order_of_key returns ansber of elements less that parameter.
// If element exists, that order is its index.
#define ordered_set                                                            \
  tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update>

#ifndef ONLINE_JUDGE
#define db(x) cerr << #x << " == " << x << endl
#define dbs(x) cerr << x << endl
#define _ << ", " <<
#else
#define db(x) ((void)0)
#define dbs(x) ((void)0)
#endif

typedef long long ll;
typedef long double ld;

typedef pair<int, int> pii;
typedef pair<int, pii> piii;
typedef pair<ll, ll> ii;
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef vector<pii> vii;
typedef vector<vii> vvii;

const ld EPS = 1e-9, PI = acos(-1.);
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const int INF = 0x3f3f3f3f, MOD = 1e9 + 7;

const int N = 1e5 + 5;

/*
  Uncomment the following before submission.
*/
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;

ll power(ll a, ll b, ll m = MOD) {
  ll ans = 1;
  while (b) {
    if (b & 1) 
      ans = (ans * a) % m;
    a = (a * a) % m;
    b >>= 1;
  }
  return ans;
}

ll modinv(ll n, int p = MOD) {
  return power(n, p - 2, p);
}

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  // freopen("in", "r", stdin);
  // freopen("out", "w", stdout);

  int t;
  cin >> t;
  while (t--) {
    int n, c;
    cin >> n >> c;

    __int128_t x, y, z;
    __int128_t nx = n;
    __int128_t ans = 5 * nx * nx;

    if (n & 1)
      ans = ans - 1;
    
    x = power(c, ans % (MOD - 1)), ans /= 2;
    y = power(c, ans % (MOD - 1)), ans /= 2;
    z = power(c, ans % (MOD - 1));
    ans = ((x + y + 2 * z) * modinv(4)) % MOD;
    // {
    //     y-=z;
    //     x-=y;
    //     x-=z;
    // }
    if (n & 1)
      ans = (ans * c) % MOD;

    int result = ans % MOD;
    cout << result << '\n';
  }
  return 0;
}
