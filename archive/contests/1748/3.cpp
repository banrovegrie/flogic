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
        cin >> n;

        vi a(n);
        for (int &i: a) 
            cin >> i;

        vi p(n);
        p[0] = a[0];
        for (int i = 1; i < n; i++)
            p[i] = p[i - 1] + a[i];

        int ans = 0;
        int mx = 0;
        map<int, int> m;
        bool flag = false;
        for (int i = 0; i < n; i++)
        {
            if (p[i] == 0 and flag == false and a[i] != 0)
                ans += 1;
            if (a[i] == 0)
            {
                if (flag == true)
                    ans += max(1ll, mx); 

                mx = 0;
                m.clear();
                flag = true;
            }
            m[p[i]]++;
            mx = max(mx, m[p[i]]);
        }
        if (flag == true)
            ans += max(1ll, mx);

        cout << ans << endl;
    }
}
