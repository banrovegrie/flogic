#include<iostream>
#include<vector>
#include <algorithm>
using namespace std;
#define int long long int 

signed main()
{
    int T;
    cin >> T;
    while (T--)
    {
        string s, t;
        cin >> s >> t;
        int n = s.length();
        
        vector<char> even, odd;
        for (int i = n - 1; i >= 0; i--)
        {
            if ((n - i - 1) % 2)
                odd.push_back(s[i]);
            else
                even.push_back(s[i]);
        }

        reverse(even.begin(), even.end());
        reverse(odd.begin(), odd.end());
        
        int m = t.length();
        int ptr = 0;
        
        int even_ptr = even.size();
        int odd_ptr = odd.size();
        
        int esize = even.size();
        int osize = odd.size();

        int e = 0, o = 0;
        bool ans = true;
       
        /* for (char c: even) */
            /* cout << c; */
        /* cout << endl; */
        /* for (char c: odd) */
            /* cout << c; */
        /* cout << endl; */

        for (int i = m - 1; i >= 0; i--)
        {
            bool flag = false;
            if (ptr == 0)
            {
                for (even_ptr = min(esize - 1 - e, esize - 1 - o); even_ptr >= 0; even_ptr--)
                {
                    /* cout << even[even_ptr] << endl; */
                    e++;
                    if(even[even_ptr] == t[i])
                    {
                        ptr = 1;
                        flag = true;
                        break;
                    }
                }   
            }
            else if (ptr == 1)
            {
                for (odd_ptr = min(osize - 1 - o, osize - e); odd_ptr >= 0; odd_ptr--)
                {
                    /* cout << odd[odd_ptr] << endl; */
                    o++;
                    if (odd[odd_ptr] == t[i])
                    {
                        ptr = 0;
                        flag = true;
                        break;
                    }
                }
            }
            if (flag == false)
            {
                ans = false;
                break;
            }
        }

        if (ans == true)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
}
