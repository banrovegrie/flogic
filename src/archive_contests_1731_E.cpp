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
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

    int t;
    cin >> t;

    while (t--) {        
        int n, m, ans = 0, x = 0, temp1 = 0, temp2 = 0;
        cin >> n >> m;
        vi arr(n + 1);

        for (int i = n; i >= 2; i--) {
            x = (n / i) * ((n / i) - 1) / 2;
            for (int j = 2 * i; j <= n; j += i)
                x -= arr[j];

            temp1 = min(x / (i - 1), m / (i - 1)),
            temp2 = temp1 * (i - 1);

            arr[i] = x;
            ans += temp1 * i;
            x -= temp2, m -= temp2;
        }

        if (m == 0)
            cout << ans << endl;
        else
            cout << -1 << endl;
        
    }
	return 0;
}
