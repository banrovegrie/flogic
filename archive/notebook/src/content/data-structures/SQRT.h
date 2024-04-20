/**
 * Author: Amul Agrawal
 * Date: 2022-09-18
 * Description: Square Root Decomposition
 * Time: Amul Knows
 */
#pragma once

const int N = 1e5 + 13, Q = 1e5 + 13, B = 500;
int S[N/B + 13][B + 13], len[N/B + 13], prv[N], nxt[N], st[N/B + 13], en[N/B + 13], A[N]; 
map<int,set<int>> pos; int n, q;

void add_link(int p,int val) {
    nxt[p] = val; prv[val] = p;
    if(p < 1 or p > n) return;
    int b = p / B;
    for(int i = st[b]; i <= en[b]; i++) {
        S[b][i - st[b] + 1] = nxt[i];
    }
    sort(S[b] + 1, S[b] + len[b] + 1);
}
// set A_x = y
void point_update(int x,int y) {
    // update the original link
    add_link(prv[x], nxt[x]); pos[A[x]].erase(x);
    // insert new links
    A[x] = y; pos[A[x]].insert(x);
    int pr = 0, nx = n + 1;
    if(*pos[A[x]].begin() != x) pr = *prev(pos[A[x]].find(x));
    if(*pos[A[x]].rbegin() != x) nx = *next(pos[A[x]].find(x));
    add_link(pr, x); add_link(x, nx);
}

int query_block(int s,int e,int k) {
    int ans = 0;
    for(int i = s; i <= e; i++) 
        ans += ((S[i] + len[i] + 1) - upper_bound(S[i] + 1, S[i] + len[i] + 1, k));
    return ans;
}

int query_elements(int s,int e,int k) {
    int ans = 0; 
    for(int i = s; i <= e; i++) 
        ans += (nxt[i] > k);
    return ans;
}

int range_query(int l,int r) {
    int lb = l / B, rb = r / B;
    if(lb == rb) return query_elements(l, r, r);
    return query_elements(l, en[lb], r) 
        + query_block(lb + 1, rb - 1, r)
        + query_elements(st[rb], r, r);
}
for(int i = 1; i <= n; i++) {
		nxt[i] = n + 1;
		if(!pos[A[i]].empty()) {
				prv[i] = *pos[A[i]].rbegin();
				nxt[prv[i]] = i;
		}
		pos[A[i]].insert(i);
}
for(int i = 1; i <= n; i++) {
		int b = i / B;
		if(!len[b]) 
				st[b] = i;
		en[b] = i;
		len[b]++;
		S[b][len[b]] = nxt[i]; 
}
for(int i = 0; i <= n/B; i++) {
		sort(S[i] + 1, S[i] + len[i] + 1);
}
