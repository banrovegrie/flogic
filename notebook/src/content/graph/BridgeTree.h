/**
 * Author: Amul Agrawal
 * Date: 2022-09-23
 * Description: Finds all biconnected components in an undirected graph, and
 *  runs a callback for the edges in each. In a biconnected component there
 *  are at least two distinct paths between any two nodes. Note that a node can
 *  be in several components. An edge which is not in a component is a bridge,
 *  i.e., not part of any cycle.
 */
#pragma once

// 0 based indexing
int n, m, Tin;
vector<vii> adj, adjn;
vi vis, low;
vector<array<int, 3>> bridges;
Dsu<int> ds;
 
int dfs0(int x,int p=-1,int w=0) {
	vis[x] = 1; low[x] = Tin++;
	int crl = low[x];
	for(auto nx : adj[x]) {
		if(nx.ff == p) continue;
		else if (vis[nx.ff]) crl = min(crl, low[nx.ff]);
		else crl = min(crl, dfs0(nx.ff, x, nx.ss));
	}
	if(crl == low[x] and p != -1) bridges.pb({x, p, w});
	else if (p != -1) ds.join(x, p);
	return crl;
}
 
void build_bridgetree() {
	// CLEAR global variables 
	ds.build(n); // INITIALIZE DSU HERE
	rep(i,0,n) if(!vis[i]) dfs0(i);
	for(auto arr : bridges) {
		int u = ds.find(arr[0]), v = ds.find(arr[1]), w = arr[2]; 
		if(u != v) {
			adjn[v].pb({u, w}); adjn[u].pb({v, w});
		}
	}
}