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
    int a, b, c, d;
    cin >> a >> b >> c >> d;

    if (a > b) swap(a, b);
    if (c > d) swap(c, d);

    if (a <= c and c <= b and b <= d) cout << "YES\n";
    else if (c <= a and a <= d and d <= b) cout << "YES\n"; 
    else cout << "NO\n";
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
