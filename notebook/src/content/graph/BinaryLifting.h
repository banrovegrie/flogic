/**
 * Author: Johan Sannemo
 * Date: 2015-02-06
 * License: CC0
 * Source: Folklore
 * Description: Initialize par[N][logN] and depth[N] array.
 * kthpar: logN, lca: logN
 * Status: Tested at Petrozavodsk, also stress-tested via LCA.cpp
 */
#pragma once

void dfs(int x,int pr=0,int d=0) {
	depth[x] = d; par[x][0] = pr;
	rep(i,1,logN) par[x][i]=par[par[x][i-1]][i-1];
	for(auto next : adj[x]) 
		if(next != pr)
			dfs(next, x, d+1);
}

int kthpar(int x,int k) {
	int ret = x;
	rep(i, 0, logN) if((k>>i)&1) ret = par[ret][i];
	return ret;
}

int lca(int u,int v) {
	if(depth[u] > depth[v]) swap(u,v);
	v = kthpar(v, depth[v] - depth[u]);
	if(u == v) return u;
	for(int i=logN-1;i>=0;i--) {
		if(par[u][i] != par[v][i]) {
			u=par[u][i]; v=par[v][i];
		}
	}
	return par[u][0];
}