#include <bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>		// uncomment before submission
//#include <ext/pb_ds/tree_policy.hpp>			// uncomment before submission
//using namespace __gnu_pbds;					// uncomment before submission
using namespace std;
//<---------------------------------------------------Template----------------------------------------------------------->
#define int long long
#define ll long long
#define double long double
// #define ld long double
const int INF = 1e18 + 7;
const int MAX = 1e1 + 7;
const int MOD = 1e9 + 7;
const double EPS = 1e-9;
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

vector<double> a(MAX), b(MAX), c(MAX), d(MAX), z(MAX);
int n = 0;

vector<double> add(vector<double> &x, vector<double> &y) 
{
    vector<double> z(n);
    for (int i = 0; i < n; i++)
        z[i] = x[i] + y[i];
    return z;
}

vector<double> subtract(vector<double> x, vector<double> y) 
{
    // vector<double> z(n);
    for (int i = 0; i < n; i++)
        z[i] = x[i] - y[i];
    return z;
}

vector<double> mul(vector<double> x, double s) 
{
    // vector<double> z(n);
    for (int i = 0; i < n; i++)
        z[i] = x[i] * s;
    return z;
}

double dot(vector<double> &x, vector<double> &y) 
{
    double z1 = 0;
    for (int i = 0; i < n; i++)
        z1 += x[i] * y[i];
    return z1;
}

double dist(vector<double> &x, vector<double> &y) 
{
    // cout << n << endl << endl;
    // for(auto c : x) cout << c << " " ;
    // cout << endl;
    // cout << "------" << endl;
    // for(auto c : y) cout << c << " " ;
    // cout << endl;
    // cout << "------" << endl;
    // auto v = subtract(x, y);
    // cout << n << " " << v.size() << endl;  
    // for(auto c : v) cout << c << " " ;
    // cout << endl;
    // cout << "------" << endl;
    // cout << dot(subtract(x, y), subtract(x, y)) << endl;
    return sqrt(dot(subtract(x, y), subtract(x, y)));
}

bool eq(double x, double y) 
{
    return abs(x - y) < EPS;
}

bool leq(double x, double y) 
{
    return (x - y < 0) or eq(x, y);
}

double dist(vector<double> &z, vector<double> &x, vector<double> &y) 
{
    vector<double> zx = subtract(z, x);
    vector<double> yx = subtract(y, x);

    if (eq(dot(yx, yx), 0.0))
        return INF;
    
    double s = dot(zx, yx) / dot(yx, yx);
    if (leq(0, s) and leq(s, 1))
    {
        yx = add(mul(yx, s), x);
        return dist(z, yx);
    }

    return 1e18;
}

double cross(pair<double, double> x, pair<double, double> y)
{
    return x.ff * y.ss - x.ss * y.ff;
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    while (t--)
    {
        cin >> n;
        double ans = INF;
        cout << fixed << setprecision(12);

        // input points
        for (int i = 0; i < n; i++)
            cin >> a[i];
        for (int i = 0; i < n; i++)
            cin >> b[i];
        for (int i = 0; i < n; i++)
            cin >> c[i];
        for (int i = 0; i < n; i++)
            cin >> d[i];

        // point distance
        
        ans = min(dist(a, c), dist(a, d));
        ans = min(ans, dist(b, c));
        ans = min(ans, dist(b, d));
        // cout << dist(a, c) << endl;
        // cout << dist(a, d) << endl;
        // cout << dist(b, c) << endl;
        // cout << dist(b, d) << endl;
        
        
        // point line distance
        ans = min(ans, dist(a, c, d));
        ans = min(ans, dist(b, c, d));
        ans = min(ans, dist(c, a, b));
        ans = min(ans, dist(d, a, b));
        // cout << ans << endl;

        // line line distance
        vector<double> ab = subtract(b, a);
        vector<double> cd = subtract(d, c);
        vector<double> ac = subtract(c, a);
        vector<double> bd = subtract(d, b);
        
        pair<double, double> x, y, z, p;
        x = {-dot(ab, ab), -dot(ab, cd)};
        y = {dot(cd, ab), dot(cd, cd)};
        z = {dot(ac, ab), dot(ac, cd)};

        if (not eq(cross(y, x), 0))
        {
            p = {(cross({-y.ff, -y.ss}, z) / cross(y, x)), (cross(x, z) / cross(y, x))};
            if (leq(0, p.ff) and leq(p.ff, 1) and leq(0, p.ss) and leq(p.ss, 1))
            {
                vector<double> s, t;
                s = add(a, mul(ab, p.ff));
                t = add(c, mul(cd, p.ss));
                ans = min(ans, dist(s, t));
            }
        }

        cout << ans << endl;
    }
    return 0;
}
