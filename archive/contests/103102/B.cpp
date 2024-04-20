#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define pb push_back
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	string s;
	cin >> s;

	int n = s.size();
	int count = 0, p = 0;
	for (int i = n; i--;) {
		if (s[i] == '0') count++;
		else p += count;
	}
	puts(p%3?"Alice":"Bob");

}
