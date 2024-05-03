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

    vi a(n);
    for (int &i: a) cin >> i;

    for (int i = 0; i < k; i++) {
        int mx = -1, i1 = -1, i2 = -1;
        for (int i = 1; i < n; i++) {
            if (abs(a[i] - a[i - 1]) > mx)
                mx = abs(a[i] - a[i - 1]), i1 = (a[i] < a[i - 1])? i : i - 1, i2 = (i1 == i)? i - 1 : i;
        }
        a[i2] = a[i1];
    }

    int sum = 0;
    for (int i: a) sum += i;

    cout << sum << endl;
    return;
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