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
    
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        string s;
        cin >> s;

        int ans1 = 0, ans2 = 0;
        if (s[0] != '?')
        {
            string x = s;
            for (int i = 0; i < n; i++)
            {
                if (x[i] == '?')
                {
                    if (x[i - 1] == 'R')
                        x[i] = 'B';
                    else
                        x[i] = 'R';
                }
            }
            cout << x << endl;
            continue;
        }
        
        // starts with B
        string x = s, y = s;
        x[0] = 'B', y[0] = 'R';
        for (int i = 0; i < n; i++)
        {
            if (x[i] == '?')
            {
                if (x[i - 1] == 'R')
                    x[i] = 'B';
                else
                    x[i] = 'R';
            }
        }
        
        // starts with R
        for (int i = 0; i < n; i++)
        {
            if (y[i] == '?')
            {
                if (y[i - 1] == 'R')
                    y[i] = 'B';
                else
                    y[i] = 'R';
            }
        }

        for (int i = 1; i < n; i++)
        {
            ans1 += (x[i] == x[i - 1])? 1 : 0;
            ans2 += (y[i] == y[i - 1])? 1 : 0;
        }
        
        if (ans1 <= ans2)
            cout << x << endl;
        else
            cout << y << endl;
    }
    return 0;
}
