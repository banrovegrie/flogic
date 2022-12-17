#include <bits/stdc++.h>
using namespace std;
#define int long long
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define pb push_back
#define endl "\n"
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;

int n;
int f[102][2][102], a[102][102];
bool visited[102][2][102];

const int mod = 998244353;

int solve(int x, int y, int i)
{
	if (visited[x][y][i])
	    return f[x][y][i];
	visited[x][y][i] = true;

	if (x == n + 1)
		return f[x][y][i] = 1 % mod;

	for (int k = 0; k < 2; k++)
	{
		int p, flag = false;
        if (y == k)
            p = i;
        else p = x - 1;

		for(int j = 1; j <= x; j++)
			if ((a[j][x] == 1 and p >= j) or (a[j][x] == 2 and p < j))
                flag = true;
		if (flag)
		    continue;

		f[x][y][i] += solve(x + 1, k, p);
        f[x][y][i] %= mod;
	}
	return f[x][y][i] % mod;
}


signed main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

    cin >> n;
    for(int i = 1; i<=n; i++)
		for (int j = i; j <= n; j++)
		    cin >> a[i][j];
	cout << solve(1, 0, 0) << endl;

    return 0;
}
