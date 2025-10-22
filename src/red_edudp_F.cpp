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
    string s, t;
    cin >> s >> t;

    vector<vector<int> > dp((int)s.length() + 5, vi((int)t.length() + 5));

    for (int i = 0; i < s.length(); i++) {
        for (int j = 0; j < t.length(); j++) {
            dp[i + 1][j + 1] = max(dp[i][j + 1], dp[i + 1][j]);
            if (s[i] == t[j])
                dp[i + 1][j + 1] = max(dp[i + 1][j + 1], dp[i][j] + 1);
        }
    }

    cout << dp[(int)s.length()][(int)t.length()] << endl;
    return;
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    // int t;
    // cin >> t;

    // while (t--) {
        solve();
    // }
}
