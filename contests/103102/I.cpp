#include <bits/stdc++.h>
using namespace std;
#define int long long
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define pb push_back
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int mod = 1e9 + 7;
int dp[(int)(1e6 + 5)];

signed main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	int n;
	cin >> n;

	if (n == 1) {
		cout << "1\n";
		return 0;
	}
	else if (n == 2) {
		cout << "2\n";
		return 0;
	}
	else if (n == 3) {
		cout << "6\n";
		return 0;
	}

	dp[n] = 1;
	for (int i = n - 1; i > 3; i--) {
		dp[i] = 1;
		for (int j = i - 1; j <= n; j += i - 1)
			for (int k = j; k <= j + 2; k++)
				if (i + 1 <= k) 
					dp[i] = (dp[i] + dp[k]) % mod;
	}

	int ans = (((4 * dp[4]) % mod) * n) % mod;
	cout << ans << "\n";
	return 0;
}
