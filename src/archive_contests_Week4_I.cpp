#include <iostream>
#include <algorithm>
#include <limits.h>

#define endl "\n"
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> a(n), b(n);
    for (int &i: a) cin >> i;
    for (int &i: b) cin >> i;

    int ans = 0;
    for (int i: a) {
        int val = INT_MAX;
        for (int j: b) {
            val = min(val, abs(i - j));
        }
        ans = max(ans, val);
    }

    cout << ans << endl;
}