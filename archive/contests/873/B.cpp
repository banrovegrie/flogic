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

int f[(int)(2e5  + 5)];

signed main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	memset(f , -1 , sizeof(f));

	int n;
	cin >> n;

	string s;
	cin >> s;
	s = 'x' + s;

	int sum = n, ans = 0;
	f[sum] = 0;
	for (int i = 1; i <= n; i++) {
		if (s[i] == '1') sum++;
		else sum--;

		if (f[sum] != -1) ans = max(ans , i - (f[sum]));
		else f[sum] = i;
	}
	cout << ans << endl;
}
