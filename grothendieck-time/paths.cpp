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

vvi g;

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    g.clear();
    g.resize(n + 5);

    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        g[x].pb(y);
        g[y].pb(x);
    }

    
    queue<int> q;
    vector<bool> used(n + 5);
    vi dicks(n + 5), cunt(n + 5, 0);

    q.push(1);
    used[1] = true;
    cunt[1] = 1;
    
    while (!q.empty()) 
    {
        int u = q.front();
        q.pop();
        for (int v : g[u]) 
        {
            if (!used[v]) 
            {
                used[v] = true;
                q.push(v);
                dicks[v] = dicks[u] + 1;
                cunt[v] = cunt[u] % MOD;
            }
            else if (dicks[v] == dicks[u] + 1)
            {
                cunt[v] = (cunt[v] + cunt[u]) % MOD;
            }
        }
    }
    
    cout << cunt[n] << endl;
    return 0;
}
