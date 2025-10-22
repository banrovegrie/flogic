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
    // int n;
    // cin >> n;

    string s;
    cin >> s;

    int n = s.length();

    int c = 0, ans = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == '1') c++;
        else {
            if (c > 0)
                ans += (c + 1);
        }
    }

    cout << ans << endl;
    return;
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    int t;
    cin >> t;

    while (t--) {
        solve();
    }
}