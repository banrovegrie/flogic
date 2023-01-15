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
ll n,m;
signed main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	cin>>n>>m;
	vector<ll> arr(m);
	for(int i=0; i<m; i++){
		cin>>arr[i];
	}
	ll q;cin>>q;
	for(int i=0; i<q; i++){
		ll sx, sy, fx, fy, k;
		cin>>sx>>sy>>fx>>fy>>k;
		ll ty = abs(sy - fy);
		ll remy = ty % k;
		ll wanty = (k - remy) % k;
		if(wanty&1){
			cout<<"NO\n";
			continue;
		}
		bool ok = true;
		wanty /= 2;
		if(sy < fy){
			if(wanty > sy && wanty > (m - fy)){
				ok = false;
			}
		}else{
			if(wanty > fy && wanty > (m - sy)){
				ok = false;
			}
		}
		ll tx = abs(sx - fx);
		ll remx = tx % k;
		ll wantx = (k - remx) % k;
		if(wantx&1){
			cout<<"NO\n";
			continue;
		}
		bool ok = true;
		wantx /= 2;
		if(sx < fx){
			if(wantx > (sx - arr[sy-1]) && wantx > (n - fx)){
				ok = false;
			}
		}else{
			if(wanty > (fx - arr[sy - 1] && wanty > (m - sy)){
				ok = false;
			}
		}
	}
}
