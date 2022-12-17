#include<bits/stdc++.h>
using namespace std;
#define N 5000
int fac[5983][N+2];
int ad[N+2];
int nz[N+2];
int query(int x)
{
    cout<<"? "<<x+1<<endl;
    int xd;
    cin>>xd;
    return xd;
}
int main() {
    fac[0][0] = 1;
    for(int i=1;i<=5982;i++)
    {
        for(int j=0;j<=N;j++)
        ad[j] = 0;
        for(int j =0;j<=N;j++)
        {
            int xd = fac[i-1][j]*i;
            int curr = j;
            while(xd>0)
            {
                ad[curr]+=xd%10;
                curr++;
                xd/=10;
            }
        }
        int curr = 0;
        bool f = false;
        vector<int> vc;
        for(int j=0;j<=N;j++)
        {
            ad[j]+=curr;
            curr/=10;
            curr+=ad[j]/10;
            fac[i][j] = ad[j]%10;
            if(fac[i][j]!=0)
            {
                f = true;
                while(!vc.empty())
                {
                    nz[vc.back()] = true;
                    vc.pop_back();
                }
            }
            else if(f)
            {
                vc.push_back(j);
            }
        }
    }
    int t;
    cin>>t;
    while(t--)
    {
    vector<int> rem;
    for(int i=1;i<=5982;i++)
    rem.push_back(i);
    for(int i=0;i<10;i++)
    {
        int mmin = INT_MAX;
        int cdiv = -1;
        for(int opt = 0;opt<=N;opt++)
        {
        vector<int> cnt(10);
        for(int j=0;j<=rem.size();j++)
        {
            cnt[fac[rem[j]][opt]]++;
        }
        int maxa = INT_MIN;
        for(int i=0;i<10;i++)
        {
            maxa = max(maxa, cnt[i]);
        }
        if(maxa<mmin)
        {
            mmin = maxa;
            cdiv = opt;
        }
        }
        int xd = query(cdiv);
        vector<int> nrem;
        for(int j=0;j<rem.size();j++)
        {
            if(fac[rem[j]][cdiv]==xd)
            {
                nrem.push_back(rem[j]);
            }
        }
        rem = nrem;
    }
    cout<<"! "<<rem[0]<<endl;
    string xd;
    cin>>xd;
    }
}