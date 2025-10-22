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
    sort(all(t));
    if (t == s) {
        cout << 1 << endl;
        return;
    }
    
    bool flag = false;
    int cnt = 1;
    for (int i = 0; i < s.length() - 1; i++) {
        if (s[i] == '0' and s[i + 1] == '1')
            flag = true;
        if (s[i] != s[i + 1]) cnt++;
    }

    cout << cnt - (int)flag << endl;
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
