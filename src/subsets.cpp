#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll arr[1002];
ll DP[1002][1002];
ll DP2[1002][1002];

ll MOD = 1e9 + 7;

int main()
{
    ll n, k;
    cin >> n >> k;

    vector<ll> even, odd;
    even.push_back(-1), odd.push_back(-1); 
    for (ll i = 1; i <= n; i++)
    {
        cin >> arr[i];
        if (arr[i] % 2)
            odd.push_back(arr[i] % MOD);
        else
            even.push_back(arr[i] % MOD);
    }

    // even
    DP[0][0] = 1;
    for(ll i = 1; i <= even.size(); i++)
    {
        DP[i][0] = 1;
        for(ll j = 1; j <= i && j <= k; j++)
        {
            DP[i][j] = (DP[i - 1][j] + (DP[i - 1][j - 1] * even[i]) % MOD) % MOD;
        }
    }

    // odd
    DP2[0][0] = 1;
    for(ll i = 1; i <= odd.size(); i++)
    {
        DP2[i][0] = 1;
        for(ll j = 1; j <= i && j <= k; j++)
        {
            DP2[i][j] = (DP2[i - 1][j] + (DP2[i - 1][j - 1] * odd[i]) % MOD) % MOD;
        }
    }

    ll ans = 0;
    for (ll i = 0; i <= k; i += 2)
        ans += DP2[(ll)odd.size()][i] * DP[(ll)even.size()][k - i], ans %= MOD;

    cout << ans << endl;
    return 0;
}
