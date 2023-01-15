#include <bits/stdc++.h>
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

signed main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	int t;cin>>t;
	while(t--){
		string s;cin>>s;
		int n = s.length();
		if(n&1){
			cout<<"NO\n";
			continue;
		}

		// int bracket = 0, meow = 0;
		// for (int i = 0; i < n; i++) {
		// 	if (s[i] == '?') bracket++;
		// 	else if (s[i] == '(') meow++;
		// 	else meow--;
		// }
		// if (abs(meow) == bracket) {
		// 	cout << "YES" << endl;
		// 	continue;
		// }

		int q = 0;
		int sum = 0;
		bool ok = true;
		for(int i=0; i<n; i++){
			if(s[i] == '?'){
				if(sum == 0){
					sum = 1;
				}else{
					q++;
				}
			}
			else if(s[i] == ')'){
				sum--;
				if(sum < 0){
					if(q == 1){
						sum++;
						q--;
					}
					else{
						ok = false;
						break;
					}
				}
			}else{
				sum++;
			}
		}

		if (abs(sum) != q || !ok) {
			cout<<"NO\n";
		}
		else
			cout<<"YES\n";
	}
}
