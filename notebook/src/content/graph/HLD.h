/**
 * Author: Benjamin Qi, Oleksandr Kulkov, chilli
 * Date: 2020-01-12
 * Description: Heavy Light Decomposition
 * License: CC0
 * Source: Path updates and Query in a Tree. Get Segment Tree first.
 * Time: O(logN * Time taken by Range Query DS)
 * Status: stress-tested against old HLD
 */
#pragma once

// requires a segment tree with init function
class HLD {
    SegmentTrees sgt; vector<vi> adj;
    vi sz, par, head, sc, st, ed;
    int t, n;
public:
    HLD(vector<vector<int>> &adj1,int n1): sz(n1+1), par(n1+1),
			 head(n1+1), sc(n1+1), st(n1+1), ed(n1+1) {
        n = n1; adj = adj1; t = 0;
    }
    void dfs_sz(int x,int p = 0) {
        sz[x] = 1; par[x] = p; head[x] = x;
        for(auto nx : adj[x]) {
            if(nx == p) continue;
            dfs_sz(nx, x);
            sz[x] += sz[nx];
            if(sz[nx] > sz[sc[x]]) sc[x] = nx;
        }
    }
    void dfs_hld(int x,int p = 0) {
        st[x] = t++;
        if(sc[x]) {
            head[sc[x]] = head[x];
            dfs_hld(sc[x], x);
        }
        for(auto nx : adj[x]) {
            if(nx == p or nx == sc[x]) continue;
            dfs_hld(nx, x);
        }
        ed[x] = t - 1;
    }
    void build(int base = 1) {
        dfs_sz(base);
        dfs_hld(base);
        sgt.init(t);
    }   
    bool anc(int x,int y) {
        if(x == 0) return true; if(y == 0) return false;
        return (st[x] <= st[y] and ed[x] >= ed[y]);
    }
    int lca(int x,int y) {
        if(anc(x, y)) return x; if(anc(y, x)) return y;
        while(!anc(par[head[x]], y)) x = par[head[x]];
        while(!anc(par[head[y]], x)) y = par[head[y]];
        x = par[head[x]]; y = par[head[y]];
        // one will overshoot the lca and the other will reach lca.
        return anc(x, y) ? y : x;
    }
    void update_up(int x,int p,ll add) {
        while(head[x] != head[p]) {
            sgt.update(st[head[x]], st[x], add, 0, t-1);
            x = par[head[x]];
        }
        sgt.update(st[p], st[x], add, 0, t - 1);
    }
    void range_update(int u,int v,T add) {
        int l =  lca(u, v);
        update_up(u, l, add); update_up(v, l, add);
        update_up(l, l, -add);
    }
    T query_up(int x,int p) {
        T ans = 0;
        while(head[x] != head[p]) {
            ans = min(ans, sgt.query(st[head[x]], st[x], 0, t-1));
            x = par[head[x]];
        }
        ans = min(ans, sgt.query(st[p], st[x], 0, t - 1));
        return ans;
    }
    T range_min(int u,int v) {
        int l = lca(u, v);
        return min(query_up(u, l), query_up(v, l));
    }
};
