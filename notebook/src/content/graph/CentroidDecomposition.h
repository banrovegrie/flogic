/**
 * Author: Tanuj Khattar
 * Description: 
 * Time: $O(N \log N + Q)$
 * Status: stress-tested
 */


const int N = 5e4 + 13, logN = 17;
vi adj[N], sub(N), par(N,-1), lvl(N), done(N), par_adj(N);
vector<vi> dist(N, vi(logN, 0)), anc(N, vi(logN, 0));
int nn = 0, root;
void dfs_size(int x,int p) {
	nn++; sub[x] = 1;
	for(auto nx : adj[x]) if(!done[nx] and nx != p) {
			dfs_size(nx, x); sub[x] += sub[nx];
		} 
}
int find_ct(int x,int p) {
	for(auto nx : adj[x]) if(!done[nx] and nx != p and sub[nx] > nn/2) 
    return find_ct(nx, x);
	return x;
}
void dfs(int x,int p,int ct) {
	anc[x][lvl[ct]] = ct;
	for(auto nx : adj[x]) if(!done[nx] and nx != p) {
			dist[nx][lvl[ct]] = 1 + dist[x][lvl[ct]];
			dfs(nx, x, ct);
		}
}
// par_adj[ct] = adjacent vertex to parent of ct in OT in subtree of ct.
int decompose(int x,int p=-1) {
	nn = 0; dfs_size(x, x);
	int ct = find_ct(x, x);
	if(p) lvl[ct] = 1 + lvl[p];
	done[ct] = 1; par[ct] = p;
	dfs(ct, ct, ct);
	for(auto nx : adj[ct]) if(!done[nx]) {
			int nct = decompose(nx, ct);
			par_adj[nct] = nx;
		}
	return ct;
}
vector<vi> child_cntb(N), my(N);
rep(x,0,n) for(int y = x; y >= 0; y = par[y]) {
			my[y].pb(dist[x][lvl[y]]);
      if(par[y] >= 0)
        child_cntb[y].pb(dist[x][lvl[par[y]]]);
  }
rep(x,0,n) {
		sort(all(my[x])); sort(all(child_cntb[x]));
}
// number of nodes <= k in v.
auto cnt_k = [&](vi &v,int k) {
  int l = upper_bound(all(v), k) - v.begin();
  return l;
};
auto k_dists = [&](int x,int k) {
  int ans = cnt_k(my[x], k);
  int ch = x, q = x; x = par[x];
  while(x >= 0) {
    ans += (cnt_k(my[x], k - dist[q][lvl[x]]));
    ans -= (cnt_k(child_cntb[ch], k - dist[q][lvl[x]]));
    ch = x; x = par[x];
  }
  return ans;
};