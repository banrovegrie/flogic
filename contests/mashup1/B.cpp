#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int t;
    cin >> t;
    while (t--) {
        int n, m, x, y;
        cin >> n >> m;
        vector<vector<int>> g(n);
        vector<int> d(n, -1), q, ans(n);
        d[0] = 0, q.push_back(0);

        for (int i = 0; i < m; i++)
            cin >> x >> y, x--, y--, g[x].push_back(y);

        for (int i = 0; i < n; i++) {
            int u = q[i];
            for (auto v : g[u])
                if (d[v] == -1)
                    d[v] = d[u] + 1, q.push_back(v);
        }

        for (int i = 0; i < n; i++) {
            ans[i] = d[i];
            for (auto v : g[i]) ans[i] = min(ans[i], d[v]);
        }
        for (int i = n - 1; i >= 0; i--) {
            int u = q[i];
            for (auto v : g[u])
                if (d[v] > d[u]) ans[u] = min(ans[u], ans[v]);
        }

        for (int i = 0; i < n; i++)
            cout << ans[i] << " ";
        cout << endl;
    }
    return 0;
}