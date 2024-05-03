#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cassert>
#include <cstring>
using namespace std;
#define int long long
#define endl '\n'
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define pb push_back
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

bool checkRotatedAndSorted(vi arr, int n)
{
    // Your code here
    // Initializing two variables x,y as zero.
    int x = 0, y = 0;
 
    // Traversing array 0 to last element.
    // n-1 is taken as we used i+1.
    for (int i = 0; i < n - 1; i++) {
        if (arr[i] < arr[i + 1])
            x++;
        else
            y++;
    }
 
    // If till now both x,y are greater than 1 means
    // array is not sorted. If both any of x,y is zero
    // means array is not rotated.
    if (y == 1) {
        // Checking for last element with first.
        if (arr[n - 1] < arr[0])
            x++;
        else
            y++;
 
        // Checking for final result.
        if (y == 1)
            return true;
    }
 
    // If still not true then definitely false.
    return false;
}

void solve() {
    int n;
    cin >> n;

    vi a(n);
    for (int &i: a) cin >> i;

    for (int  i = 0; i < n; i++) {
        if (i + 1 == a[a[i] - 1]) {
            cout << 2 << endl;
            return;
        }   
    }
    cout << 3 << endl;
    return;
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    int t;
    cin >> t;

    while (t--) {
        solve();
    }
}