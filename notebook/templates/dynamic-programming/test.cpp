#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<long long> a(n);
  for (auto &x : a)
    cin >> x;
  vector<vector<long long>> mndp(1 << n, vector<long long>(n, (long long)1e15)),
      mxdp(1 << n, vector<long long>(n, -1));
  for (int i = 0; i < n; ++i) {
    mndp[0][i] = 0;
    mxdp[0][i] = 0;
  }
  for (int msk = 1; msk < (1 << n); ++msk) {
    for (int i = 0; i < n; ++i)
      if (msk & (1 << i)) {
        if (!(msk & (msk - 1))) {
          mndp[msk][i] = 0;
          mxdp[msk][i] = 0;
          continue;
        }
        for (int j = 0; j < n; ++j)
          if (msk & (1 << j) and i != j) {
            mndp[msk][i] = 
                min(mndp[msk][i], mndp[msk ^ (1 << i)][j] + (a[i] ^ a[j]) +
                                      __gcd(a[i], a[j]));
            mxdp[msk][i] =
                max(mxdp[msk][i], mxdp[msk ^ (1 << i)][j] + (a[i] ^ a[j]) +
                                      __gcd(a[i], a[j]));
          }
      }
  }
  long long mn = 1e15, mx = 0;
  for (int i = 0; i < n; ++i) {
    mn = min(mn, mndp[(1 << n) - 1][i]);
    mx = max(mx, mxdp[(1 << n) - 1][i]);
  }
  cout << mx - mn << endl;
  return 0;

  // Create a vector and initialize all values to 1e15.
  vector<int> v(10, (int)1e15);
  for (auto i: v)
    cout << i << " ";

/*
for i, x in enu
*/
}