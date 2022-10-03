/**
 * Author: Simon Lindholm
 * Date: 2015-02-23
 * License: CC0
 * Source: http://en.wikipedia.org/wiki/Bellman-Ford_algorithm
 * Description: Calculates shortest paths from $s$ in a graph that might have negative edge weights.
 * Unreachable nodes get dist = inf; nodes reachable through negative-weight cycles get dist = -inf.
 * Assumes $V^2 \max |w_i| < \tilde{} 2^{63}$. undirected graph with negative edge gets -inf for all 
 * vertices.
 * Time: O(VE)
 * Status: Tested on kattis:shortestpath3
 */
#pragma once

const int INF = 1e9;
void bellmann_ford_extended(vector<vector<pii>> &adj, 
							int source, vi &dist, vector<bool> &cyc) {
	dist.assign(adj.size(), INF);
	cyc.assign(adj.size(), false); // true when u is in a <0 cycle
	dist[source] = 0;
	for (int iter = 0; iter < adj.size() - 1; ++iter){
		bool relax = false;
		for (int u = 0; u < adj.size(); ++u)
			if (dist[u] == INF) continue;
			else for (auto &e : adj[u])
				if(dist[u]+e.second < dist[e.first])
					dist[e.first] = dist[u]+e.second, relax = true;
		if(!relax) break;
	}
	bool ch = true;
	while (ch) {				// keep going untill no more changes
		ch = false;				// set dist to -INF when in cycle
		for (int u = 0; u < adj.size(); ++u)
			if (dist[u] == INF) continue;
			else for (auto &e : adj[u])
				if (dist[e.first] > dist[u] + e.second
					&& !cyc[e.first]) {
					dist[e.first] = -INF;
					ch = true;		//return true for cycle detection only
					cyc[e.first] = true;
				}
	}
}

