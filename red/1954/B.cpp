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

    vi a(n);
    for (int &i: a) cin >> i;

    assert(a[0] == a[(int)a.size() - 1]);
    if (a[0] != a[(int)a.size() - 1]) {
        cout << 0 << endl;
        return;
    }

    int s = a[0], cnt = 0, flag = false, mn = (int)1e15; // the start and end variable

    for (int i = 0; i < n; i++) {
        if (s == a[i]) {
            cnt += 1;        
        } else break;
    }
    mn = min(mn, cnt);

    for (int i = 0; i < n; i++) {
        if (a[i] != s) {
            flag = true;
            mn = min(mn, cnt);
            cnt = 0;
        }
        else {
            if (flag)
                cnt++;
        }
        // cout << cnt << endl;     
    }
    mn = min(mn, cnt);

    if (flag == false) cout << "-1\n";
    else cout << mn << endl;
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