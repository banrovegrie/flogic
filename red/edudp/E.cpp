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

    vi w(N), v(N);
    int sum = 0;
    for (int i = 0; i < N; i++) 
        cin >> w[i] >> v[i], sum += v[i];

    vector<vector<int>> dp(N + 5, vi(sum + 5, (int)1e18));
    dp[0][0] = 0;
    for (int i = 1; i <= N; i++) {
        for (int j = 0; j <= sum; j++) {
            dp[i][j] = dp[i - 1][j];
            if (j - v[i - 1] >= 0)
                dp[i][j] = min(dp[i][j], dp[i - 1][j - v[i - 1]] + w[i - 1]);
        }
    }

    // for (int i = 1; i <= N; i++) {
    //     for (int j = 0; j <= sum; j++) {
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    for (int j = sum; j >= 0; j--) {
        if (dp[N][j] <= W) {
            cout << j << endl;
            return;
        }
    }
}

signed main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
    
    solve();
}