#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cassert>
#include <cstring>
#include <set>
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

    vi a(n), arr;
    set<int> s;
    for (int &i: a) cin >> i, s.insert(i);
    for (int i: s) arr.pb(i);

    bool f = false;
    int x = 0;
    for (int i = 0; i < arr.size(); i++) {
        f = not f;
        if (arr[i] - x > 1)
            break;
        x = arr[i];
    }

    if (f) cout << "Alice" << endl;
    else cout << "Bob" << endl;
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