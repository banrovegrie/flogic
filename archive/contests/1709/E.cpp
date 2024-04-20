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

const int N = 2 * 1e5 + 7;
int XOR[N];
unordered_set<int> s[N];
int a[N];
int cnt = 0;
vector<int> g[N];

void dfs(int u, int p) {
	bool flag = false;
	s[u] = {XOR[u]};
	for (int v: g[u]) {
		if (v == p) continue;
		XOR[v] = XOR[u] ^ a[v];
		dfs(v, u);

		if (sz(s[u]) < sz(s[v])) swap(s[u], s[v]);
		
		for (int x: s[v])
			if (s[u].count(x ^ a[u]) > 0)
				flag = true;
		for (int x: s[v])
			s[u].insert(x);
	}

	if (flag) {
		cnt += 1;
		s[u].clear();
	}
}

signed main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
		cin >> a[i];

	for (int i = 0; i < n - 1; i++) {
		int x, y;
		cin >> x >> y;
		x--, y--;
		g[x].pb(y),	g[y].pb(x);
	}

	XOR[0] = a[0];
	dfs(0, -1);
	cout << cnt << endl;
}
