#include <iostream>
#include <vector>
#include <tuple>
#include <string>
#include <algorithm>
#include <numeric>
#define pb emplace_back
using namespace std;

int main() {
    ios_base::sync_with_stdio(0); 
    cin.tie(0);

    string c;
    int n, m, h; 
    cin >> n >> m >> h;
    vector<tuple<int, int, int>> mx;
    vector<tuple<int, int, int>> mn;
    vector<vector<int>> projection_front(n, vector<int>(m));
    vector<vector<int>> projection_left(n, vector<int>(h));

    for (int i = 0; i < n; ++i) {
        cin >> c;
        for (int j = 0; j < m; ++j) 
            projection_front[i][j] = (c[j] == '1');
    }
    for (int i = 0; i < n; ++i) {
        cin >> c;
        for (int j = 0; j < h; ++j) 
            projection_left[i][j] = (c[j] == '1');
    }

    for (int i = 0; i < n; ++i) {
        int front_sum = accumulate(projection_front[i].begin(), projection_front[i].end(), 0);
        int left_sum = accumulate(projection_left[i].begin(), projection_left[i].end(), 0);
        if (not(front_sum) and left_sum or front_sum and not(left_sum)) {
            cout << -1 << endl;
            return 0;
        }

        vector<int> front, left;
        for (int j = 0; j < m; ++j) if (projection_front[i][j]) front.pb(j);
        for (int k = 0; k < h; ++k) if (projection_left[i][k]) left.pb(k);

        for (int j : front) for (int k : left) mx.pb(i, j, k);
        for (int j = front.size() - 1, k = left.size() - 1; j >= 0 || k >= 0; --j, --k)
            mn.pb(i, front[max(0, j)], left[max(0, k)]);
    }

    sort(mx.begin(), mx.end());
    cout << mx.size() << endl;
    for (auto [i, j, k] : mx) 
        cout << i + 1 << ' ' << j + 1 << ' ' << k + 1 << '\n';

    sort(mn.begin(), mn.end());
    cout << mn.size() << endl;
    for (auto [i, j, k] : mn) 
        cout << i + 1 << ' ' << j + 1 << ' ' << k + 1 << '\n';
}
