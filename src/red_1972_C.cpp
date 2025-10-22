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
    // input
    int n, k;
    cin >> n >> k;

    vi a(n);
    for (int &i : a) 
        cin >> i;

    sort(all(a));

    int cnt = 1, index = 0;
    for (int i = 1; i < n; i++) {
        if (a[i] > a[i - 1]) {
            int diff = a[i] - a[i - 1];
            if (diff * cnt <= k)
                index = i, k -= diff * cnt;
            else break;
            cnt++;
        }
        else cnt++;
    }

    while (index < n - 1 and a[index] == a[index + 1])
        index++;
    
    // still k left
    if (index == n - 1) {
        int ans = a[index] + (k / (index + 1));
        k %= (index  + 1);
    
        cout << ans * n - (index + 1 - k) + 1 << endl;
        return;
    }

    // no k left
    // cout << k << endl;
    // cout << index << endl;
    int num = a[index] + (int) (k / (index + 1));
    k -= (int) (k / (index + 1)) * (index + 1);
    int ans = (((num - 1) * n) + 1);
    // cout << ans << endl;
    // cout << k << endl;

    cout << ans + (n - (index + 1)) + min(k, index + 1) << endl;
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