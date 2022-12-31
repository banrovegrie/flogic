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
typedef vector<vi> vvi;

int n, m;
vvi grid;

vi get_arr(vi &arr, int val) {
    vi temp;
    deque<int> q;

    for (int i = 0; i < arr.size(); i++) {
        if (q.size() > 0 and q.front() == i - val) 
            q.pop_front();

        while (q.size() > 0 and arr[q.back()] >= arr[i]) 
            q.pop_back();
        q.pb(i);
        
        if (i + 1 >= val) 
            temp.pb(arr[q.front()]);
    }

    return temp;
}

bool solve(int val) {
    vvi matrix(n, vi(m + 1 - val));
    for (int i = 0; i < n; i++)
        matrix[i] = get_arr(grid[i], val);

    for (int j = 0; j <= m - val; j++) {
        vi arr(n);
        for(int i = 0, k = 0; i < n; i++)
            arr[k++] = matrix[i][j];
        
        arr = get_arr(arr, val);
        for(auto x: arr)
            if(x >= val) 
                return true;
    }
    return false;
}

signed main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

    int t;
    cin >> t;
    while (t--) {
        cin >> n >> m;
        grid.clear();
        grid.resize(n, vi(m));

        for (int i = 0; i < n; i++) 
            for (int j = 0; j < m; j++) 
                cin >> grid[i][j];

        int start = 1, end = min(n, m);
        while (start < end - 1) {
            int mid = (start + end) / 2;
            if (solve(mid)) 
                start = mid;
            else 
                end = mid;
        }

        if (solve(end)) 
            cout << end << endl;
        else 
            cout << start << endl;
    }
}
