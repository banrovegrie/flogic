/**
 * Author: Amul Agrawal
 * Date: 2022-09-18
 * Description: Graph, adding edges, checking bp color
 * Time: $O(\alpha(N))$
 */
#pragma once

struct DSU {
	int sets; vi p, s, l;
	DSU(int n) : p(n, -1), s(n, 1), l(n, 0), sets(n) {}
	bool IsSameColor(int a,int b) {
		find(a); find(b); return l[a] == l[b]; 
	}
	bool IsSameSet(int a, int b) { return find(a) == find(b); }
	int find(int x) {
		if(p[x] == -1) return x;
		int y = find(p[x]); l[x] ^= l[p[x]]; return p[x] = y;
	}
	void join(int a, int b) {
		int ca = a, cb = b; a = find(a), b = find(b);
		if (a == b) return;
		if (s[a] < s[b]) swap(a, b);
		sets--; s[a] += s[b]; l[b] = 1 ^ l[ca] ^ l[cb]; p[b] = a;
	}
};
