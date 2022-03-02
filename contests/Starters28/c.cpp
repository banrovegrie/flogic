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
        int n, k;
        cin >> n >> k;
        string s;
        cin >> s;
        vector <string> seqs;
        string left = s;
        for(int jj = 0; jj < min(k - 1, (int)25); jj++){
            map <int, int> freq_before;
            map <int, int> freq_after;
            for(char c: s){
                freq_after[c] += 1;
            }
            left.clear();
            string current_seq;
            int min_char = (*freq_after.begin()).first;
            int min_before = 1e9;

            for(int i = 0; i < s.size(); i++){
                if (s[i] == min_char){
                    current_seq += min_char;
                } else {
                    left += s[i];
                    freq_before[s[i]] += 1;
                }
                freq_after[s[i]] -= 1;
                
                if (freq_after[s[i]] == 0){
                    freq_after.erase(s[i]);
                }
            
                if (freq_after.find(min_char) == freq_after.end()){
                    if (jj == k - 2){
                        // look at the first char of the left string
                        if (freq_before.size() == 0 and freq_after.size() == 0){
                            continue;
                        }

                        else if (freq_before.size() == 0){
                            int min_after = (*freq_after.begin()).first;
                            min_char = min_after;
                        } else if (freq_after.size() == 0){
                            break;
                        } else {
                            int min_after = (*freq_after.begin()).first;
                            int min_before = left[0];
                            if (min_before >= min_after){
                                min_char = min_after;
                                continue;
                            } else {
                                continue;
                            }
                        }
                    } else {
                    // no more min_char in string
                    if (freq_before.size() == 0 and freq_after.size() == 0) {
                        continue;
                    }
                    else if (freq_before.size() == 0) {
                        int min_after = (*freq_after.begin()).first;
                        min_char = min_after;
                        continue;
                    } else if (freq_after.size() == 0){
                        break;
                    } else {
                        int min_after = (*freq_after.begin()).first;
                        int min_before = (*freq_before.begin()).first;
                        if (min_before >= min_after){
                            min_char = min_after;
                            continue;
                        } else {
                            continue;
                        }
                    }
                    }
                }
            }
            seqs.push_back(current_seq);
            s = left;
        }
        seqs.pb(left);

        string anss;
        for (int i = 0; i < seqs.size(); i++){
            // cout << seqs[i] << endl;
            for (int x: seqs[i]){
                anss.push_back(x);
            }
        }
        cout << anss << endl;
    
    }
    return 0;
}




