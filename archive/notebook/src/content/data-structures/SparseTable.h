/**
 * Author: Johan Sannemo, pajenegod
 * Date: 2015-02-06
 * License: CC0
 * Source: Folklore
 * Description: Range Minimum Queries on an array. Returns
 * min(V[a], V[a + 1], ... V[b - 1]) in constant time.
 * Usage:
 *  RMQ rmq(values);
 *  rmq.query(inclusive, exclusive);
 * Time: $O(|V| \log |V| + Q)$
 * Status: stress-tested
 */
#pragma once

template<class T> 
struct SparseTable {
    T (*op)(T, T);
    vi log2s; vector<vector<T>> st;
    SparseTable (const vector<T>& arr, T (*op)(T, T)) 
			: op(op), log2s(sz(arr)+1), st(sz(arr)) {
        rep(i,2,sz(log2s)) { log2s[i] = log2s[i/2] + 1; }
				rep(i,0,sz(arr)) {
					st[i].assign(log2s[sz(arr) - i] + 1); 
					st[i][0] = arr[i];
				}
				rep(p, 1, log2s[sz(arr)] + 1) rep(i,0,sz(arr)) 
					if(i+(1<<p) <= sz(arr)) {
						st[i][p] = op(st[i][p-1], st[i+(1<<(p-1))][p-1]);
				} 
    }
    T query (int l, int r) {
        int p = log2s[r-l+1]; 
				return op(st[l][p], st[r-(1<<p)+1][p]);
    }
};
