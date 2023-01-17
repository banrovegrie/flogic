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

int n, m, check = 0, ans[(int)(1e5 + 5)] = {0};

int solve(int l,int r,int val)
{
	if (l == r - 1) {
		ans[l] = val; 
		return 0;
	}

	if (check) {
		int mid = (l + r) / 2;
		check--;

		solve(l, mid, val + r - mid);
		solve(mid, r, val);
	}
	else {
		for (int i = 0; i < r - l; i++) 
			ans[l + i] = val + i;
	}

	return 0;
}

signed main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	
	cin >> n >> m;
    
	if (m % 2 == 0 or m > 2 * n - 1) {
		cout << -1 << endl;
		return 0;
	}

    check = (m - 1) / 2, solve(0, n, 1);

	for (int i = 0; i < n; i++) cout << ans[i] << " ";
	cout << endl;
    return 0;
}
