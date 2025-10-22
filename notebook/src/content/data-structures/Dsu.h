/**
 * Author: Amul Agrawal
 * Date: 2022-09-18
 * Description: DSU with rollback
 * Time: $O(\alpha(N))$
 */
#pragma once

struct DSU {
	int sets; vi p, s;
	stack<pii> ss, sp;
	DSU(int n) : p(n, -1), s(n, 1), sets(n) {}
	bool IsSameSet(int a, int b) { return find(a) == find(b); }
	int find(int x) {return p[x] == -1 ? x : p[x] = find(p[x]);}
	bool join(int a, int b) {
		a = find(a), b = find(b);
		if (a == b) return false;
		if (s[a] < s[b]) swap(a, b);
		ss.push({a, s[a]}); sp.push({b, p[b]});
		sets--; s[a] += s[b]; p[b] = a; return true;
	}
	int time() {return sz(ss);}
	void rollback(int t) {
		while(time() > t) {
			p[sp.top().first] = sp.top().second; sp.pop();
			s[ss.top().first] = ss.top().second; ss.pop();
		}
	}
};
