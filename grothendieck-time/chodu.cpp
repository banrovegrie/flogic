#include <bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>		// uncomment before submission
//#include <ext/pb_ds/tree_policy.hpp>			// uncomment before submission
//using namespace __gnu_pbds;					// uncomment before submission
using namespace std;
//<---------------------------------------------------Template----------------------------------------------------------->
#define int long long
#define ll long long
#define ld long double
const int INF = 1e18 + 7;
const int MAX = 1e5 + 7;
const int MOD = 1e9 + 7;
typedef pair<ll, ll> ii;
typedef vector<ll> vi;                  // Vector of long long
typedef vector<vi> vvi;                 // Vector of vi
typedef vector<ii> vii;                 // Vector of pairs
typedef vector<vii> vvii;               // Vector of Vector of pairs
typedef vector<bool> vb;                // Vector of bool
#define pq priority_queue               // Max heap (To convert to min heap, use negative sign before every value)
#define ff first                        // For pairs
#define ss second                       // For pairs
#define pb push_back                    // Push back to vector
#define mp make_pair                    // Makes pairs to be stored as pair
#define endl "\n"                       // Changes endl to \n
#define all(c) (c).begin(), (c).end()   // Mainly used by me in sorting
#define range(c, r) (c).begin(), (c).begin() + (r)                // Mainly used in sorting
#define present(c, x) ((c).find(x) != (c).end())                  // for sets, maps, multi-maps
#define cpresent(c, x) (find(all(c),x) != (c).end())              // for vectors
#define testcases(T) int (T); cin>>(T); while((T)--)              // inputing testcases
#define run(x, c) for((x)=(c).begin(); (x)!=(c).end(); (x)++)     // Mainly used by me for range based loops
// ordered_set adds two new functions to set - (set).find_by_order([kth element based on zero indexing]) and order_of_key()
// order_of_key returns number of elements less that parameter. If element exists, that order is its index
#define ordered_set tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update>
//<----------------------------------------------------------------------------------------------------------------------->

string s;
vvi dp;

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> s;
    dp.clear();
    dp.resize(s.length(), vi(8, 0));
    
    int ans = 0;
    for (int i = 0; i < s.length(); i++)
    {
        if (i > 0)
        {
            for (int j = 0; j < 8; j++)
                dp[i][j] = dp[i - 1][j] % MOD;
        }

        if (s[i] == 'c')
            dp[i][0]++;
        else if (i > 0)
        {
            if(s[i] == 'h')
                dp[i][1] += dp[i - 1][0];
            else if(s[i] == 'o')
                dp[i][2] += dp[i - 1][1];
            else if(s[i] == 'k')
                dp[i][3] += dp[i - 1][2];
            else if(s[i] == 'u')
                dp[i][4] += dp[i - 1][3];
            else if(s[i] == 'd')
                dp[i][5] += dp[i - 1][4];
            else if(s[i] == 'a')
                dp[i][6] += dp[i - 1][5];
            else if(s[i] == 'i')
                dp[i][7] += dp[i - 1][6];
        }
    }
    cout << dp[(int)s.length() - 1][7] % MOD << endl;
    return 0;
}
