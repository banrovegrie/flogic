#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cassert>
#include <cstring>
using namespace std;
#define int long long
#define endl '\n'
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define pb push_back
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

void solve() {
    int n;
    cin >> n;

    vi a(n), b(n), c(n);
    vector<vector<int> > dp(n + 5, vi(3, 0));
    for (int i = 0; i < n; i++) {
        cin >> a[i] >> b[i] >> c[i];
        dp[i + 1][0] = max(dp[i][1], dp[i][2]) + a[i];
        dp[i + 1][1] = max(dp[i][0], dp[i][2]) + b[i]; 
        dp[i + 1][2] = max(dp[i][0], dp[i][1]) + c[i];
    }

     cout << max(dp[n][0], max(dp[n][1], dp[n][2])) << endl;
    return;
}

signed main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
    
    solve();
}