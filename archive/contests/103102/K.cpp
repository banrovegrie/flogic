#include <bits/stdc++.h>
using namespace std;
#define int long long
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define pb push_back
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int mod = 1e9 + 7;
const int N = 2e5 + 5;

struct node {
    int m, p, val;
} a[N];

int n;
bool cmp(node& lhs, node& rhs) {
    return lhs.val > rhs.val;
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i].m;
    }
    for (int i = 1; i <= n; i++) {
        cin >> a[i].p;
        a[i].val = a[i].m + a[i].p;
    }
    sort(a + 1, a + n + 1, cmp);
    cout << a[1].val << " " << a[n].val << endl;
    return 0;
}