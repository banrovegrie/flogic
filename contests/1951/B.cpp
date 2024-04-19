#include <iostream>
#include <utility>
#include <string>
#include <vector>
#define endl "\n"
using namespace std;

void solve() {
    int n, k, x = 0, ans1 = 0, ans2 = 0;
    cin >> n >> k;
    k--;

    vector<int> c(n, 0);
    for (int &i: c) cin >> i;

    for (int i = 0; i < k; i++) {
        if (c[i] > c[k]) {
            x = i;
            break;
        }
    }

    swap(c[k], c[0]);

    for (int i = 1; i < n; i++) {
        if (c[i] < c[0])
            ans1++;
        else break;
    }

    swap(c[0], c[k]);
    swap(c[k], c[x]);

    if (x != 0) ans2++;

    for (int i = x + 1; i < n; i++) {
        if (c[i] < c[x])
            ans2++;
        else break;
    }

    cout << max(ans1, ans2) << endl;
}

int main() {
    int t;
    cin >> t;

    while (t--){
        solve();
    }
}