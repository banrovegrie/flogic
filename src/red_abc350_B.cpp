#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cassert>
#include <map>
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
    int n, q;
    cin >> n >> q;

    vi t(q, 0);
    map<int, int> m;
    
    int cnt = 0;
    for (int &i : t) {
        cin >> i, m[i]++;
        if (m[i] % 2 == 1) cnt += 1;
        else cnt -= 1;
    }
    cout << n - cnt << endl;
}

signed main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
    
    solve();
}