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

    vi x(n - 1);
    for (int &i: x)
        cin >> i;

    vi a(n);
    a[0] = 1000;
    for (int i = 1; i < n; i++) {
        a[i] = a[i - 1] + x[i - 1];
    }

    for (int i = 1; i < n; i++) {
        assert(a[i] % a[i - 1] == x[i - 1]);
    }

    for (int i: a) cout << i << ' ';
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