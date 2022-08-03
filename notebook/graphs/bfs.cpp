/**********************************************************************************
* BFS (BREADTH-FIRST SEARCH)                                                      *
* Time complexity: O(V+E)                                                         *
* Usage: bfs(node)                                                                *
* Notation: s: starting node                                                      *
*           adj[i]: adjacency list for node i                                     *
*           vis[i]: visited state for node i (0 or 1)                             *
**********************************************************************************/

vector<vector<int>> adj;
int n; // number of nodes
int s; // source

vector<int> d(n, 0), p(n, -1), visited(n, false);
queue<int> q;

q.push(s);
visited[s] = true;

while (not q.empty()) {
    int u = q.front();
    q.pop();

    for (auto v: adj[u]) {
        if (not visited[v]) {
            visited[v] = true;
            d[v] = d[u] + 1;
            p[v] = u;
            q.push(v);
        }
    }
}