#include <bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>		// uncomment before
// submission
//#include <ext/pb_ds/tree_policy.hpp>			// uncomment before
// submission
// using namespace __gnu_pbds;					// uncomment
// before submission
using namespace std;
//<---------------------------------------------------Template----------------------------------------------------------->
#define int long long
#define ll long long
#define ld long double
const int INF = 505;
const int MAX = 405;
const int MOD = 1e9 + 7;
typedef pair<ll, ll> ii;
typedef vector<ll> vi;    // Vector of long long
typedef vector<vi> vvi;   // Vector of vi
typedef vector<ii> vii;   // Vector of pairs
typedef vector<vii> vvii; // Vector of Vector of pairs
typedef vector<bool> vb;  // Vector of bool
#define pq                                                                     \
  priority_queue  // Max heap (To convert to min heap, use negative sign before
                  // every value)
#define ff first  // For pairs
#define ss second // For pairs
#define pb push_back                  // Push back to vector
#define mp make_pair                  // Makes pairs to be stored as pair
#define endl "\n"                     // Changes endl to \n
#define all(c) (c).begin(), (c).end() // Mainly used by me in sorting
#define range(c, r) (c).begin(), (c).begin() + (r) // Mainly used in sorting
#define present(c, x) ((c).find(x) != (c).end())   // for sets, maps, multi-maps
#define cpresent(c, x) (find(all(c), x) != (c).end()) // for vectors
#define testcases(T)                                                           \
  int(T);                                                                      \
  cin >> (T);                                                                  \
  while ((T)--) // inputing testcases
#define run(x, c)                                                              \
  for ((x) = (c).begin(); (x) != (c).end();                                    \
       (x)++) // Mainly used by me for range based loops
// ordered_set adds two new functions to set - (set).find_by_order([kth element
// based on zero indexing]) and order_of_key() order_of_key returns number of
// elements less that parameter. If element exists, that order is its index
#define ordered_set                                                            \
  tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update>
//<----------------------------------------------------------------------------------------------------------------------->

int n;
int res;
string s;
int fac[INF + 1];
int invfac[INF + 1];
int dp[MAX][MAX][MAX];
int visited[MAX][MAX][MAX];

int binpow(int x, int y, int m = MOD) {
  int ans = 1;
  while (y > 0) {
    if (y % 2 == 1)
      ans *= x, ans %= m;
    y /= 2;
    x = x * x;
    x %= m;
  }
  return ans % m;
}

int C(int n, int k) {
  return (fac[n] * invfac[n - k] % MOD * invfac[k] % MOD) % MOD;
}

int func(int l, int r, int len) {
  if (len == 0)
    return 1;
  else if (len < 0)
    return 0;
  else if (l == r) {
    if (len == 1)
      return 1;
    return 0;
  }

  if (r < l)
    return 0;

  if (visited[l][r][len])
    return dp[l][r][len];
  visited[l][r][len] = 1;

  int &ans = dp[l][r][len];
  ans = 0;
  if (s[l] == s[r]) {
    int val = func(l + 1, r - 1, len - 2);
    if (len != n)
      res += binpow(C(n, n - len), MOD - 2, MOD) * val, res %= MOD;
    ans += val, ans %= MOD;
  }
  ans += func(l, r - 1, len) + func(l + 1, r, len),
      ans -= func(l + 1, r - 1, len), ans %= MOD;
  return ans;
}

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  fac[0] = invfac[0] = 1;
  for (int i = 1; i <= INF; i++) {
    fac[i] = (fac[i - 1] * i) % MOD;
  }

  invfac[INF] = binpow(fac[INF], MOD - 2, MOD);
  for (int i = INF - 1; i >= 1; i--) {
    invfac[i] = invfac[i + 1] * (i + 1) % MOD;
  }

  int T;
  cin >> T;
  for (int test = 1; test <= T; test++) {
    memset(visited, 0, sizeof(visited));
    memset(dp, -1, sizeof(dp));

    cin >> n;
    cin >> s;

    res = 2;
    for (int i = 0; i < n; i++) {
      for (int j = i + 1; j < n; j++) {
        for (int len = 0; len <= j - i + 1; len++)
          func(i, j, len);
      }
    }

    cout << "Case #" << test << ": " << res << endl;
  }
  return 0;
}
