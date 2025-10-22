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
    int n, k;
    cin >> n >> k;

    vi h(n, 0), dp(n + 5, (int)1e18);
    for (int &i: h) cin >> i;
    dp[0] = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 1; j <= k; j++)
            if (i - j >= 0)
                dp[i] = min(dp[i], dp[i - j] + abs(h[i] - h[i - j]));
    }

    if (dp[n - 1] == (int)1e18)
        dp[n - 1] = 0;

    cout << dp[n - 1] << endl;   
}

signed main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
    
    solve();
}