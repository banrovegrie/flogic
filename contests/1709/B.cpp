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
	
	int n, m;
	cin >> n >> m;

	vi arr(n);
	for(int i=0; i<n; i++){
		cin>>arr[i];
	}
	vi prefix(n-1);
	vi suffix(n-1);
	for(int i=1; i<n; i++){
		if(arr[i] < arr[i-1])
			prefix[i-1] = arr[i-1] - arr[i];
	}
	for(int i=n-1; i>0; i--){
		if(arr[i] > arr[i-1])
			suffix[i-1] = arr[i] - arr[i-1];
	}
	
	for(int i=1; i<n-1; i++){
		prefix[i] += prefix[i-1];
	}
	for(int i=n-2; i>=0; i--){
		suffix[i] += suffix[i+1];
	}
	for(int i=0; i<m; i++){
		int l, r;cin>>l>>r;
		int ans;
		if(r > l){
			l--;r--;r--;
			ans = prefix[r];
			if(l > 0)
				ans -= prefix[l-1];
			
		}else{
			l--;r--;
			ans = suffix[l];
			if(r < n-1)
				ans -= suffix[r];
		}
		cout<<abs(ans)<<"\n";
	}
}
