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
        int n, k;
        cin >> n >> k;
        vector<pii> h(n);

        for(int i = 0; i < n; i++)
            cin >> h[i].first;

        multiset<int> pws;
        for(int i = 0; i < n; i++) {
            cin >> h[i].second;
            pws.insert(h[i].second);
        }

        sort(all(h));
        int i = 0, damage = 0;
        bool dead = false;
        while (true) {
            // cerr << k << endl;
            damage += k;
            while (i < n and h[i].first <= damage) {
                pws.erase(pws.find(h[i].second));
                i++;
            }
            if(i >= n) break;
            auto cp = *pws.begin();
            k -= cp;
            if (k <= 0) {
                dead = true;
                break;
            } 
        }    
        if (dead) cout << "NO\n";
        else cout << "YES\n";
    }
    return 0;
}
