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

signed main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	int t;
	cin >> t;
	while (t--) {
		pii a[3];
		for (pii& point: a)
			cin >> point.first >> point.second;
		
		bool flag = false;
		for (int i = 0; i < 3; i++) {
			int x = a[i].first;
			int y = a[i].second;

			if (x > min(a[(i + 1) % 3].first, a[(i + 2) % 3].first)
				and x < max(a[(i + 1) % 3].first, a[(i + 2) % 3].first)) {
				flag = true;
				break;
			}
			else if (y > min(a[(i + 1) % 3].second, a[(i + 2) % 3].second)
				and y < max(a[(i + 1) % 3].second, a[(i + 2) % 3].second)) {
				flag = true;
				break;
			}
		}

		if (flag)
			cout << "YES\n";
		else cout << "NO\n";
	}
}
