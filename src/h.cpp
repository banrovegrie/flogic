#include<bits/stdc++.h>
using namespace std;
#define pii pair<int, int>
#define pp pair<int, pii >
#define all(x) x.begin(),x.end()
#define N 500005
pii id[N];
pp xe[N];
vector<int> gr[N];
int ans[N], vis[N], isc[N], nx[N];
vector<vector<int> > cycles, pref;
vector<int> path;
int K;
int pre[N], hs[N], maxh;
set<pii> st[N];
vector<int> rm;
void dfs1(int node, int h)
{
    st[node].insert({h, node});
    for(auto x: gr[node])
    {
        dfs1(x, h+1);
    if(st[x].size()>st[node].size())
        swap(st[x], st[node]);
    for(auto y: st[x])
        st[node].insert(y);
    }
    while(st[node].rbegin()->first>h+K)
        st[node].erase(--st[node].end());
    ans[node] = st[node].size();
}
pp dfs(int node, int prev)
{
    vis[node] = 1;
    path.push_back(node);
    int a= nx[node];
    pp xd;
    if(vis[a]==0)
    {
        xd = dfs(a, prev+1);
    }
    else if(vis[a]==1)
    {
        vector<int> cyc;
        cyc.push_back(a);
        for(int j=path.size()-1;j>=0;j--)
        {
            if(path[j]==cyc[0])
                break;
            cyc.push_back(path[j]);
        }
        reverse(all(cyc));
        cycles.push_back(cyc);
        pref.push_back(vector<int>(2*cyc.size()+1));
        int i=0;
        for(auto x: cyc)
        {
            isc[x] = true;
            id[x] = {cycles.size()-1, i};
            i++;
        }
    }
    else
    {
        xd = xe[a];
    }
        xd.first++;
    path.pop_back();
    vis[node]=2;
    if(isc[node])
    {
        return xe[node] = {0, id[node]};
    }
    else
    {
        if(xd.first<=K)
        {
            int se = cycles[xd.second.first].size();
            int en = (xd.second.second+min(K-xd.first, se-1));
            pref[xd.second.first][en+1]--;
            pref[xd.second.first][xd.second.second]++;
        }
        return xe[node] = {xd.first, xd.second};
    }
}
int main()
{
    int n,k;
    cin>>n>>k;
    K=k;
    vector<int> indeg(n+1);
    for(int i=1;i<=n;i++)
    {
        ans[i]=1;
        cin>>nx[i];
        indeg[nx[i]]++;
        gr[nx[i]].push_back(i);
    }
    for(int i=1;i<=n;i++)
    {
        if(!indeg[i])
        {
            dfs(i, 0);
        }
    }
    for(int i=1;i<=n;i++)
    {
        if(!vis[i])
            dfs(i, 0);
    }
    for(int i=0;i<cycles.size();i++)
    {
        for(auto x: cycles[i])
        {
            ans[x]+=min(k, (int)cycles[i].size()-1);
        }
        int curr=0;
        for(int j=0;j<=2*cycles[i].size();j++)
        {
            curr+=pref[i][j];
            ans[cycles[i][j%(int)cycles[i].size()]]+=curr;
        }
    }
    for(auto x: cycles)
    {
        for(auto zz: x)
        {
            for(auto y: gr[zz])
            {
            if(isc[y])
                continue;
            dfs1(y, 0);
            }
        }
    }
    for(int i=1;i<=n;i++)
        cout<<ans[i]<<"\n";
}