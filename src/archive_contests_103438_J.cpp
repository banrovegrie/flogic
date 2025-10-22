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

	int n, count = 0;
	cin >> n;
	string s;
	cin >> s;

	stack<int> q[2];
	vector<pii> ans;

	for (auto i: s)
		if (i == 'A') count++;

	count = n - count;
	if (count < 0) {
		cout << "NO" << endl;
		return 0;
	}

	for (int i = 0; i < 2 * n; i++) {
		if (s[i] == 'A')
			q[0].push(i);
		else if (s[i] == 'B') {
			if (count > 0) q[1].push(i), count--;
			else {
				if (q[0].empty()) {
					cout << "NO" << endl;
					return 0;
				}
				ans.push_back({q[0].top(), i}), q[0].pop();
 			}
		}
		else {
			if (q[0].empty() and q[1].empty()) {
				cout << "NO" << endl;
				return 0;
			}
			if (not q[1].empty())
				ans.push_back({q[1].top(), i}), q[1].pop();
			else
				ans.push_back({q[0].top(), i}), q[0].pop();
		}
	}

	cout << "YES" << endl;
	for (auto i: ans) {
		cout << i.first + 1 << " " << i.second + 1 << endl;
	}
}
