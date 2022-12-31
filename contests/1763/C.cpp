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

signed main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		
		vi arr(n);
		for (int i = 0; i < n; i++)
			cin >> arr[i];
			
		if (n >= 4)
			cout << 1ll * (*max_element(all(arr))) * n << endl;
		else if (n == 2)
			cout << max(arr[0] + arr[1], 2ll * abs(arr[0] - arr[1])) << endl;
		else if (n == 3) {
			if (*max_element(all(arr)) == arr[0] or *max_element(all(arr)) == arr[n - 1])
				cout << 1ll * (*max_element(all(arr))) * n << endl;
			else {
				sort(all(arr));
				int ans = arr[0] + arr[1] + arr[2];
				ans = max(ans, 2ll * abs(arr[2] - arr[0]) + arr[1]);
				ans = max(ans, 3ll * (abs(arr[1] - (arr[2]- arr[0]))));
				ans = max(ans, 3ll * (arr[2] - arr[0]));
				ans = max(ans, 3ll * (arr[1]));
				cout << ans << endl;
			}
			continue;
		}
	}
}
