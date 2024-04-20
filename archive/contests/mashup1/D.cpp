#include <bits/stdc++.h>
using namespace std;
#define endl "\n"

int g[1005][1005], f[1005][1005];
deque<int> q;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int r, c;
        cin >> r >> c;

        for (int i = 1; i <= r; i++)
            for (int j = 1; j <= c; j++)
                cin >> g[i][j];

        for (int i = 1; i <= r; i++) {
            for (int j = 1; j <= c; j++) {
                if (g[i][j] == g[i - 1][j])
                    f[i][j] = f[i - 1][j];
                else f[i][j] = i;
            }
        }
        
        int ans = 0, sum = 0, k = 0;
        for (int i = 1; i <= r; i++)
        {
            for (int j = 1; j <= c; j++)
            {
                if (g[i][j] != g[i][j - 1]) {
                    while (not q.empty()) q.pop_front();
                    q.push_back(i + 1 - f[i][j]),
                    sum = i + 1 - f[i][j],
                    ans += sum; 
                }
                else {
                    k = 0;
                    while (not q.empty()) {
                        if (q.back() <= i + 1 - f[i][j]) break;
                        sum -= q.back(), q.pop_back(), k++;
                    }
                    for (int start = 1; start <= k + 1; start++)
                        sum += i + 1 - f[i][j], q.push_back(i + 1 - f[i][j]);
                    ans += sum;
                }
            }
        }
        cout << ans << endl;
    }
}