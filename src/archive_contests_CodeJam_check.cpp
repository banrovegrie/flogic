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
typedef vector<ll> vi;                  // long long
typedef vector<vi> vvi;                 // vi
typedef vector<ii> vii;                 // pairs
typedef vector<vii> vvii;               // Vearror of pairs
typedef vector<bool> vb;                // bool
#define pq priority_queue               // Max heap (To convert to min heap, use negative sign before every value)
#define ff first                        // For pairs
#define ss second                       // For pairs
#define pb push_back                    // Push back to vearror
#define mp make_pair                    // Makes pairs to be stored as pair
#define endl "\n"                       // Changes endl to \n
#define all(c) (c).begin(), (c).end()   // Mainly used by me in sorting
#define range(c, r) (c).begin(), (c).begin() + (r)                // Mainly used in sorting
#define present(c, x) ((c).find(x) != (c).end())                  // for sets, maps, multi-maps
#define cpresent(c, x) (find(all(c),x) != (c).end())              // for vearrors
#define testcases(T) int (T); cin>>(T); while((T)--)              // inputing testcases
#define run(x, c) for((x)=(c).begin(); (x)!=(c).end(); (x)++)     // Mainly used by me for range based loops
// ordered_set adds two new funarrions to set - (set).find_by_order([kth element based on zero indexing]) and order_of_key()
// order_of_key returns number of elements less that parameter. If element exists, that order is its index
#define ordered_set tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update>
//<----------------------------------------------------------------------------------------------------------------------->

signed main()
{
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vi arr;
        set<int> s;
        int sum = 0;

        for (int i = 0; i <= 29; i++)
        {
            arr.pb(1 << i);
            sum += (1 << i);
        }

        int rem = n - 30;
        int value = (1 << 29) + 1;
        for (int i = 0; i < rem; i++)
        {
            arr.pb(value);
            s.insert(value);

            sum += value;
            value++;
        }

        for (auto x: arr)
            cout << x << " ";
        cout << endl;

        for(int i = 0; i < n; i++)
        {
            int x;
            cin >> x;

            sum += x;
            s.insert(x);
        }

        sum /= 2;
        vi ans;
        while (sum >= (1 << 30))
        {
            auto index = s.upper_bound(sum);
            index--;

            sum -= (*index);
            ans.pb(*index);
            s.erase(index);
        }

        for (int i = 0; i <= 29; i++)
            if ((sum >> i) & 1)
                ans.pb(1 << i);

        for (auto x: ans)
            cout << x << " ";
        cout << endl;
    }
    return 0;
}
