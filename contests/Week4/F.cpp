#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;
#define endl "\n"

vector<int> graph[100005];

int dfs(int u = 1, int parent = -1) {
    int val = 0;
    for (int v : graph[u])
        if (parent != v)
            val += dfs(v, u);
    return val ? val - 1 : 1;
}

int main() {
    int n, u, v;
    cin >> n;
    for (int i = 0; i < n-1; i++)
        cin >> u >> v,
        graph[u].push_back(v),
        graph[v].push_back(u);
    cout << (dfs() ? "Alice" : "Bob") << endl;
    return 0;
}
