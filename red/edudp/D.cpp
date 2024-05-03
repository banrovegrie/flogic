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
    int N, W;
    cin >> N >> W;

    vi w(N, 0), v(N, 0);
    for (int i = 0; i < N; i++)
        cin >> w[i] >> v[i];

    vector<vector<int> > dp(N + 1, vi(W + 1, 0));
    
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= W; j++) {
                dp[i][j] = dp[i - 1][j];
            if (j - w[i - 1] >= 0)
                dp[i][j] = max(dp[i][j], dp[i - 1][j - w[i - 1]] + v[i - 1]);
        }
    }

    int mx = 0;
    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= W; j++)
            mx = max(mx, dp[i][j]);

    cout << mx << endl;
    return;
}

signed main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
    
    solve();
}