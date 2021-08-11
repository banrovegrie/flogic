#include <bits/stdc++.h>

using namespace std;

const int N = 100 + 10;
const int M = 100000 + 10;
const int inf = 1000000001;

int f[M];
int w[N], v[N];

int main()
{
	int n, W, tot = 0;
	cin>>n>>W;
	for (int i=1; i<=n; i++){
		cin>>w[i]>>v[i];
		tot += v[i];
	}
	for (int i=1; i<=tot; i++) 
        f[i] = inf;
	for (int i=1; i<=n; i++)
		for (int j=tot; j>=v[i]; j--) 
            f[j] = min(f[j], f[j-v[i]] + w[i]);
    for (int j=tot; j>=0; j--)
		if (f[j] <= W)
        {
			cout<<j<<endl;
			break;
		}
	return 0;
}
