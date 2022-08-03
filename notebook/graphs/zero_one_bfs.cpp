// 0-1 BFS - O(V+E)

vector<int> d(n, INF);
d[s] = 0;
deque<int> q;
q.push_front(s);
while (!q.empty()) {
    int u = q.front();
    q.pop_front();
    for (auto edge : adj[u]) {
        int v = edge.first; // neighbour
        int w = edge.second; // weight of the edge u-v
        if (d[v] > d[u] + w) {
            d[v] = d[u] + w;
            
            if (w == 1)
                q.push_back(v);
            else
                q.push_front(v);
        }
    }
}