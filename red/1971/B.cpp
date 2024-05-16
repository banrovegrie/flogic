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
    string s;
    cin >> s;

    string t = s;
    sort(all(s));
    if (t != s) {
        cout << "YES\n";
        cout << s << endl;
        return;
    }
    
    reverse(all(s));
    if (t != s) {
        cout << "YES\n";
        cout << s << endl;
        return;
    }
    cout << "NO\n";
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
