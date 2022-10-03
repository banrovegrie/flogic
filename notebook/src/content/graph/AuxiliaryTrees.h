/**
 * Author: Amul
 * Description: Creates a auxiliary tree of $k$ nodes.
 * Time: $O(k)$
 */

#pragma once

using vvi = vector<vector<int>>
struct Tree {
	int n;
	vvi adj;
	vi pos, tour, depth, pos_end, max_depth, dp, max_up;
	Tree(int n) : n(n), adj(n), max_depth(n), dp(n), max_up(n) {}
	void add_edge(int s, int t) {
		adj[s].pb(t); adj[t].pb(s);
	}
	vvi table;
	int argmin(int i, int j) { return depth[i] < depth[j] ? i : j; }
	void rootify(int r) {
		pos.resize(n); pos_end.resize(n);
		function<void (int,int,int)> dfs = [&](int u, int p, int d) {
			pos[u] = pos_end[u] = depth.size();
			tour.pb(u); depth.pb(d);
			for (int v: adj[u]) {
				if (v != p) {
					dfs(v, u, d+1);
					pos_end[u] = depth.size();
					tour.pb(u);
					depth.pb(d);
				}
			}
		}; dfs(r, r, 0);
		int logn = sizeof(int)*__CHAR_BIT__-1-__builtin_clz(tour.size()); // log2
		table.resize(logn+1, vi(tour.size()));
		iota(all(table[0]), 0);
		for (int h = 0; h < logn; ++h) 
			for (int i = 0; i+(1<<h) < tour.size(); ++i)
				table[h+1][i] = argmin(table[h][i], table[h][i+(1<<h)]);
	}
	int lca(int u, int v) {
		int i = pos[u], j = pos[v]; if (i > j) swap(i, j);
		int h = sizeof(int)*__CHAR_BIT__-1-__builtin_clz(j-i); // = log2
		return i == j ? u : tour[argmin(table[h][i], table[h][j-(1<<h)])];
	}
	int getDepth(int u){
		return depth[pos[u]];
	}
	void aux_Tree(vi nodes, vvi & adj_aux, vi & start_times){
		// adj_aux stores the children
		for(int x : nodes) start_times.pb(pos[x]);
		sort(all(start_times));
		for(int i = 1; i < (int) nodes.size();  i++){
			start_times.pb(pos[lca(tour[start_times[i]], tour[start_times[i - 1]])]);
		}
		sort(all(start_times));
		start_times.erase(unique(start_times.begin(), start_times.end()), start_times.end());
		adj_aux.resize(start_times.size());
		stack<int> st;
        // nodes now indexed according to start_times
		st.push(0);
		for(int i = 1; i < (int)start_times.size(); i++){
			while(pos_end[tour[start_times[st.top()]]] < start_times[i]){
				st.pop();
			}
			adj_aux[st.top()].pb(i);
			st.push(i);
		}
	}
};
