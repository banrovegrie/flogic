/**********************************************************************************
* KUHN'S ALGORITHM (FIND GREATEST NUMBER OF MATCHINGS - BIPARTITE GRAPH)          *
* Time complexity: O(VE)                                                          *
* Notation: ans:      number of matchings                                         *
*           b[j]:     matching edge b[j] <-> j                                    *
*           adj[i]:   adjacency list for node i                                   *
*           vis:      visited nodes                                               *
*           x:        counter to help reuse vis list                              *
**********************************************************************************/

// TIP: If too slow, shuffle nodes and try again.
int x, vis[N], b[N], ans;

bool match(int u) {
  if (vis[u] == x) return 0;
  vis[u] = x;
  for (int v : adj[u])
    if (!b[v] or match(b[v])) return b[v]=u;
  return 0;
}

for (int i = 1; i <= n; ++i) ++x, ans += match(i);

// Maximum Independent Set on bipartite graph
MIS + MCBM = V

// Minimum Vertex Cover on bipartite graph
MVC = MCBM
