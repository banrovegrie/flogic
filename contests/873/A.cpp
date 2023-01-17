#include <bits/stdc++.h>
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

signed main() {
	// cin.tie(0)->sync_with_stdio(0);
	// cin.exceptions(cin.failbit);

    int n, k, x;
    cin >> n >> k >> x;

    vi a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    // cout << 0 << endl;

    sort(all(a));
    for (int i = n - 1; i >= 0; i--) {
        if (k > 0)
            a[i] = min(x, a[i]), k--;
    }

    int sum = 0;
    for (int i = 0; i < n; i++) sum += a[i];
    cout << sum << endl;
}
