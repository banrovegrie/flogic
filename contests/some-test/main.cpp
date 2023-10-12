#include <iostream>
#include <vector>
using namespace std;

pair<int, int> partitionArray(const vector<int>& arr) {
    int total_sum = 0;
    for (int num : arr) {
        total_sum += num;
    }
    int n = arr.size();
    
    vector<vector<bool>> dp(n+1, vector<bool>(total_sum+1, false));

    // Initialize the first column as true (since sum 0 can always be achieved)
    for (int i = 0; i <= n; ++i) {
        dp[i][0] = true;
    }

    // Fill the dp table
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= total_sum; ++j) {
            dp[i][j] = dp[i-1][j];
            if (arr[i-1] <= j) {
                dp[i][j] = dp[i][j] || dp[i-1][j-arr[i-1]];
            }
        }
    }

    // Find the closest possible sum to half of the total sum
    int subset1_sum;
    for (int j = total_sum/2; j >= 0; --j) {
        if (dp[n][j]) {
            subset1_sum = j;
            break;
        }
    }

    int subset2_sum = total_sum - subset1_sum;
    return {subset1_sum, subset2_sum};
}

int main() {
    vector<int> arr = {7, 6, 7, 3, 1, 2};
    pair<int, int> result = partitionArray(arr);
    cout << "Subset 1 sum: " << result.first << ", Subset 2 sum: " << result.second << endl;
    return 0;
}
