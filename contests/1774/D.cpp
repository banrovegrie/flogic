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
typedef vector<vector<int>> vvi;

signed main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

    int t;
    cin >> t;
    while (t--) {
        int n, m, count = 0;
        cin >> n >> m;

        vi arr(n), L, R;
        vvi a(n, vi(m));
        vector<pair<int, pair<int, int>>> ans;

        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                cin >> a[i][j],
                count += a[i][j], arr[i] += a[i][j];
    
        if (count % n) {
            std::cout << "-1" << endl;
            continue;
        }
        count /= n;
        
        for (int j = 0; j < m; j++) {
            L.clear(), R.clear();
            for (int i = 0; i < n; i++) {
                if (a[i][j] == 0 and arr[i] < count)
                    L.push_back(i);
                if (a[i][j] == 1 and arr[i] > count)
                    R.push_back(i);
            }

            while (true)
            {
                if (L.empty() or R.empty())
                    break;
                arr[L.back()] += 1, arr[R.back()] -= 1;
                ans.push_back({R.back() + 1, {L.back() + 1, j + 1}});
                L.pop_back(), R.pop_back();
            }
        }

        std::cout << ans.size() << "\n";
        for(auto it: ans)
        {
            std::cout << it.first << " ";
            std::cout << it.second.first << " ";
            std::cout << it.second.second << endl;
        }
    }
}
