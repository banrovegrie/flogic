#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
#define ll long long int
#define ld long double
#define ordered_set                                                            \
  tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update>
// added two more functions to set
//(1)*(set.find_by_order(k))[kth element in the sorted set]
//(2)set.order_of_key(k)[count of elements strictly less than k]

// Uncomment when using kactl templates and change typedef of pair
// #define rep(i, a, b) for(int i = a; i < (b); ++i)
// #define sz(x) (int)(x).size()
// typedef pair<int, int> pii;

typedef vector<int> vi;
typedef vector<long long> lvi;
typedef vector<vector<int>> vvi;
typedef vector<vector<long long>> lvvi;
typedef pair<int, int> ii;
typedef pair<long long, long long> lii;
typedef vector<pair<int, int>> vii;
typedef vector<pair<long long, long long>> lvii;
typedef vector<vector<pair<int, int>>> vvii;
typedef vector<vector<pair<long long, long long>>> lvvii;
typedef vector<bool> vb;

mt19937
    rng((unsigned int)chrono::steady_clock::now().time_since_epoch().count());
// usage: x = rng() % k; shuffle(all(v), rng);

#define all(c) (c).begin(), (c).end()
#define tc(t)                                                                  \
  int(t);                                                                      \
  cin >> (t);                                                                  \
  while ((t)--)
#define ff first
#define pb push_back
#define ss second
#ifdef ONLINE_JUDGE
#define error(args...) 0
#else
#define error(args...)                                                         \
  {                                                                            \
    string _s = #args;                                                         \
    replace(_s.begin(), _s.end(), ',', ' ');                                   \
    stringstream _ss(_s);                                                      \
    istream_iterator<string> _it(_ss);                                         \
    err(_it, args);                                                            \
  }
#endif
void err(istream_iterator<string> it) { cerr << endl; }
template <typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
  cerr << "[ " << *it << " = " << a << " ]";
  err(++it, args...);
}

//-----------------------------------------------------------------------------------------------------------------------------------------------------------------
const long long mod = 1e9 + 7;
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------

long long mos() { return 0LL; }
template <typename T, typename... Args> T mos(T a, Args... args) {
  return ((a + mos(args...)) % mod + mod) % mod;
}

long long mop() { return 1LL; }
template <typename T, typename... Args> T mop(T a, Args... args) {
  return (a * mop(args...)) % mod;
}
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------

#define endl "\n"

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  tc(T) {
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    if (x1 != x2 and y1 != y2)
      cout << "sad" << endl;
    else if (x2 > x1)
      cout << "right" << endl;
    else if (x2 < x1)
      cout << "left" << endl;
    else if (y2 > y1)
      cout << "up" << endl;
    else
      cout << "down" << endl;
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