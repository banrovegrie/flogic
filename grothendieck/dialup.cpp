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

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, m;
    cin >> n >> m;
    
    // inputs
    bool f0 = false, f1 = false;
    bool g0 = false, g1 = false; 
    vi s(n), t(m);
    for (int &i: s)
    {
        cin >> i;
        if (i == 0)
            f0 = true;
        else
            f1 = true;
    }
    for (int &i: t)
    {
        cin >> i;
        if (i == 0)
            g0 = true;
        else
            g1 = true;
    }
    
    // check impossibility
    if ((g0 and !f0) or (g1 and !f1))
    {
        cout << -1 << endl;
        return 0;
    }

    // find answer
    int ans = 0, mn = INF;
    bool flag = true;
  
    for (int i = 0; i < n; i++)
    {
        if (s[i] != s[0])
            mn = min(mn, min(i, n - i));
    }

    for (int i = 0; i < m; i++)
    {
        if (t[i] == s[0])
            ans += 1;
        else
        {
            if (flag)
                ans += mn + 1, flag = false;
            else
                ans += 2;
            s[0] = t[i];
        }
    }

    cout << ans << endl;
    return 0;
}
