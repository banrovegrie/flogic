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
const int MOD = 998244353;
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

void solve(double a, double b, double c, double d, 
    double& x1_real, double& x2_real, double& x3_real, 
    double& x2_imag, double& x3_imag
) 
{
    b /= a;
    c /= a;
    d /= a;
    
    double disc, q, r, dum1, s, t, term1, r13;
    q = (3.0*c - (b*b))/9.0;
    r = -(27.0*d) + b*(9.0*c - 2.0*(b*b));
    r /= 54.0;
    disc = q*q*q + r*r;
    term1 = (b/3.0);

    if (disc > 0)
    {
        s = r + sqrt(disc);
        s = s<0 ? -cbrt(-s) : cbrt(s);
        t = r - sqrt(disc);
        t = t<0 ? -cbrt(-t) : cbrt(t);
        x1_real = -term1 + s + t;
        term1 += (s + t)/2.0;
        x3_real = x2_real = -term1;
        term1 = sqrt(3.0)*(-t + s)/2;
        x2_imag = term1;
        x3_imag = -term1;
    }
    else if (disc == 0)
    { 
        x3_imag = x2_imag = 0;
        r13 = r<0 ? -cbrt(-r) : cbrt(r);
        x1_real = -term1 + 2.0*r13;
        x3_real = x2_real = -(r13 + term1);
    }
    else
    {
        x3_imag = x2_imag = 0;
        q = -q;
        dum1 = q*q*q;
        dum1 = acos(r/sqrt(dum1));
        r13 = 2.0*sqrt(q);
        x1_real = -term1 + r13*cos(dum1/3.0);
        x2_real = -term1 + r13*cos((dum1 + 2.0*M_PI)/3.0);
        x3_real = -term1 + r13*cos((dum1 + 4.0*M_PI)/3.0);
    }
    
    cout << "\nRoots:" << endl <<
            "  x = " << x1_real << endl <<
            "  x = " << x2_real << " + i" << x2_imag << endl <<
            "  x = " << x3_real << " + i" << x3_imag << endl;
}

long double* cmul(long double* sq1, long double* sq2)
{
    long double* ans = new long double[2];
 
    // For real part
    ans[0] = (sq1[0] * sq2[0]) - (sq1[1] * sq2[1]);
 
    // For imaginary part
    ans[1] = (sq1[1] * sq2[0]) + sq1[0] * sq2[1];
 
    return ans;
}
 

long double* power(long double* x, int n)
{
    long double* ans = new long double[2];
    if (n == 0) {
        ans[0] = 0;
        ans[1] = 0;
        return ans;
    }
    if (n == 1)
        return x;
 
    long double* sq = power(x, n / 2);
    if (n % 2 == 0)
        return cmul(sq, sq);
    return cmul(x, cmul(sq, sq));
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, m;
    cin >> n >> m;
    int s, t, u;
    cin >> s >> t >> u;

    double x1_real, x2_real, x3_real;
    double x2_imag, x3_imag;

    solve(1.0, s, t, u, x1_real, x2_real, x3_real, x2_imag, x3_imag);

    double* a = new double[2];
    double* b = new double[2];
    double* c = new double[2];

    a[0] = x1_real, a[1] = 0.0;
    b[0] = x2_real, a[1] = x2_imag;
    c[0] = x3_real, c[1] = x3_imag;


    return 0;
}
