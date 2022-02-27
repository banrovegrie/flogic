#include <bits/stdc++.h>
#include <unordered_set>
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

vi parent, sz;
vi parent2, sz2;

int find_set(int v) 
{
    if (v == parent[v])
        return v;
    return parent[v] = find_set(parent[v]);
}

void make_set(int v) 
{
    parent[v] = v;
    sz[v] = 1;
}

void union_sets(int a, int b) 
{
    a = find_set(a);
    b = find_set(b);
    if (a != b) {
        if (sz[a] < sz[b])
            swap(a, b);
        parent[b] = a;
        sz[a] += sz[b];
    }
}

int find_set2(int v) 
{
    if (v == parent2[v])
        return v;
    return parent2[v] = find_set2(parent2[v]);
}

void make_set2(int v) 
{
    parent2[v] = v;
    sz2[v] = 1;
}

void union_sets2(int a, int b) 
{
    a = find_set2(a);
    b = find_set2(b);
    if (a != b) {
        if (sz2[a] < sz2[b])
            swap(a, b);
        parent2[b] = a;
        sz2[a] += sz2[b];
    }
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, m1, m2;
    cin >> n >> m1 >> m2;
    
    parent.resize(n + 5), sz.resize(n + 5);
    parent2.resize(n + 5), sz2.resize(n + 5);
    for (int i = 1; i <= n; i++)
        make_set(i), make_set2(i);

    for (int i = 0; i < m1; i++)
    {
        int x, y;
        cin >> x >> y;
        union_sets(x, y);
    }
    
    for (int i = 0; i < m2; i++)
    {
        int x, y;
        cin >> x >> y;
        union_sets2(x, y);
    }

    // unique parents
    /* unordered_set<int> p, p1; */
    /* for (int i = 1; i <= n; i++) */
        /* p.insert(i), p1.insert(i); */

    int ans = 0;
    vii edges;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (find_set(i) != find_set(j) and find_set2(i) != find_set2(j))
            {
                /* cout << i << " " << j << endl; */
                ans++;
                edges.pb({i, j});
                union_sets(i, j), union_sets2(i, j);
            }
        }
    }
    /* cout << endl; */

    cout << ans << endl;
    for (int i = 0; i < ans; i++)
        cout << edges[i].ff << " " << edges[i].ss << endl;
    return 0;
}
