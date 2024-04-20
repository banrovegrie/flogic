/**
 * Author: Amul Agrawal
 * Date: 2022-09-18
 * Description: RMQ SegTree
 * Time: $O(\log(N))$
 */
#pragma once
const ll INF = 1e18;
struct node {
	ll x;
};

template<class T>
struct SegmentTrees {
	vector<node> st, lazy; 
  node def;
	SegmentTrees(int n) : st(4*n, {INF}), lazy(4*n, {INF}), def({INF}) {}
	inline node combine(node a, node b) {
		node ret; ret.x = min(a.x, b.x); return ret;
	}
	void push(int pos) {
		if(lazy[pos].x != INF) {
			st[pos*2] = lazy[pos]; st[pos*2 + 1] = lazy[pos];
			lazy[pos*2] = lazy[pos]; lazy[pos*2+1] = lazy[pos];
			lazy[pos] = def;
		}
	}
	void update(int l,int r,T val,int left,int right,int pos=1) {
		if(l > r) return;
		if(l==left && r==right) {
			st[pos].x = val; lazy[pos] = {val};
		} else {
			push(pos);
			int mid = (left + right)/2;
			update(l, min(r,mid), val, left, mid, pos*2);
			update(max(l,mid+1), r, val, mid+1, right, pos*2+1);
			st[pos] = combine(st[pos*2], st[pos*2+1]);
		}
	}
	node query(int l,int r,int left,int right,int pos=1) {
		if(l>r) return def;
		if(l==left && r==right) return st[pos];
		else {
			push(pos); int mid = (left + right)/2;
			return combine(query(l, min(r,mid), left, mid, pos*2), 
        query(max(l,mid+1), r, mid+1, right, pos*2+1));
		}
	}
};