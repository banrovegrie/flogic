#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

int dp[5005][5005];
int n, queries, l, r;
string s;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
	cin >> s;
	n = s.size();
	
    for (int i = 0; i < n; i++)
	{
	    for (int j = 0; i + j < n and i - j >= 0; j++)
	    {
	        if ( s[i + j] != s[i - j])
                break;
            dp[i - j + 1][i + j + 1] = 1;
	    }
	}

    for (int i = 0; i < n - 1; i++)
	{
	    for (int j = 1; i - j + 1 >= 0 and i + j < n; j++)
	    {
	        if (s[i - j + 1] != s[i + j])
                break;
            dp[i - j + 2][i + j + 1] = 1;
	    }
	}

	for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n - i + 1; j++)
            dp[j][j + i - 1] += dp[j + 1][j + i - 1] + dp[j][j + i - 2] - dp[j + 1][j + i - 2];
    
    cin >> queries;
    while (queries--) {
        cin >> l >> r;
        cout << dp[l][r] << endl;
    }
    return 0;  
}