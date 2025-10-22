#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds; 
using namespace std;
#define lli long long int
#define pii pair<int,int>
#define pll pair<lli, lli>
#define double long double
#define all(x) x.begin(),x.end()
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define siz(x) x.size()
#define prs(x,y) x.find(y)!=x.end()
#define DEBUG(x) cout << '>' << #x << ':' << x << endl;
#define forn(i,n) for(int i=0;i<(n);i++)
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define FORD(i,a,b) for(int i=(a);i>=(b);i--)
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
inline bool EQ(double a, double b) { return fabs(a-b) < 1e-9; }
const int INF = 1<<29;
typedef long long ll;
inline int two(int n) { return 1 << n; }
inline int test(int n, int b) { return (n>>b)&1; }
inline void set_bit(int & n, int b) { n |= two(b); }
inline void unset_bit(int & n, int b) { n &= ~two(b); }
inline int last_bit(int n) { return n & (-n); }
inline int ones(int n) { int res = 0; while(n && ++res) n-=n&(-n); return res;}
inline int level(int n){int ans=0;while(n%2==0){n/=2;ans++;}return ans;}
#define gog(T,x) cout<<"Case #"<<T<<": "<<x<<"\n";
lli MOD=998244353;
lli powa(lli x,lli y)
{
	lli ans=1;
	lli m=MOD;
	while(y>0)
	{
		if(y%2==1)
		{
			ans*=x;
			ans%=m;
		}
		y/=2;
		x=x*x;
		x%=m;
	}
	return ans%m;
}
std::mt19937 gen(std::chrono::system_clock::now().time_since_epoch().count());
#define FAC 0
lli fac[FAC+1];
lli invfac[FAC+1];
lli cnk(lli n, lli k) {
    return (fac[n] * invfac[n - k] % MOD * invfac[k] % MOD)%MOD;
}
// First of all remove t in case of single test case
vector<int> vc;
lli solve()
{
	lli n,x;
	cin>>n>>x;
	bool odd=false;
	if(n%2LL)
	{
		odd=true;
		if(x<1LL)
		{
			cout<<-1<<"\n";
			return 0;
		}
		if(x%2==0)
			x-=1;
	}
	n/=2;
	x/=2;
	vc.clear();
	vector<int> dp(32,0);
	int cst=0;
	int cs=0;
	for(int i=0;i<30;i++)
	{
		bool no=(n>>i)&1;//N ka ith bit 1
		bool xo=(x>>i)&1;// X k ITH BIT 1
		if(!xo)
		{
			if(i!=0)
				dp[i]=dp[i-1];
		}
		else
		{
		if(no)
		{
			dp[i]=(1+cs)+(i>0?dp[i-1]:0);
		}
		dp[i]=max(dp[i], cst);
		}
		if(no)
		{
			cst+=cs+1;
		}
		cs=1-cs;
	}
	if(!odd)
	cout<<min(1+cst-dp[29], cst)<<"\n";
	else
		cout<<1+cst-dp[29]<<"\n";
	return 0;
}
int main()
{
	    fac[0]=invfac[0]=1;
    for(int i=1;i<=FAC;i++)
    {
        fac[i]=(fac[i-1]*i)%MOD;
        invfac[i]=powa(fac[i],MOD-2);
    }
	fast_io //REMOVE FOR interactive problems
	int t=1;
	cin>>t;
	while(t--)
	{
		solve();
	}

}

