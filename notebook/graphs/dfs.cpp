/**********************************************************************************
* DFS (DEPTH-FIRST SEARCH)                                                        *
* Time complexity: O(V+E)                                                         *                                                      *
* Notation: adj[x]: adjacency list for node x                                     *
*           vis[i]: visited state for node i (0 or 1)                             *
**********************************************************************************/

vector<vector<int>> adj; // graph represented as an adjacency list
int n; // number of vertices
vector<bool> visited(n, false); // visited state for each vertex

void dfs(int u) {
  visited[u] = true;
  for (int v : adj[u])
    if (!visited[v])
      dfs(v);
}