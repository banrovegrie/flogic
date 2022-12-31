#include <bits/stdc++.h>
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

signed main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        int c0 = 0, c1 = 0;
        for (int i = 0; i < n - 1; i++) {
            if (s[i] == '0')
                c0 = i + 1,
                cout << c1 + 1 << " ";
            else
                c1 = i + 1,
                cout << c0 + 1 << " ";
        }
        cout << endl;
    }
}
