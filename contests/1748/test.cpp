#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define MP make_pair
#define F first
#define S second
#define SZ(a) (int)(a.size())
#define ALL(a) a.begin(), a.end()
#define off                                                                    \
  ios_base::sync_with_stdio(0);                                                \
  cin.tie(0);                                                                  \
  cout.tie(0)
typedef long long int LL;
typedef vector<LL> VL;
#define dout(n) cout << n << "\n"
#define DRT()                                                                  \
  int t;                                                                       \
  cin >> t;                                                                    \
  while (t--)
void IO() {
#ifndef ONLINE_JUDGE
  freopen("../input.txt", "r", stdin);
  freopen("../output.txt", "w", stdout);
#endif
  mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
  off;
}

int main() {
  IO();
  DRT() {
    LL n;
    cin >> n;

    VL a(n);
    for (LL i = 0; i < n; i++)
      cin >> a[i];

    VL p(n);
    p[0] = a[0];
    for (LL i = 1; i < n; i++)
      p[i] = p[i - 1] + a[i];

    LL ans = 0, max_count = 0;
    map<LL, LL> counts;
    bool zero_seen = false;

    for (LL i = 0; i < n; i++) {
      if (a[i] == 0) {
        if (zero_seen)
          ans += max(1ll, max_count);

        max_count = 0;
        counts.clear();
        zero_seen = true;
      }
      else if (p[i] == 0 && zero_seen == false) {
        ans++;
      }
      counts[p[i]]++;
      max_count = max(max_count, counts[p[i]]);
    }
    if (zero_seen)
      ans += max(1ll, max_count);

    dout(ans);
  }
  return 0;
}