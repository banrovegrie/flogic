#include <bits/stdc++.h>
using namespace std;

// 0-1 Knapsack Code
// Time Complexity: O(nW)
// Space Complexity: O(W)

// initialize your dp
int knapsack(int W, int n, int wt[], int val[]) {
    int dp[n+1][W+1];
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= W; j++) {
            if (i == 0 || j == 0) {
                dp[i][j] = 0;
            } else if (wt[i-1] <= j) {
                dp[i][j] = max(dp[i-1][j], dp[i-1][j-wt[i-1]] + val[i-1]);
            } else {
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    return dp[n][W];
}

// Fractional Knapsack
// Time Complexity: O(nW)
// Space Complexity: O(W)
int fractionalKnapsack(int n, int W, int w[], int v[]) {
    int dp[n+1][W+1];
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= W; j++) {
            if (i == 0 || j == 0) {
                dp[i][j] = 0;
            } else if (j < w[i-1]) {
                dp[i][j] = dp[i-1][j];
            } else {
                dp[i][j] = max(dp[i-1][j], dp[i-1][j-w[i-1]] + v[i-1]*w[i-1]/j);
            }
        }
    }
    return dp[n][W];
}