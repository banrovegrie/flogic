#include <bits/stdc++.h>
#include <cstdlib>
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
typedef pair<ll, ll> point;
typedef vector<ll> vi;                  // Vector of long long
typedef vector<vi> vvi;                 // Vector of vi
typedef vector<point> vii;                 // Vector of pairs
typedef vector<vii> vvii;               // Vector of Vector of pairs
typedef vector<bool> vb;                // Vector of bool
#define pq priority_queue               // Max heap (To convert to min heap, use negative sign before every value)
#define x first                        // For pairs
#define y second                       // For pairs
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

// struct point
// {
    // int x;
    // int y;
// };

bool cmp1(point a, point b)
{
    if (a.x == b.x)
        return a.y < b.y;
    else
        return a.x < b.x;
}

bool cmp2(point a, point b)
{
    if (a.y == b.y)
        return a.x < b.x;
    else
        return a.y < b.y;
}

int area(point up, point down, point left, point right)
{
    cout << up.x << "," << up.y << " " << down.x << "," << down.y << endl;
    cout << left.x << "," << left.y << " " << right.x << "," << right.y << endl;
    
    int ret = abs(up.y - down.y) * abs(left.x - right.x);
    cout << ret << endl;
    return ret;
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    while (t--)
    {
        // Inputs
        int n;
        cin >> n;

        vector<point> p_s(n), sorted_x(n), sorted_y(n);
        
        map<point, point> left_high, left_low, right_high, right_low;
        map<point, point> up_r, up_l, down_r, down_l; 
        
        for (int i = 0; i < n; i++)
        {
            cin >> p_s[i].x >> p_s[i].y;
            sorted_x.pb({p_s[i].x, p_s[i].y});
            sorted_y.pb({p_s[i].x, p_s[i].y});
        }
        
        // Sort the points
        sort(sorted_x.begin(), sorted_x.end(), cmp1);
        sort(sorted_y.begin(), sorted_y.end(), cmp2);
        
        left_low[sorted_x[0]] = sorted_x[0];
        left_high[sorted_x[0]] = sorted_x[0];
        for (int i = 1; i < n; i++)
        {
            if (left_high[sorted_x[i - 1]].y > sorted_x[i].y)
                left_high[sorted_x[i]] = left_high[sorted_x[i - 1]];
            else
                left_high[sorted_x[i]] = sorted_x[i];

            if (left_low[sorted_x[i - 1]].y < sorted_x[i].y)
                left_low[sorted_x[i]] = left_low[sorted_x[i - 1]];
            else
                left_low[sorted_x[i]] = sorted_x[i]; 
        }   


        right_low[sorted_x[n - 1]] = sorted_x[n - 1];
        right_high[sorted_x[n - 1]] = sorted_x[n - 1];
        for (int i = n - 2; i >= 0; i--)
        {
            if (right_high[sorted_x[i + 1]].y > sorted_x[i].y)
                right_high[sorted_x[i]] = right_high[sorted_x[i + 1]];
            else
                right_high[sorted_x[i]] = sorted_x[i];

            if (right_low[sorted_x[i + 1]].y < sorted_x[i].y)
                right_low[sorted_x[i]] = right_low[sorted_x[i + 1]];
            else
                right_low[sorted_x[i]] = sorted_x[i]; 
        }   

        down_r[sorted_y[0]] = sorted_y[0];
        down_l[sorted_y[0]] = sorted_y[0];
        for (int i = 1; i < n; i++)
        {
            if (down_r[sorted_y[i - 1]].x > sorted_y[i].x)
                down_r[sorted_y[i]] = down_r[sorted_y[i - 1]];
            else
                down_r[sorted_y[i]] = sorted_y[i];

            if (down_l[sorted_y[i - 1]].x < sorted_y[i].x)
                down_l[sorted_y[i]] = down_l[sorted_y[i - 1]];
            else
                down_l[sorted_y[i]] = sorted_y[i]; 
        }   
        
        up_r[sorted_y[n - 1]] = sorted_y[n - 1];
        up_l[sorted_y[n - 1]] = sorted_y[n - 1];
        for (int i = n - 2; i >= 0; i--)
        {
            if (up_r[sorted_y[i + 1]].x > sorted_y[i].x)
                up_r[sorted_y[i]] = up_r[sorted_y[i + 1]];
            else
                up_r[sorted_y[i]] = sorted_y[i];

            if (up_l[sorted_y[i + 1]].x < sorted_y[i].x)
                up_l[sorted_y[i]] = up_l[sorted_y[i + 1]];
            else
                up_l[sorted_y[i]] = sorted_y[i]; 
        }   
        
        // Look for the first point
        point left, right, up, down; 
        int ans = -1;

        for (auto p: p_s)
        {
            int sum = 0;

            // Left-Right 
            right = p;
            left = sorted_x[0];
            up = left_high[p];
            down = left_low[p];
            sum = area(up, down, left, right);

            auto it = (upper_bound(sorted_x.begin(), sorted_x.end(), p));
            if (it == sorted_x.end())
                left = p;
            else 
                left = *it;
            right = sorted_x[n - 1];
            up = right_high[left];
            down = right_low[left];
            sum += area(up, down, left, right);
                
            if (ans == -1)
                ans = sum;

            ans = min(ans, sum);

            // Up-Down
            up = p;
            down = sorted_y[0];
            right = down_r[p];
            left = down_l[p];
            sum = area(up, down, left, right);

            it = upper_bound(sorted_y.begin(), sorted_y.end(), p);
            if (it == sorted_y.end())
                down = p;
            else 
                down = *it;
            up = sorted_y[n - 1];
            left = up_l[p];
            right = up_r[p];
            sum += area(up, down, left, right);

            ans = min(ans, sum);
        }

        cout << ans << endl;
    }
    return 0;
}
