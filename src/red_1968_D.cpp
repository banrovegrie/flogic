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

const int N = (int) 1e6;
vector<bool> visited;
vector<int> p, a;

int maxsum(int k, int pos) {
    if (k == 0)
        return 0;

    if (visited[pos])
        return a[pos] * k;

    visited[pos] = true;
    k--;
    return max(a[pos] + a[pos] * k, a[pos] + maxsum(k, p[pos]));
}

void solve() {
    int n, k, p1, p2;
    cin >> n >> k >> p1 >> p2, p1--, p2--;

    p.clear(), a.clear();
    p.resize(n), a.resize(n);
    for (int &i: p)
        cin >> i, i--;
    for (int &i: a)
        cin >> i;

    visited.clear();
    visited.resize(n, false);
    int s1 = maxsum(k, p1);
    
    visited.clear();
    visited.resize(n, false);
    int s2 = maxsum(k, p2);

    cerr << s1 << ' ' << s2 << endl;

    if (s1 == s2) cout << "Draw" << endl;
    else if (s1 > s2) cout << "Bodya" << endl;
    else cout << "Sasha" << endl;
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
