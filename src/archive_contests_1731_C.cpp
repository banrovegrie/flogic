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
        vi arr(n + 1, 0);
		vi freq(4 * n + 1, 0);

        for (int i = 1; i <= n; i++) 
            cin >> arr[i];

        for (int i = 1; i <= n; i++)
			arr[i] ^= arr[i - 1];
		
		freq[0] = 1;
		int res = (n * (n + 1) / 2);
		for (int i = n; i > 0; i--) {
			for(int j = 0; j * j <= 2 * n; j++)
					res -= freq[(j * j) ^ arr[i]];
			freq[arr[i]]++;
		}

		cout << res << endl;
	}
}
