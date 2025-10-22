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
const int MAX = 1e6 + 7;
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

unordered_map<int, int> ump[MAX]; 

vector<int> parse(string s) 
{
    int num = 0;
    vector<int> ret;

    for(int i = 0; i < s.size(); i++) 
    {
       if (i == s.length() - 1)
        { 
            num = (num * 10 + (s[i + 1] - '0'));
            ret.push_back(num); 
            num = 0; 
        } 
        else if (s[i] == ' ')
        {  
            ret.pb(num); 
            num = 0; 
        }
        else num = (num * 10 + (s[i + 1] - '0'));
    }
    return ret;
}

vector<int> parse2(string s) 
{
    int num = 0;
    vector<int> ret;

    for(int i = 0; i < s.size(); i++) 
    {
        if (i == s.length() - 1)
        { 
            num = (num * 10 + (s[i + 1] - '0'));
            ump[i][num] = ret.size(); 
            
            ret.push_back(num); 
            num = 0; 
        } 
        else if (s[i] == ' ')
        { 
            ump[i][num] = ret.size(); 
            
            ret.pb(num); 
            num = 0; 
        }
        else num = (num * 10 + (s[i + 1] - '0'));
    }
    return ret;
}

int pref[MAX]; 
priority_queue<int> q[MAX]; 
queue<int> l;
int n, m;
vi capacity(MAX);
vvi cpref(MAX), rpref(MAX);
string s;

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n >> m;
    
    for (int i = 1; i <= m; i++)
        cin >> capacity[i];

    getchar();
    for (int i = 1; i <= n; i++)
    {
        getline(cin, s);
        cpref[i] = parse(s);
    }
    for (int i = 1; i <= m; i++)
    {
        getline(cin, s);
        rpref[i] = parse2(s);
    }

    for(int i = 1; i <= n; i++) 
        l.push(i); 

    while (!l.empty())
    { 
        int s = l.front(); 
        l.pop();

        if (pref[s] == cpref[s].size()) 
            continue;

        int x = cpref[s][pref[s]]; 
        q[x].push(ump[x][s]); 
        
        while(q[x].size() > capacity[x])
        { 
            int y = rpref[x][q[x].top()]; 
            q[x].pop(); 
            pref[y]++; 
            l.push(y); 
        } 
    } 
    
    for (int i = 1; i <= n; i++) 
        if (pref[i] < (int)cpref[i].size()) 
            cout << i << endl; 
    return 0;
}
