#include <bits/stdc++.h>
using namespace std;
#define int long long
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define pb push_back
#define endl "\n"
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;

const int mod = 998244353;

signed main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
    int n;
    cin >> n;
    string s;
    cin >> s;

    int sum1 = 0, sum0 = 0;
    int cur1 = 1, cur0 = 1;
    for (int i = 0; i < n; i++) {
        if (s[i] == '1')
            sum1 += cur1, cur1 *= 2;
        else sum0 += cur0, cur0 *= 2;
    }

    for (int i = sum1 + 1; i <= pow(2, n) - sum0; i++) {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}
