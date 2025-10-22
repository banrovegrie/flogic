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
    string x, y, a = "", b = "";
    cin >> x >> y;

    if (x[0] <= y[0])
        a += x[0], b+= y[0];
    else
        a+= y[0], b += x[0];

    for (int i = 1; i < x.size(); i++) {
        // cout << x << " " << y << " " << (x > y) << endl;
        if (a > b)
            swap(a, b);

        if (x[i] >= y[i])
            a += x[i], b += y[i];
        else
            a += y[i], b += x[i];
    }
    cout << a << endl;
    cout << b << endl;
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