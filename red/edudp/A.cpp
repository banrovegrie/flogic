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

    vi h(n, 0), dp(n + 5, 0);
    for (int &i: h) cin >> i;

    for (int i = 0; i < n; i++) {
        if (i - 1 >= 0)
            dp[i] = dp[i - 1] + abs(h[i] - h[i - 1]);
        if (i - 2 >= 0)
            dp[i] = min(dp[i], dp[i - 2] + abs(h[i] - h[i - 2]));
    }
    cout << dp[n - 1] << endl;   
}

signed main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
    
    solve();
}