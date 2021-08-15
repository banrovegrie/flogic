#include <algorithm>
#include <bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>		// uncomment before submission
//#include <ext/pb_ds/tree_policy.hpp>			// uncomment before submission
//using namespace __gnu_pbds;					// uncomment before submission
using namespace std;
//<---------------------------------------------------Template----------------------------------------------------------->
#define int long long
#define ll long long
#define double long double
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

int dist(ii x, ii y)
{
    return abs(x.ff - y.ff) + abs(x.ss - y.ss);
}

void show(ii x, ii y, ii z)
{
    cout << x.ff << " " << x.ss << endl;
    cout << y.ff << " " << y.ss << endl;
    cout << z.ff << " " << z.ss << endl;
}

// double Area(ii x0, ii x1, ii x2)
// {
//     double dArea = ((double)(x1.ff - x0.ff) * (x2.ss - x0.ss) 
//             - (double)(x2.ff - x0.ff) * (x1.ss - x0.ss)) / 2.0;
//     return (dArea > 0.0) ? dArea : -dArea;
// }

double Area(ii x0, ii x1, ii x2)
{
    double dArea = ((double)(x1.ff - x0.ff) * (x2.ss - x0.ss)) / 2.0;
    return dArea;
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    while (t--)
    {
        int d[3], d2[3];
        cin >> d[0] >> d[1] >> d[2];
        d2[0] = d[0], d2[1] = d[1], d2[2] = d[2];

        // Rectangle is not possible
        if ((d[0] + d[1] + d[2]) % 2 != 0)
        {
            cout << "NO" << endl;
            continue;
        }

        // Triangle inside a rectangle is possible
        sort(d, d + 3);
        
        double area = 0.0;
        ii X = {0, 0}, Y = {0, 0} , Z = {0, 0};
        do
        {
            // constant
            ii A = {1, 1};
            ii B = {1 + d[1], 1};
    
            // variable
            int x = (d[0] + d[1] - d[2]) / 2;
            int y = (d[0] - x);
            ii C = {x + 1, y + 1};

            if (x > 0 or y > 0)
            {
                if (Area(A, B, C) > area)
                    area = Area(A, B, C),
                    X = A, Y = B, Z = C;
            }
        }
        while(next_permutation(d, d + 3));

        if (X.ff == 0)
        {
            cout << "NO" << endl;
            continue;
        }

        cout << "YES" << endl;
        /* cout << area << endl; */
        if (dist(X, Y) == d2[0] and dist(Y, Z) == d2[1])
            show(X, Y, Z);
        else if (dist(X, Z) == d2[0] and dist(Z, Y) == d2[1])
            show(X, Z, Y);
        else if (dist(Y, X) == d2[0] and dist(X, Z) == d2[1])
            show(Y, X, Z);
        else if (dist(Y, Z) == d2[0] and dist(Z, X) == d2[1])
            show(Y, Z, X);
        else if (dist(Z, X) == d2[0] and dist(X, Y) == d2[1])
            show(Z, X, Y);
        else 
            show(Z, Y, X);
    }
    return 0;
}
