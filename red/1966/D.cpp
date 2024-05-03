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

    vi a;
    int x = 0;

    for (int i = 0; i < 21; i++) {
        a.pb(1 << i);

        if (1 << i <= k)
            x = i;
    }

    a.clear();

    for (int i = 0; i < 21; i++) {
        if (i != x)
            a.pb(1 << i);
    }


    a.pb(k - (1 << x));
    a.pb(k + 1);
    // if (k == (1 << x))
    a.pb(k + 1 + (1<<x));

    cout << a.size() << endl;
    for (int i: a) cout << i << " ";
    cout << endl;
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
