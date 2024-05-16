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
    int n, k, q;
    cin >> n >> k >> q;

    vi a(k + 1, 0), b(k + 1, 0);
    for (int i = 1; i <= k; i++) cin >> a[i];
    for (int i = 1; i <= k; i++) cin >> b[i];

    // sort(all(a));

    while (q--) {
        int d;
        cin >> d;

        // cout << "hell: " << d << endl;

        if (d == n) {
            cout << b[k] << " ";
            continue;
        }
        
        int index = upper_bound(a.begin(), a.end(), d) - a.begin() - 1;
        int diff = d - a[index];
        // cout << d << " " << index << " " << diff << endl;
        int time = b[index] + ((b[index + 1] - b[index]) / (a[index + 1] - a[index])) * (d - a[index]);
        cout << time << " ";
    }
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
