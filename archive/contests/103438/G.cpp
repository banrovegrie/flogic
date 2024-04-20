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

bool cmp(pair<pair<int, int>, int> l, pair<pair<int, int>, int> r) {
	return l.second < r.second;
}

signed main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	int n, sum = 0;
	cin >> n;

	vector<pair<pair<int, int>, int>> a;
	for (int i = 1; i <= 2 * n; i++) {
		int x, y;
		cin >> x >> y;
		a.push_back({{min(x, y), max(x, y)}, x + y});
	}

	sort(all(a), cmp);
	// for (int i = 0; i < 2 * n; i++)
	// 	cout << "(" << a[i].first.first << " " << a[i].first.second << "), ";
	// cout << endl;

	for (int i = 0; i < n; i++)
		sum -= a[i].first.first;
	for (int i = n; i < 2 * n; i++)
		sum += a[i].first.second;
	cout << sum << endl;
}
