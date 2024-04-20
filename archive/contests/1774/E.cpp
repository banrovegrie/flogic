#include <bits/stdc++.h>
using namespace std;
#define int long long
#define MAX (int)(2e5 + 5)
#define endl '\n'
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define pb push_back
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;

int n, d, ans = 0;
int visited[2][MAX];
int dp[2][MAX];
vi path;
vvi g(MAX);

void get_dp(int u, int parent) {
	dp[0][u] = visited[0][u],
    dp[1][u] = visited[1][u];
	
    for (auto v: g[u])
		if (v != parent)
            get_dp(v, u),
            dp[0][u] += dp[0][v],
            dp[1][u] += dp[1][v];
}

void get_path(int u, int parent, int type) {
	path.push_back(u);
    int sz = path.size();

	if(sz >= d + 1)
		visited[1 - type][path[sz - (d + 1)]] = 1;

	for (auto v: g[u])
		if (v != parent and dp[type][v])
		    get_path(v, u, type);
	path.pop_back();
}

void dfs(int u, int parent, int type) {
	for (auto v: g[u])
		if (v != parent and dp[type][v])		
            ans += 2,
            dfs(v, u, type);
}


signed main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

    int x, y;
    cin >> n >> d;
	for (int i = 0; i < n - 1; i++)
		cin >> x >> y, 
        g[x].push_back(y), g[y].push_back(x);

    int m1, m2;
    cin >> m1;
    for (int i = 0; i < m1; i++)
        cin >> x,
        visited[0][x] = 1;
    cin >> m2;
    for (int i = 0; i < m2; i++)
        cin >> x,
        visited[1][x] = 1;
		
	get_dp(1, 0);
	get_path(1, 0, 0);
	
    get_path(1, 0, 1);
    get_dp(1, 0);
	
    dfs(1, 0, 1);
	dfs(1, 0, 0);
	cout << ans << endl;
}
