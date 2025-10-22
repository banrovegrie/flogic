#include <bits/stdc++.h>
using namespace std;
#define int long long
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
	    set<pii> s;
        int n, curr = -1;
	    cin >> n;

        for(int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            if (i != 0)
                s.insert({x, i});
            else curr = x;
        }

        while (not s.empty())
        {
            if (curr < (*s.begin()).first) {
                auto it = *s.begin();
                int prev = curr;
                
                curr = (prev + it.first + 1) / 2;
                it.first = (prev + it.first) - curr;
                s.erase(s.begin());
                it.first--, s.insert(it);
            }
            else {
                s.erase(s.begin());
                continue;
            }
        }
        cout << curr << "\n";
    }
}
