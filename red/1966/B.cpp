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
    int n, m;
    cin >> n >> m;

    string s[n];
    for (int i = 0; i < n; i++)
        cin >> s[i];

    if (s[0][0] == s[n - 1][m - 1]) {
        cout << "YES" << endl;
        return;
    }

    if (s[0][m - 1] == s[n - 1][0]) {
        cout << "YES" << endl;
        return;
    }

    if (n == 1 or m == 1) {
        cout << "NO" << endl;
        return;
    }

    // Let's try to shift 0, 0
    char c = s[n - 1][m - 1];
    assert(c != s[0][0]);
    bool f1 = false, f2 = false;

    for (int i = 0; i < n; i++)
        if (s[i][0] == c) 
            f1 = true;

    for (int j = 0; j < m; j++)
        if (s[0][j] == c) 
            f2 = true;

    if (f1 and f2) {
        cout << "YES" << endl;
        return;
    }

    // Let's try to shift n - 1, m - 1
    c = s[0][0];
    assert(c != s[n - 1][m - 1]);
    f1 = false, f2 = false;

    for (int i = 0; i < n; i++)
        if (s[i][m - 1] == c) 
            f1 = true;

    for (int j = 0; j < m; j++)
        if (s[n - 1][j] == c) 
            f2 = true;

    if (f1 and f2) {
        cout << "YES" << endl;
        return;
    }

    // Let's try to shift n - 1, 0
    c = s[0][m - 1];
    assert(c != s[n - 1][0]);
    f1 = false, f2 = false;

    for (int i = 0; i < n; i++)
        if (s[i][0] == c) 
            f1 = true;

    for (int j = 0; j < m; j++)
        if (s[n - 1][j] == c)
            f2 = true;
    
    if (f1 and f2) {
        cout << "YES" << endl;
        return;
    }

    // Let's try to shift 0, m - 1
    c = s[n - 1][0];
    assert(c != s[0][m - 1]);
    f1 = false, f2 = false;

    for (int i = 0; i < n; i++)
        if (s[i][m - 1] == c) 
            f1 = true;

    for (int j = 0; j < m; j++)
        if (s[0][j] == c)
            f2 = true;
    
    if (f1 and f2) {
        cout << "YES" << endl;
        return;
    }

    cout << "NO" << endl;
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