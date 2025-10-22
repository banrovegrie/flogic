// Longest Increasing Subsequence - O(nlogn)
//
// dp(i) = max j<i { dp(j) | a[j] < a[i] } + 1
//
int longestIncreasingSubsequence(vector<int>& a) {
    int n = a.size();
    vector<int> dp(n);
    
    for (int i = 0; i < n; i++) {
        int mx = 0;
        for (int j = 0; j < i; j++) {
            if (a[j] < a[i])
                mx = max(mx, dp[j]);
        }
        dp[i] = mx + 1;
    }
    return *max_element(dp.begin(), dp.end());
}

// Longest Common Subsequence - O(mn)
//
// dp(i, j) = max { dp(i-1, j-1) | a[i] == b[j] } + 1
//
int longestCommonSubsequence(vector<int>& a, vector<int>& b) {
    int n = a.size();
    int m = b.size();
    vector<vector<int>> dp(n+1, vector<int>(m+1, 0));

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (a[i-1] == b[j-1])
                dp[i][j] = dp[i-1][j-1] + 1;
            else
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }
    return dp[n][m];
}