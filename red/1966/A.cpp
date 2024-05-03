#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cassert>
#include <cstring>
#include <map>
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

    vi a(n);
    map<int, int> m;
    for (int &i: a) cin >> i, m[i]++;

    int mx = 0;
    for (auto i: m)
        mx = max(mx, i.second);

    if (mx < k)
        cout << n << endl;
    else
        cout << min(k - 1, n) << endl;
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
