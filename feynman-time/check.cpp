thodi derr mai aata
Amul — Today at 3:37 PM
lets go
Amul — Today at 8:15 PM
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
#define ll long long int
Expand
message.txt
4 KB
﻿
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
#define ll long long int
#define ld long double
#define ordered_set tree < ll ,  null_type ,  less<ll> ,  rb_tree_tag ,  tree_order_statistics_node_update >
//added two more functions to set
//(1)*(set.find_by_order(k))[kth element in the sorted set] 
//(2)set.order_of_key(k)[count of elements strictly less than k]

// Uncomment when using kactl templates and change typedef of pair
// #define rep(i, a, b) for(int i = a; i < (b); ++i)
// #define sz(x) (int)(x).size()
// typedef pair<int, int> pii;

typedef vector< int > vi;
typedef vector<long long> lvi;
typedef vector< vector<int> > vvi;
typedef vector< vector<long long> > lvvi;
typedef pair< int,int > ii;
typedef pair< long long,long long > lii;
typedef vector<pair<int,int>> vii;
typedef vector<pair<long long,long long>> lvii;
typedef vector<vector<pair<int,int>>> vvii;
typedef vector<vector<pair<long long,long long>>> lvvii;
typedef vector<bool> vb;

mt19937 rng((unsigned int) chrono::steady_clock::now().time_since_epoch().count());
// usage: x = rng() % k; shuffle(all(v), rng);

#define all(c) (c).begin(),(c).end()
#define tc(t) int (t); cin>>(t);while((t)--)
#define ff first
#define pb push_back
#define ss second
#ifdef ONLINE_JUDGE
    #define error(args...) 0
#else
    #define error(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }
#endif
void err(istream_iterator<string> it) {}
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
    cerr <<"[ "<< *it << " = " << a << " ]"<< endl;
    err(++it, args...);
}

//-----------------------------------------------------------------------------------------------------------------------------------------------------------------
const long long mod = 1e9 + 7;
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------

long long mos() { return 0LL; }
template<typename T, typename... Args>
T mos(T a, Args... args) { return ((a + mos(args...))%mod + mod)%mod; }

long long mop() { return 1LL; }
template<typename T, typename... Args>
T mop(T a, Args... args) { return (a*mop(args...))%mod; }
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------



signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);    
    tc(T)
    {
        ll n, x;
        cin >> n >> x;
        ll sol = 0;
        while(n > x and n > 1)
        {
            sol += 1;
            for(int j = 32; j >= 0; j--)
            {
                if((n>>j)&1) {
                    n -= (1LL << j);
                    break;
                }
            }
        }
        if(n > x) cout << -1 << endl;
        else if(n == 0) cout << sol << endl;
        else {
            ++sol;
            cout << sol << endl;
        }
    }
    return 0;
}    


// WA
// 1. overflow
// 2. re-initialize global variables for every test case.
// 3. edge cases like n=1

// Run time error
// 1. division by zero.
// 2. array bounds.

// TLE
// 1. uncomment that #define endl '\n' line
