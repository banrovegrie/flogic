#include <iostream>
using namespace std;

vector<int> dp;
int a[] = {1, 2, 3, 4};

int f(int mask, int k) {
  if (dp[mask] != -1) return dp[mask];
  if (k == -1) return a[mask];
  dp[mask] = f(mask, k - 1);
  if (mask & (1 << k))
    dp[mask] += f(mask ^ (1 << k), k - 1);
  return dp[mask];
}

int main() {

    // # of elements in the list for which you want to find the sum over all subsets
    int n = 2;

    // the list for which you want to find the sum over all subsets

    // answer for sum over subsets of each subset
    vector<int> sos(1 << n);
    dp.resize(1 << n, -1);

    for (int i = 0; i < (1 << n); i++) {
        // iterate over all other sets and checks whether they're a subset of i
        for (int j = 0; j < (1 << n); j++) {
            if ((i & j) == j) { sos[i] += a[j]; }
        }
    }

    // print sos
    for (int i = 0; i < (1 << n); i++) {
        cout << sos[i] << " ";
    }
    cout << "\n";

    for (int i = 0; i < (1 << n); i++) f(i, n - 1);

    // print dp
    for (int i = 0; i < (1 << n); i++) {
        cout << dp[i] << " ";
    }
    cout << "\n";
}