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
    int n = 0;
    cin >> n;

    vi a(n), b(n);
    for (int &i: a) cin >> i;
    for (int &i: b) cin >> i;

    int i = 0, j = 0, x = 0;
    while (j < n) {
        if (a[i] <= b[j]) i++, j++;
        else j++, x++;
    }

    cout << x << endl;
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