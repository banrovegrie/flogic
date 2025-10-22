#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cassert>
#include <cstring>
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

const int MOD = 998244353;

void solve() {
    int n;
    cin >> n;

    vi a(n, 0);
    int sum = 0, ans = 0;
    for (int &i : a) cin >> i, sum += i;

    vi dp(sum + 1);
    dp[0] = 1;

    for (int i = 0; i < n; i++)
        for (int j = sum - a[i]; j >= 0; j--) 
            dp[j + a[i]] = (dp[j + a[i]] + dp[j]) % MOD;

    for (int j = 0; j <= sum; j++) 
        ans = (ans + (((j + 1) / 2) * dp[j]) % MOD) % MOD;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < a[i]; j++) 
        ans = (ans + (((a[i] - (a[i] + j + 1) / 2 + MOD) % MOD) * dp[j]) % MOD) % MOD;
    cout << ans << endl;
}

signed main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

    solve();
}