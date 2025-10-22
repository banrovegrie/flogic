- "Sometimes it is the people no one can imagine anything of who do the things no one can imagine." (Turing, alleged)
- "Discovery is a child’s privilege, one who is not afraid to be wrong, to look silly, to not be serious, to act differently from everyone else and ignore the silent and flawless consensus that is part of the air we breathe – the consensus of all the people who are, or are reputed to be, reasonable." (Grothendieck)
- "All the time you're saying to yourself, 'I could do that, but I won't,' — which is just another way of saying that you can't." (Feynman)

# Competitive Programming

Solving competitive programming problems involve generally a combination of these following aspects:

1. **Observation**: Understanding the problem and come up with non-trivial properties. Abductive reasoning is often very helpful.
2. **Technique**: Appling known algorithms or data structures to the problem.
3. **Implementation**: Writing the solution fast, bug-free and naturally understandable.

Make sure that you understand various aspects of the problem statement and prove your way towards the solution. Don't be afraid of any type of problem or implementation.

## List of basic and important techniques

- greedy
- binary or ternary search
- brute force
- dfs, bfs, dijkstra
- algebra (is this **fft**?)
- string (is this **kmp, trie, hashing, suffix, aho-corasik**?)
- combinatorics (is this **dp**? is this **bitmasking**?)
- data structures (is this **segment tree**?)

## References

1. [The Reason You are Bad at Codeforces — You are Not Russian Enough](https://codeforces.com/blog/entry/126310)
2. [All You Need is Randomly Guessing — How to Improve at Codeforces](https://codeforces.com/blog/entry/126875)
3. Link to most useful stuff: [notebook](../files/notebook.pdf).

## Table of Contents
1. [Template & Setup](#template)
2. [Data Structures](#data-structures)
3. [Dynamic Programming](#dynamic-programming)
4. [Graph Algorithms](#graph-algorithms)
5. [String Algorithms](#string-algorithms)
6. [Mathematics](#mathematics)
7. [Miscellaneous](#miscellaneous)

## Template

```cpp
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cassert>
#include <cstring>
using namespace std;
#define int long long
#define endl '\n'
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define pb push_back
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

void solve() {
    return;
}

signed main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
    
    int t;
    cin >> t;
    
    while (t--) {
        solve();
    }
}
```

## Data Structures

### Linked List
```cpp
template<typename T>
struct node {
    T data; 
    struct node* next, *prev;
};

template<typename T>
class LinkedList {
public:
    node<T> *head, *tail;
    
    LinkedList() {
        head = NULL; tail = NULL;
    }
    
    void display(node<T> *head) {
        if (head == NULL) cout << endl;
        else cout << head->data << " ", display(head->next);
    }
    
    void push_back(T n) {
        node<T> *temp = new node<T>;
        temp->data = n; temp->next = NULL; temp->prev = NULL;
        if (head == NULL)
            head = temp, tail = temp;
        else {
            tail->next = temp; temp->prev = tail;
            tail = tail->next;
        }
    }
    
    void push_front(T n) {
        node<T> *temp = new node<T>;
        temp->data = n; temp->next = NULL; temp->prev = NULL;
        if (head == NULL)
            head = temp, tail = temp;
        else {
            head->prev = temp; temp->next = head;
            head = head->prev;
        }
    }
    
    void pop_front() {
        if (head == NULL) cout << "Empty list\n";
        else {
            head = head->next;
            node<T> *temp = head->prev;
            delete temp;
        }
    }
    
    void pop_back() {
        if (head == NULL) cout << "Empty list\n";
        else {
            tail = tail->prev;
            node<T> *temp = tail->next;
            delete temp;
        }
    }
};

// Cycle detection (Floyd's Tortoise and Hare)
bool hasCycle(ListNode* head) {
    ListNode* slow = head;
    ListNode* fast = head;
    
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) return true;
    }
    
    return false;
}
```

### Minimum Queue
```cpp
struct MinQueue {
    int plus = 0;
    int sz = 0;
    deque<pair<int, int>> dq;
    
    bool empty() { return dq.empty(); }
    void clear() { plus = 0; sz = 0; dq.clear(); }
    void add(int x) { plus += x; }
    int min() { return dq.front().first + plus; }
    int size() { return sz; }
    
    void push(int x) {
        x -= plus;
        int amt = 1;
        while (dq.size() and dq.back().first >= x)
            amt += dq.back().second, dq.pop_back();
        dq.push_back({ x, amt });
        sz++;
    }
    
    void pop() {
        dq.front().second--, sz--;
        if (!dq.front().second) dq.pop_front();
    }
};
```

### Ordered Set
```cpp
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>
using namespace __gnu_pbds;

typedef tree<int,null_type,less<int>,rb_tree_tag,
             tree_order_statistics_node_update> ordered_set;

ordered_set s;
s.insert(2);
s.insert(3);
s.insert(7);
s.insert(9);

// find_by_order returns an iterator to the element at a given position
auto x = s.find_by_order(2);
cout << *x << "\n"; // 7

// order_of_key returns the position of a given element
cout << s.order_of_key(7) << "\n"; // 2
cout << s.order_of_key(6) << "\n"; // 2 (position if inserted)
```

### Segment Tree
```cpp
int n, v[N], lz[4*N], st[4*N];

void build(int p = 1, int l = 1, int r = n) {
    if (l == r) {
        st[p] = v[l]; return;
    }
    build(2*p, l, (l+r)/2);
    build(2*p+1, (l+r)/2+1, r);
    st[p] = min(st[2*p], st[2*p+1]); // RMQ -> min/max, RSQ -> +
}

void push(int p, int l, int r) {
    if (lz[p]) {
        st[p] = lz[p]; // RMQ -> update: = lz[p], increment: += lz[p]
        if (l != r)
            lz[2*p] = lz[2*p + 1] = lz[p]; // update: =, increment +=
        lz[p] = 0;
    }
}

int query(int i, int j, int p = 1, int l = 1, int r = n) {
    push(p, l, r);
    if (l > j or r < i)
        return INF; // RMQ -> INF, RSQ -> 0
    if (l >= i and j >= r)
        return st[p];
    return min(query(i, j, 2*p, l, (l+r)/2),
               query(i, j, 2*p + 1, (l+r)/2 + 1, r)); // RMQ -> min/max, RSQ -> +
}

void update(int i, int j, int v, int p = 1, int l = 1, int r = n) {
    push(p, l, r);
    if (l > j or r < i)
        return;
    if (l >= i and j >= r) {
        lz[p] = v;
        push(p, l, r);
        return;
    }
    update(i, j, v, 2*p, l, (l+r)/2);
    update(i, j, v, 2*p + 1, (l+r)/2 + 1, r);
    st[p] = min(st[2*p], st[2*p + 1]); // RMQ -> min/max, RSQ -> +
}
```

### Trie
```cpp
int trie[N][26], trien = 1;

int add(int u, char c){
    c-='a';
    if (trie[u][c]) return trie[u][c];
    return trie[u][c] = ++trien;
}

// To add a string s in the trie
void addString(string s) {
    int u = 1;
    for(char c : s) u = add(u, c);
}
```

### Union Find (Disjoint Set Union)
```cpp
int par[N], sz[N];

int find(int a) { 
    return par[a] == a ? a : par[a] = find(par[a]); 
}

void unite(int a, int b) {
    if ((a = find(a)) == (b = find(b))) return;
    if (sz[a] < sz[b]) swap(a, b);
    par[b] = a; sz[a] += sz[b];
}

// Initialize
void initDSU(int n) {
    for (int i = 1; i <= n; i++) par[i] = i, sz[i] = 1;
}
```

## Dynamic Programming

### Bitmasking DP
```cpp
// Optimal selection problem
// Buy each of k products exactly once over n days
// At most one product per day
void optimalSelection(int n, int k, vector<vector<int>>& price) {
    vector<vector<int>> f(1<<k, vector<int>(n, INF));
    
    for (int j = 0; j < k; j++) {
        f[1<<j][0] = price[j][0];
    }
    
    for (int i = 1; i < n; i++) {
        for (int mask = 0; mask < (1<<k); mask++) {
            f[mask][i] = f[mask][i - 1];
            for (int j = 0; j < k; j++) {
                if (mask & (1<<j)) {
                    f[mask][i] = min(f[mask][i],
                                   f[mask ^ (1<<j)][i - 1] + price[j][i]);
                }
            }
        }
    }
}

// From permutations to subsets
void permutationToSubsets(int n) {
    vector<vector<int>> f(1<<n, vector<int>(n));
    
    for (int mask = 1; mask < (1 << n); mask++) {
        for (int i = 0; i < n; i++) {
            if (mask & (1 << i)) {
                for (int j = 0; j < n; j++) {
                    if (mask & (1 << j) and i != j)
                        f[mask][i] = min(f[mask][i], 
                                       f[mask ^ (1<<i)][j] + cost[i][j]);
                }
            }
        }
    }
}
```

### Divide and Conquer Optimization
```cpp
int n, maxj;
int dp[N][J], a[N][J];

int cost(int i, int j) {
    // Define cost function
    return 0;
}

void calc(int l, int r, int j, int kmin, int kmax) {
    int m = (l + r) / 2;
    dp[m][j] = LINF;
    for (int k = kmin; k <= kmax; ++k) {
        ll v = dp[k][j - 1] + cost(k, m);
        if (v < dp[m][j])
            a[m][j] = k, dp[m][j] = v;
    }
    if (l < r) {
        calc(l, m, j, kmin, a[m][j]);
        calc(m + 1, r, j, a[m][j], kmax);
    }
}

void divideConquerDP() {
    for (int j = 2; j <= maxj; ++j)
        calc(1, n, j, 1, n);
}
```

### Knapsack
```cpp
// 0-1 Knapsack
int knapsack(int W, int n, int wt[], int val[]) {
    vector<vector<int>> dp(n+1, vector<int>(W+1));
    
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= W; j++) {
            if (i == 0 || j == 0) {
                dp[i][j] = 0;
            } else if (wt[i-1] <= j) {
                dp[i][j] = max(dp[i-1][j], dp[i-1][j-wt[i-1]] + val[i-1]);
            } else {
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    return dp[n][W];
}
```

### Longest Increasing Subsequence
```cpp
int longestIncreasingSubsequence(vector<int>& a) {
    int n = a.size();
    vector<int> dp(n, 1);
    
    for (int i = 0; i < n; i++) {
        if (i > 0 && a[i] > a[i-1]) {
            dp[i] = max(dp[i], dp[i-1] + 1);
        }
    }
    
    return *max_element(dp.begin(), dp.end());
}
```

### Longest Common Subsequence
```cpp
int longestCommonSubsequence(vector<int>& a, vector<int>& b) {
    int n = a.size(), m = b.size();
    vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
    
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (a[i-1] == b[j-1])
                dp[i][j] = dp[i-1][j-1] + 1;
            else
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }
    
    return dp[n][m];
}
```

### Sum Over Subsets (SOS) DP
```cpp
void sosDP(int N, vector<int>& A, vector<int>& F) {
    for(int i = 0; i < (1<<N); ++i)
        F[i] = A[i];
        
    for(int i = 0; i < N; ++i)
        for(int mask = 0; mask < (1<<N); ++mask) {
            if(mask & (1<<i))
                F[mask] += F[mask^(1<<i)];
        }
}
```


## Graph Algorithms

### DFS (Depth-First Search)
```cpp
vector<vector<int>> adj;
vector<bool> visited;

void dfs(int u) {
    visited[u] = true;
    for (int v : adj[u])
        if (!visited[v])
            dfs(v);
}
```

### BFS (Breadth-First Search)
```cpp
vector<vector<int>> adj;
vector<int> d, p, visited;

void bfs(int s, int n) {
    d.assign(n, 0);
    p.assign(n, -1);
    visited.assign(n, false);
    
    queue<int> q;
    q.push(s);
    visited[s] = true;
    
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        
        for (auto v: adj[u]) {
            if (!visited[v]) {
                visited[v] = true;
                d[v] = d[u] + 1;
                p[v] = u;
                q.push(v);
            }
        }
    }
}
```

### Topological Sort (Kahn's Algorithm)
```cpp
vector<int> adj[N];
int inc[N];

void topologicalSort(int n) {
    queue<int> q;
    
    for (int i = 1; i <= n; ++i) 
        if (inc[i] <= 1) q.push(i);
    
    while (!q.empty()) {
        int u = q.front(); q.pop();
        
        for (int v : adj[u])
            if (inc[v] > 1 and --inc[v] <= 1)
                q.push(v);
    }
}
```

### Articulation Points and Bridges
```cpp
int n, timer;
vector<vector<int>> adj;
vector<bool> visited;
vector<int> tin, low;

void dfs(int v, int p = -1) {
    visited[v] = true;
    tin[v] = low[v] = timer++;
    
    for (int to : adj[v]) {
        if (to == p) continue;
        
        if (visited[to])
            low[v] = min(low[v], tin[to]);
        else {
            dfs(to, v);
            low[v] = min(low[v], low[to]);
            if (low[to] > tin[v])
                IS_BRIDGE(v, to);
        }
    }
}

void find_bridges() {
    timer = 0;
    visited.assign(n, false);
    tin.assign(n, -1);
    low.assign(n, -1);
    
    for (int i = 0; i < n; ++i)
        if (!visited[i])
            dfs(i);
}
```

### Shortest Path - Bellman-Ford
```cpp
void bellmanFord(int n, int m, vector<Edge>& edges, int start) {
    vector<int> d(n, INF);
    d[start] = 0;
    
    while (true) {
        bool any = false;
        for (int j = 0; j < m; j++) {
            if (d[edges[j].a] < INF && d[edges[j].b] > d[edges[j].a] + edges[j].cost) {
                d[edges[j].b] = d[edges[j].a] + edges[j].cost;
                any = true;
            }
        }
        if (!any) break;
    }
}
```

### Shortest Path - Dijkstra
```cpp
const int INF = 1000000000;
vector<vector<pair<int, int>>> adj;

void dijkstra(int s, vector<int>& d, vector<int>& p) {
    int n = adj.size();
    d.assign(n, INF);
    p.assign(n, -1);
    d[s] = 0;
    
    using ii = pair<int, int>;
    priority_queue<ii, vector<ii>, greater<ii>> q;
    q.push({0, s});
    
    while (!q.empty()) {
        int v = q.top().second;
        int d_v = q.top().first;
        q.pop();
        
        if (d_v != d[v]) continue;
        
        for (auto edge : adj[v]) {
            int to = edge.first;
            int len = edge.second;
            
            if (d[v] + len < d[to]) {
                d[to] = d[v] + len;
                p[to] = v;
                q.push({d[to], to});
            }
        }
    }
}
```

### Floyd-Warshall
```cpp
void floydWarshall(int n, vector<vector<int>>& adj) {
    for (int k = 0; k < n; ++k)
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);
}
```

### 0-1 BFS
```cpp
void zeroOneBFS(int s, int n, vector<vector<pair<int, int>>>& adj) {
    vector<int> d(n, INF);
    d[s] = 0;
    deque<int> q;
    q.push_front(s);
    
    while (!q.empty()) {
        int u = q.front();
        q.pop_front();
        
        for (auto edge : adj[u]) {
            int v = edge.first;
            int w = edge.second;
            
            if (d[v] > d[u] + w) {
                d[v] = d[u] + w;
                if (w == 1)
                    q.push_back(v);
                else
                    q.push_front(v);
            }
        }
    }
}
```

### Minimum Spanning Tree - Kruskal
```cpp
struct Edge {
    int u, v, weight;
    bool operator<(Edge const& other) {
        return weight < other.weight;
    }
};

int kruskal(int n, vector<Edge>& edges) {
    sort(edges.begin(), edges.end());
    
    vector<int> parent(n);
    iota(parent.begin(), parent.end(), 0);
    
    function<int(int)> find = [&](int x) {
        return parent[x] == x ? x : parent[x] = find(parent[x]);
    };
    
    int cost = 0;
    for (Edge e : edges) {
        int u = find(e.u), v = find(e.v);
        if (u != v) {
            parent[u] = v;
            cost += e.weight;
        }
    }
    
    return cost;
}
```

### Lowest Common Ancestor
```cpp
const int N = 1e6, M = 25;
int anc[M][N], h[N], rt;

void buildLCA(int n) {
    anc[0][rt] = rt;
    for (int i = 1; i < M; ++i)
        for (int j = 1; j <= n; ++j)
            anc[i][j] = anc[i-1][anc[i-1][j]];
}

int lca(int u, int v) {
    if (h[u] < h[v]) swap(u, v);
    
    for (int i = M-1; i >= 0; --i) 
        if (h[u] - (1<<i) >= h[v])
            u = anc[i][u];
    
    if (u == v) return u;
    
    for (int i = M-1; i >= 0; --i) 
        if (anc[i][u] != anc[i][v])
            u = anc[i][u], v = anc[i][v];
    
    return anc[0][u];
}
```

### Strongly Connected Components (Kosaraju)
```cpp
vector<int> adj[N], adjt[N];
int n, ordn, cnt, vis[N], ord[N], cmp[N];

void dfs(int u) {
    vis[u] = 1;
    for (auto v : adj[u]) 
        if (!vis[v]) dfs(v);
    ord[ordn++] = u;
}

void dfst(int u) {
    cmp[u] = cnt, vis[u] = 0;
    for (auto v : adjt[u]) 
        if (vis[v]) dfst(v);
}

void kosaraju() {
    for (int i = 1; i <= n; ++i) 
        if (!vis[i]) dfs(i);
    
    for (int i = ordn-1; i >= 0; --i) 
        if (vis[ord[i]]) cnt++, dfst(ord[i]);
}
```


## String Algorithms

### Knuth-Morris-Pratt (KMP)
```cpp
char s[N], p[N];
int b[N], n, m;

void kmppre() {
    b[0] = -1;
    for (int i = 0, j = -1; i < m; b[++i] = ++j)
        while (j >= 0 && p[i] != p[j])
            j = b[j];
}

void kmp() {
    for (int i = 0, j = 0; i < n;) {
        while (j >= 0 && s[i] != p[j]) j = b[j];
        i++, j++;
        if (j == m) {
            // match found at position i-j
            j = b[j];
        }
    }
}
```

### KMP Automaton
```cpp
const int N = 1e5 + 5;
int cnt, nxt[N+1][26];

void prekmp(string &p) {
    nxt[0][p[0] - 'a'] = 1;
    for(int i = 1, j = 0; i <= p.size(); i++) {
        for(int c = 0; c < 26; c++) nxt[i][c] = nxt[j][c];
        if(i == p.size()) continue;
        nxt[i][p[i] - 'a'] = i+1;
        j = nxt[j][p[i] - 'a'];
    }
}

void kmpAutomaton(string &s, string &p) {
    for(int i = 0, j = 0; i < s.size(); i++) {
        j = nxt[j][s[i] - 'a'];
        if(j == p.size()) cnt++; // match at position i - j + 1
    }
}
```

### Rabin-Karp
```cpp
const int B = 31;
typedef unsigned long long ull;

void rabinKarp(string &s, string &p) {
    int n = s.length(), m = p.length();
    if (n < m) return;
    
    ull hp = 0, hs = 0, E = 1;
    
    for (int i = 0; i < m; ++i) {
        hp = ((hp * B) % MOD + p[i]) % MOD;
        hs = ((hs * B) % MOD + s[i]) % MOD;
        E = (E * B) % MOD;
    }
    
    if (hs == hp) {
        // matching at position 0
    }
    
    for (int i = m; i < n; ++i) {
        hs = ((hs * B) % MOD + s[i]) % MOD;
        hs = (hs - s[i-m] * E % MOD + MOD) % MOD;
        if (hs == hp) {
            // matching at position i-m+1
        }
    }
}
```

### Manacher (Longest Palindromic Substring)
```cpp
int lps[2*N+5];

int manacher(string s) {
    int n = s.length();
    string p(2*n+3, '#');
    p[0] = '^';
    for (int i = 0; i < n; i++) p[2*(i+1)] = s[i];
    p[2*n+2] = '$';
    
    int k = 0, r = 0, m = 0;
    int l = p.length();
    
    for (int i = 1; i < l; i++) {
        int o = 2*k - i;
        lps[i] = (r > i) ? min(r-i, lps[o]) : 0;
        
        while (p[i + 1 + lps[i]] == p[i - 1 - lps[i]]) lps[i]++;
        
        if (i + lps[i] > r) k = i, r = i + lps[i];
        m = max(m, lps[i]);
    }
    
    return m;
}
```


## Mathematics

### Basic Math Functions
```cpp
// GCD and LCM
ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
ll lcm(ll a, ll b) { return a/gcd(a, b)*b; }

// Fast Exponentiation
ll power(ll a, ll b, ll m = MOD) {
    ll ans = 1;
    while (b) {
        if (b & 1) ans = (ans * a) % m;
        a = (a * a) % m;
        b >>= 1;
    }
    return ans;
}

// Modular Inverse
ll modinv(ll n, int p) {
    return power(n, p - 2, p);
}

// Combination nCr % p
ll f[N];
void factorial(int n) {
    f[0] = 1;
    for (int i = 1; i <= n; i++)
        f[i] = (f[i - 1] * i) % MOD;
}

ll C(ll n, int r, int p) {
    if (n < r) return 0;
    if (r == 0) return 1;
    return (f[n] * modinv(f[r], p) % p * modinv(f[n - r], p) % p) % p;
}
```

### Matrix Exponentiation
```cpp
vector<vector<ll>> matmul(vector<vector<ll>> a, vector<vector<ll>> b) {
    int n = a.size();
    vector<vector<ll>> ans(n, vector<ll>(n));
    
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            for (int k = 0; k < n; k++)
                ans[i][j] = (ans[i][j] + a[i][k] * b[k][j]) % MOD;
    
    return ans;
}

vector<vector<ll>> matpow(vector<vector<ll>> a, ll n) {
    if (n == 0) return vector<vector<ll>>(1, vector<ll>(1, 1));
    if (n == 1) return a;
    
    vector<vector<ll>> b = matpow(a, n/2);
    b = matmul(b, b);
    if (n % 2) b = matmul(b, a);
    
    return b;
}
```

### Advanced Math
```cpp
// Multiplicative Inverse for all 1..N-1 in O(N)
ll inv[N];
void precomputeInverses(int n) {
    inv[1] = 1;
    for(int i = 2; i < n; ++i)
        inv[i] = MOD - (MOD / i) * inv[MOD % i] % MOD;
}

// Catalan Numbers
ll cat[N];
void precomputeCatalan(int n) {
    cat[0] = 1;
    for(int i = 1; i < n; i++)
        cat[i] = 2ll * (2ll * i - 1) * inv[i + 1] % MOD * cat[i - 1] % MOD;
}

// Floor division optimization
// floor(n/i) has at most 2*sqrt(n) different values
void floorDivision(int n) {
    for(int l = 1, r; l <= n; l = r + 1){
        r = n / (n / l);
        // floor(n / i) has the same value for l <= i <= r
    }
}
```

### Sieve of Eratosthenes
```cpp
vector<int> p(N);
vector<int> primes;

void sieve() {
    for (ll i = 2; i < N; ++i) {
        if (!p[i]) {
            for (ll j = i*i; j < N; j += i) 
                p[j] = 1;
            primes.push_back(i);
        }
    }
}
```

### Extended Euclidean Algorithm
```cpp
void extendedGCD(ll a, ll b, ll &x, ll &y) {
    if (b) {
        extendedGCD(b, a%b, y, x);
        y -= x*(a/b);
    } else {
        x = 1, y = 0;
    }
}

bool diophantine(ll a, ll b, ll c, ll &x, ll &y){
    extendedGCD(abs(a), abs(b), x, y);
    ll g = abs(__gcd(a, b));
    
    if(c % g) return false;
    
    x *= c / g;
    y *= c / g;
    if(a < 0) x = -x;
    if(b < 0) y = -y;
    
    return true;
}
```

### Chinese Remainder Theorem
```cpp
bool crt_auxiliary(ll a, ll b, ll m1, ll m2, ll &ans){
    ll x, y;
    if(!diophantine(m1, m2, b - a, x, y)) return false;
    
    ll lcm = m1 / __gcd(m1, m2) * m2;
    ans = ((a + x % (lcm / m1) * m1) % lcm + lcm) % lcm;
    
    return true;
}

bool crt(int n, ll a[], ll b[], ll &ans){
    if(!b[0]) return false;
    
    ans = a[0] % b[0];
    ll l = b[0];
    
    for(int i = 1; i < n; i++){
        if(!b[i]) return false;
        if(!crt_auxiliary(ans, a[i] % b[i], l, b[i], ans)) return false;
        l *= (b[i] / __gcd(b[i], l));
    }
    
    return true;
}
```

### Euler's Totient Function
```cpp
// Single value
int eulerPhi(int n) {
    int result = n;
    
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            while (n % i == 0) n /= i;
            result -= result / i;
        }
    }
    
    if (n > 1) result -= result / n;
    return result;
}

// Precompute for range
int phi[N];
void totient() {
    for (int i = 1; i < N; ++i) phi[i] = i;
    for (int i = 2; i < N; i += 2) phi[i] >>= 1;
    
    for (int j = 3; j < N; j += 2) {
        if (phi[j] == j) {
            phi[j]--;
            for (int i = 2*j; i < N; i += j) 
                phi[i] = phi[i]/j*(j-1);
        }
    }
}
```

### Prime Factorization
```cpp
vector<int> primeFactors(int n) {
    vector<int> factors;
    int ind = 0, pf = primes[0];
    
    while (pf*pf <= n) {
        while (n % pf == 0) {
            n /= pf;
            factors.push_back(pf);
        }
        pf = primes[++ind];
    }
    
    if (n != 1) factors.push_back(n);
    return factors;
}
```


## Miscellaneous

### Bitset Operations
```cpp
// Iterate through subsets of a set x
void iterateSubsets(int x) {
    int b = 0;
    do {
        // process subset b
    } while (b = (b - x) & x);
}
```

### Builtin Functions
```cpp
__builtin_ctz(x)        // trailing zeroes
__builtin_clz(x)        // leading zeroes  
__builtin_popcount(x)   // number of bits set
__builtin_ffs(x)        // index of LSB + 1 (0 if x==0)

// For long long, add 'll' suffix: __builtin_clzll(x)
```

### Quick Sort
```cpp
void quickSort(vector<int> &v, int left, int right) {
    if (left >= right) return;
    
    int pivot = v[left];
    int i = left, j = right;
    
    while (i < j) {
        while (i < j && v[j] >= pivot) j--;
        if (i < j) v[i++] = v[j];
        
        while (i < j && v[i] <= pivot) i++;
        if (i < j) v[j--] = v[i];
    }
    
    v[i] = pivot;
    quickSort(v, left, i - 1);
    quickSort(v, i + 1, right);
}

int quickSelect(vector<int> &v, int left, int right, int k) {
    if (left >= right) return v[left];
    
    int pivot = v[left];
    int i = left, j = right;
    
    while (i < j) {
        while (i < j && v[j] >= pivot) j--;
        if (i < j) v[i++] = v[j];
        
        while (i < j && v[i] <= pivot) i++;
        if (i < j) v[j--] = v[i];
    }
    
    v[i] = pivot;
    
    if (i == k) return v[i];
    else if (i < k) return quickSelect(v, i + 1, right, k);
    else return quickSelect(v, left, i - 1, k);
}
```

### Sliding Window Maximum
```cpp
vector<int> maxSlidingWindow(vector<int>& arr, int k) {
    deque<int> dq;
    vector<int> result;
    
    for (int i = 0; i < arr.size(); i++) {
        // Remove elements outside window
        while (!dq.empty() && dq.front() <= i - k)
            dq.pop_front();
        
        // Remove smaller elements
        while (!dq.empty() && arr[i] >= arr[dq.back()])
            dq.pop_back();
        
        dq.push_back(i);
        
        // Add to result when window is complete
        if (i >= k - 1)
            result.push_back(arr[dq.front()]);
    }
    
    return result;
}
```

### Merge Sort with Inversion Count
```cpp
int mergeSort(vector<int>& v, int l, int r, vector<int>& ans) {
    if (l == r) return 0;
    
    int mid = (l + r) / 2;
    int inv = 0;
    
    inv += mergeSort(v, l, mid, ans);
    inv += mergeSort(v, mid + 1, r, ans);
    
    int i = l, j = mid + 1, k = l;
    
    while (i <= mid || j <= r) {
        if (i <= mid && (j > r || v[i] <= v[j])) {
            ans[k++] = v[i++];
        } else {
            ans[k++] = v[j++];
            inv += (mid - i + 1); // Count inversions
        }
    }
    
    for (int i = l; i <= r; i++) v[i] = ans[i];
    return inv;
}
```


## Advanced Math Formulas

### Combinatorial Identities
```cpp
// Sum formulas
// Σ(k=0 to n) k² = n(n+1)(2n+1)/6
// Σ(k=0 to n) k³ = n²(n+1)²/4
// Σ(k=0 to n) k⁴ = (6n⁵ + 15n⁴ + 10n³ - n)/30
// Σ(k=0 to n) xᵏ = (xⁿ⁺¹ - 1)/(x - 1)

// Binomial identities
// C(n,k) = n!/(k!(n-k)!)
// C(n,k) = C(n-1,k) + C(n-1,k-1)
// C(n,k) = C(n,n-k)
// Σ(k=1 to n) k*C(n,k) = n*2^(n-1)
```

### Stirling Numbers of Second Kind
```cpp
// Number of ways to partition n objects into k non-empty subsets
long long stirling2(int n, int k) {
    if (n == 0 && k == 0) return 1;
    if (n == 0 || k == 0) return 0;
    if (k == 1 || k == n) return 1;
    
    // S(n,k) = k*S(n-1,k) + S(n-1,k-1)
    vector<vector<long long>> dp(n+1, vector<long long>(k+1, 0));
    
    dp[0][0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= min(i, k); j++) {
            dp[i][j] = j * dp[i-1][j] + dp[i-1][j-1];
        }
    }
    
    return dp[n][k];
}
```

### Burnside's Lemma
```cpp
// |X/G| = (1/|G|) * Σ(g∈G) |X^g|
// where X^g is the set of elements fixed by group element g

// Example: Necklace coloring with N beads and K colors
long long necklaceColoring(int n, int k) {
    long long result = 0;
    
    for (int i = 1; i <= n; i++) {
        result += power(k, __gcd(i, n));
    }
    
    return result / n;
}
```

### Numerical Integration (RK4)
```cpp
// Runge-Kutta 4th order method
// To integrate dy/dt = f(t, y) with y₀ = y(t₀)
double rk4Step(double t, double y, double h, function<double(double, double)> f) {
    double k1 = f(t, y);
    double k2 = f(t + h/2, y + h*k1/2);
    double k3 = f(t + h/2, y + h*k2/2);
    double k4 = f(t + h, y + h*k3);
    
    return y + (h/6) * (k1 + 2*k2 + 2*k3 + k4);
}
```

## Time Complexities Quick Reference

| Algorithm | Time Complexity | Space Complexity |
|-----------|----------------|------------------|
| DFS/BFS | O(V + E) | O(V) |
| Dijkstra | O((V + E) log V) | O(V) |
| Floyd-Warshall | O(V³) | O(V²) |
| Bellman-Ford | O(VE) | O(V) |
| Kruskal's MST | O(E log E) | O(V) |
| Segment Tree | O(log n) query/update | O(n) |
| Union-Find | O(α(n)) amortized | O(n) |
| KMP | O(n + m) | O(m) |
| Manacher | O(n) | O(n) |
| Binary Search | O(log n) | O(1) |
| Quick Sort | O(n log n) average | O(log n) |
| Merge Sort | O(n log n) | O(n) |

This reference guide contains the essential algorithms and data structures commonly used in competitive programming.
Each implementation is optimized for contest conditions with clear, concise code that's easy to remember and modify during competitions.
