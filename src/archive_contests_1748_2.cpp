#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define endl '\n'
#define int long long
#define sz(x) (int)(x).size()
#define pb push_back
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
signed main() 
{
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
    int t = 0;
    cin >> t;
    while (t--) 
    {
        int n;
        cin>>n;
        
        string s;
        cin>>s;
        
        int ans = 0;
        for(int i = 0; i < n; i++) {
            map<int, int> m;
            int mx = 0;
            for (int j = 0; j < 100; j++)
            {
                if (i + j >= n)
                    break;
                m[s[i + j] - '0']++;
                mx = max(mx, m[s[i + j] - '0']);
                if (mx <= m.size()) ans++;
            }
        }
        cout << ans << endl;
    }
}
