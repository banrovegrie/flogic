#include <iostream>
#include <utility>
#include <string>
#include <vector>
#define endl "\n"
using namespace std;

void solve() {
    int n, m, k; 
    cin >> n >> m >> k;
        
    vector<int> a(n);
    for (int &i : a) cin >> i;

    sort(a.begin(), a.end());
    
    long long int ans = 0;
    int tax = 0;
    for (int i = 0; i < n; ++i) {
        ans += 1LL * min(m, k) * (a[i] + tax);
        tax += min(m, k), k -= min(m, k);
    }
    cout << ans << endl;
}

int main() {
    int t;
    cin >> t;

    while (t--){
        solve();
    }
}