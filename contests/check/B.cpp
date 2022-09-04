#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define all(x) x.begin(), x.end()
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<lli> a(n);
    set<lli> st;
    int cnt = 0;
    bool f = false;
    int co = 0, cm = 0;
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      if (a[i] != 0 && abs(a[i]) != 1)
        cnt++;
      if (a[i] == -1) {
        f = true;
        cm++;
      }
      if (a[i] == 1)
        co++;
    }
    if (cnt > 1 || (cnt >= 1 && f) || (cm > 1 && co == 0)) {
      cout << "no\n";
      continue;
    } else
      cout << "yes\n";
  }
  return 0;
}