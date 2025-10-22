#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

#define int long long

signed main() {
    int n, m, qq;
    cin >> n >> m >> qq;
    vector<int> tt(3*m + 1), which(3*m + 1), size(3*m + 1), in(3*m + 1);
    vector<vector<int>> par(3*m + 1), adj(3*m + 1);
    size[1] = n;
    for(int i = 0; i < m; i++) {
        char ch;
        cin >> ch;
        int x, y, z;
        cin >> x >> y >> z;
        if (ch == 'S') {
            par[y].push_back(x);
            par[z].push_back(x);
            adj[x].push_back(y);
            adj[x].push_back(z);
            in[y]++;
            in[z]++;
            tt[y] = 0;
            tt[z] = 0;
            // size[y] = (size[x] + 1) / 2;
            // size[z] = size[x] / 2;
            which[y] = 0;
            which[z] = 1;
        } else {
            par[z].push_back(x);
            par[z].push_back(y);
            adj[x].push_back(z);
            adj[y].push_back(z);
            in[z] += 2;
            // size[z] = size[x] + size[y];
            tt[z] = 1;
        }
    }
    queue<int> q;
    q.push(1);
    while(!q.empty()) {
        auto x = q.front();
        q.pop();
        if (x != 1) {
            if(tt[x] == 0) {
                if(which[x] == 0) {
                    size[x] = (size[par[x][0]] + 1) / 2;
                } else {
                    size[x] = (size[par[x][0]]) / 2;
                }
            } else {
                size[x] = size[par[x][0]] + size[par[x][1]];
            }
        }
        for(auto nx : adj[x]) {
            in[nx] -= 1;
            if(in[nx] == 0) q.push(nx);
        }
    }
    while(qq--) {
        long long x, k;
        cin >> x >> k;
        bool flag = true;
        while(x != 1) {
            if (k > size[x]) {
                flag = false;
                break;
            }
            // cerr << x << " " << k << " " << tt[x] << " " << which[x] << endl;
            // split
            if(tt[x] == 0) {
                // first child
                if(which[x] == 0) {
                    k = 2 * k - 1;
                } else {
                    k = 2 * k;
                }
                x = par[x][0];
            } else {
                int allow = 2 * min(size[par[x][0]], size[par[x][1]]);
                if (k <= allow) {
                    if (k & 1) {
                        x = par[x][0];
                        k = (k + 1) / 2;
                    } else {
                        x = par[x][1];
                        k = k / 2;
                    }
                } else {
                    k -= (allow / 2);
                    if (size[par[x][0]] < size[par[x][1]]) {
                        x = par[x][1];
                    } else {
                        x = par[x][0];
                    }
                }
            }
        }
        if(k > n || !flag) cout << "none" << "\n";
        else cout << k << "\n";
    }
    return 0;
}