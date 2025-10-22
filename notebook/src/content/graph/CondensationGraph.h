/**
 * Author: Lukas Polacek
 * Date: 2009-10-28
 * License: CC0
 * Source: Czech graph algorithms book, by Demel. (Tarjan's algorithm)
 * Description: Finds strongly connected components in a
 * directed graph. If vertices $u, v$ belong to the same component,
 * we can reach $u$ from $v$ and vice versa.
 * Usage: scc(graph, [\&](VI\& v) { ... }) visits all components
 * in reverse topological order. comp[i] holds the component
 * index of a node (a component only has edges to components with
 * lower index). ncomps will contain the number of components.
 * Time: O(E + V)
 * Status: Bruteforce-tested for N <= 5
 */
#pragma once

// 0 based indexing
void condense(vector<vi> adj,vector<vi> &adj_scc,
						vector<vi> &comp,vi &root_of,int n) {
	vector<vi> rev_adj(n);
	rep(u,0,n) {
		for(auto v : adj[u]) {
			rev_adj[v].push_back(u);
		}
	}
	vector<bool> vis(n, false); vi order, component, root_nodes;
	function<void(int)> dfs1 = [&](int x) {
		vis[x] = true;
		for(auto nx : adj[x]) {
			if(!vis[nx]) {
				dfs1(nx);
			}
		}
		order.push_back(x);
	};
	rep(i, 0, n) { if(!vis[i]) dfs1(i); }
	vis.clear(); vis.assign(n, false);
	// order is now kind of topologically sorted
	reverse(order.begin(), order.end());
	function<void(int)> dfs2 = [&](int x) {
		vis[x] = true;
		component.push_back(x);
		for(auto u : rev_adj[x]) {
			if(!vis[u]) {
				dfs2(u);
			}
		}
	};
	comp.clear(); comp.resize(n);
	root_of.clear(); root_of.resize(n);
	for(auto v : order) {
		if(!vis[v]) {
			dfs2(v);
			int root = component.front();
			for(auto u : component) root_of[u] = root;
			root_nodes.push_back(root);
			comp[root] = component;
			component.clear();
		}
	}
	adj_scc.clear(); adj_scc.resize(n);
	rep(u, 0, n) {
		for(auto v : adj[u]) {
			if(root_of[u] != root_of[v]) {
				adj_scc[root_of[u]].push_back(root_of[v]);
			}
		}
	}
}
