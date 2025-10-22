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

int solve(int n, int x, int y) {
	int ans = 0;
	for (int i = 0; (1 << i) <= y; i++)
		if ((y & (1 << i)) and
			((n * y - (1 << i) & x - (1 << i)) == x - (1 << i)))
				ans ^= (1 << i);
	
	return ans;
}

signed main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	
	int n, x, y, ans = 0;
	cin >> n >>  x >> y;
	
	if (n % 2 == 0) {
		cout << 0 << endl;
		return 0;
	}

	for (int i = 1; i <= y; i++)
		if ((y & i) == i)
			ans ^= solve(n, x, i);

	cout << ans << endl;
	return 0;
}
