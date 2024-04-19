#include <iostream>
#include <utility>
#include <string>
#include <vector>
#define endl "\n"
using namespace std;

void solve() {
    long long int n, k;
    cin >> n >> k;
    
    if (n == k)
        cout << "YES\n1\n1\n";
    
    else if (n < k)
        cout << "NO\n";
    
    else if (n < 2 * k - 1)
        cout << "NO\n";
    
    else
        cout << "YES\n2\n" << n - k + 1 << " 1\n";
}

int main() {
    int t;
    cin >> t;

    while (t--){
        solve();
    }
}