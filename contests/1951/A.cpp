#include <iostream>
#include <vector>
using namespace std;

int main() {
    int t, n;
    cin >> t;

    while (t--) {
        int n, sum = 0;
        cin >> n;

        string s;
        cin >> s;
        for (char c: s)
            if (c == '1')
                sum++;

        if (sum % 2 == 1) {
            cout << "NO\n";
            continue;
        }

        if (sum >= 4) {
            cout << "YES\n";
            continue;
        }

        // sum = 2
        for (int i = 1; i < n; i++) {
            if (s[i] == '1' and s[i - 1] == '1')
                sum = -1;
        }

        if (sum == -1) {
            cout << "NO\n";
            continue;
        }
        else cout << "YES\n";
    }
}