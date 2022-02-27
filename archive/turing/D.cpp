#include<bits/stdc++.h>
using namespace std;
#define nan cout<<"-1\n";return 0
int solv()
{
	int n,k;
	cin>>n>>k;
	int rem = n-k;
	if(rem==2 || rem==0)
	{
		nan;
	}
	vector<vector<int> > vc;
	for(int i=1;i<=n;i++)
	{
		if(i!=k+1)
		vc.push_back({i, k+1});
	}
	for(int i=k+2;i<=n;i+=2)
	{
		if(i==n)
		{
			if(i-1!=k+1)
			vc.push_back({i-1, i});
		}
		else
			vc.push_back({i, i+1});
	}
	if(k==0 && n==5)
	{
		vc.clear();
		vc.push_back({1,2});
        vc.push_back({2,3});
        vc.push_back({3,4});
        vc.push_back({4,5});
		vc.push_back({5, 1});
	}
    if(k==0 && n<=6 && n>=4 && n!=5)
    {
        vc.clear();
        vc.push_back({1,2});
        vc.push_back({2,3});
        vc.push_back({3,4});
        vc.push_back({4,1});
        for(int i=5;i<=n;i+=2)
        {
            if(i!=n)
            {
            vc.push_back({i, 1});
            vc.push_back({i, i+1});
            vc.push_back({i+1, 3});
            }
            else
            {
                vc.push_back({1, i});
                vc.push_back({i, 3});
            }
        }
    }
	cout<<vc.size()<<"\n";
	for(auto x: vc)
		cout<<x[0]<<" "<<x[1]<<"\n";
	return 0;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin>>t;
	while(t--)
	{
		solv();
	}
}
