#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
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
    int n, m, k, recolor = 0;
    cin >> n >> m >> k;

    if (m == 1) {
        cout << "NO\n";
        return;
    }

    if (n % m == 0)
        recolor = n - (n / m);
    else recolor = n - (n / m) - 1;

    if (recolor <= k) cout << "NO\n";
    else cout << "YES\n";
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