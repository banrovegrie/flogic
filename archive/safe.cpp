#include <bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>		// uncomment before submission
//#include <ext/pb_ds/tree_policy.hpp>			// uncomment before submission
//using namespace __gnu_pbds;					// uncomment before submission
using namespace std;
//<---------------------------------------------------Template----------------------------------------------------------->
#define int long long
#define ll long long
#define ld long double
const ld MIN = 1e-6;
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

ld x, y;
int n;
vector<pair<ld, ld> > point;
vector<int> parent;

int find(int x)
{
    if (parent[x] != x) 
        return parent[x] = find(parent[x]);
    return parent[x];
}

void change(int x, int y)
{
    if (x != y)
        parent[x] = y;
}

ld d(pair<ld, ld> x, pair<ld, ld> y)
{
    return sqrt((x.ff - y.ff) * (x.ff - y.ff) 
        + (x.ss - y.ss) * (x.ss - y.ss)
    );
}

bool f(ld val)
{
    int v, w;
    for (int i = 1; i <= n + 4; i++)
        parent[i] = i;

    for (int i = 1; i <= n; i++)
    {
        if (point[i].ff < val)
            change(find(i), find(n + 4));
        if (point[i].ss < val)
            change(find(i), find(n + 3));
        if (x - point[i].ff < val)
            change(find(i), find(n + 2));
        if (y - point[i].ss < val)
            change(find(i), find(n + 1));

        for(int j = i + 1; j <= n ; j++)
        {
            ld dist = d(point[i], point[j]);
            if (dist < 2 * val)
                change(find(j), find(i));
        }
    }
    if (find(n + 1) != find(n + 2) 
        and find(n + 1) != find(n + 3) 
        and find(n + 3) != find(n + 4) 
        and find(n + 2) != find(n + 4)
    ) 
        return true;
    return false;
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> x >> y >> n;
    point.resize(n + 15);
    parent.resize(n + 15); 

    for (int i = 1; i <= n; i++)
        cin >> point[i].ff >> point[i].ss;
    
    ld start = 0, end = max(x, y), mid;
    while (end - start >= MIN)
    {
        mid = (start + end) / 2;
        if (f(mid))
            start = mid;
        else
            end = mid;
    }

    cout << fixed << setprecision(9) << start << endl;
    return 0;
}
