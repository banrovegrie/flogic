// Longest Increasing Subsequence - O(nlogn)
//
// dp(i) = max j<i { dp(j) | a[j] < a[i] } + 1
//
int longestIncreasingSubsequence(vector<int>& a) {
    int n = a.size();
    vector<int> dp(n, 1);
    
    for (int i = 0; i < n; i++) {
        if (i > 0 && a[i] > a[i-1]) {
            dp[i] = max(dp[i], dp[i-1] + 1);
        }
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

// Longest Palindromic Subsequence
//
// dp(i, j) = longest palindromic subsequence of a[i..j]
//
int longestPalindromeSubseq(string s) {
    int n = s.size();
    vector<vector<int>> dp(n, vector<int>(n));
    for (int i = n - 1; i >= 0; --i) {
        dp[i][i] = 1;
        for (int j = i+1; j < n; ++j) {
            if (s[i] == s[j]) {
                dp[i][j] = dp[i+1][j-1] + 2;
            } else {
                dp[i][j] = max(dp[i+1][j], dp[i][j-1]);
            }
        }
    }
    return dp[0][n-1];
}

// Longest Palindromic Substring
//
// Solve using Manacher's Algorithm
// O(n^2)
//