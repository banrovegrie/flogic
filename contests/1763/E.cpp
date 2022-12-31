#include <bits/stdc++.h>
using namespace std;
#define int long long
#define MAX LLONG_MAX
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

	int p;
	cin >> p;

	vi f(p + 1, MAX);
	f[1] = 2, f[0] = 0;
	
	for (int i = 2, j = 2; i <= p; i++)
	{
		j = 2;
		while (true) {
			int check = j * (j - 1) / 2ll;
			if (check > i)
				break;
			f[i] = min(f[i], f[i - check] + j),
			j++;
		}
	}
	
	cout << f[p] << " " << f[p] * (f[p] - 1) / 2ll - p << endl;
	return 0;
}
