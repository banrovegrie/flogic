#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define endl '\n'
#define sz(x) (int)(x).size()
#define pb push_back
typedef long long ll;
#define int long long
typedef pair<int, int> pii;
typedef vector<int> vi;
signed main() 
{
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

    int t;
    cin >> t;
    while (t--) 
    {
        int n;
        cin >> n;
        string s;
        cin >> s;

        int count0 = 0;
        int count1 = 0;
        int net0 = 0;
        int net1 = 0;
        int max_count1 = 0;
        int max_count0 = 0;

        for (int i = 0; i < n; i++) 
        {
            if (s[i] == '1')
                count0 = 0,
                count1++, net1++,
                max_count1 = max(count1, max_count1);
            else
                count1 = 0,
                count0++, net0++,
                max_count0 = max(count0, max_count0);
        }

        // cout << net0 << " " << net1 << " " << max_count0 << " " << max_count1 << endl; 
        cout << max(max(net0 * net1, max_count0 * max_count0), max_count1 * max_count1) << endl;
    }
    return 0;
}
