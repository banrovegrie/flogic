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

int n, m, k, ans = 0, res = 0, a[105][105] = {0};

int solve(int c) {
	vi arr;
	for (int i = 0; i < n; i++)
		arr.pb(a[i][c]);

	int x = 0, y = 0, sum = 0, prefix = 0;
	for (int i = 0; i < n; i++) {
		sum = 0;
		for (int j = 0; i + j < n and j < k; j++) 
			sum += arr[i + j];
		
		if (sum > x)
			x = sum, y = prefix;
		else if (sum == x and prefix < y)
			x = sum, y = prefix;

		prefix += arr[i];
	}
	ans += x, res += y;
	return 0;
}

signed main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	
	cin >> n >> m >> k;
 	for (int i = 0; i < n; i++)
    	for (int j = 0; j < m; j++)
      		cin >> a[i][j];
  	for (int j = 0; j < m; j++)
    	solve(j);

	cout << ans << " ";
	cout << res << "\n";
}
