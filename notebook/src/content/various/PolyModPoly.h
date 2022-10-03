/**
 * Author: BenQ
 * Date: 2022-10-3
 * Description: Poly Mod Poly
 */
#pragma once
#define rsz resize
poly RSZ(poly p, int x) { p.rsz(x); return p; }
poly rev(poly p) { reverse(all(p)); return p; }
poly inv(poly A, int n) { // Q-(1/Q-A)/(-Q^{-2})
	poly B{1/A[0]};
	while (sz(B) < n) {
		int x = 2*sz(B);
		B = RSZ(2*B-conv(RSZ(A,x),conv(B,B)),x); } // fft
	return RSZ(B,n);
}
pair<poly,poly> divi(const poly& f, const poly& g) { 
	if (sz(f) < sz(g)) return {{},f};
	auto q = mul(inv(rev(g),sz(f)-sz(g)+1),rev(f));
	q = rev(RSZ(q,sz(f)-sz(g)+1));
	auto r = RSZ(f-mul(q,g),sz(g)-1); return {q,r};
}
typedef vector<mi> vmi; // mi = modular int
struct MultipointEval {
	poly stor[1<<18];
	void prep(vmi v, int ind = 1) { // v -> places to evaluate at
		if (sz(v) == 1) { stor[ind] = {-v[0],1}; return; }
		int m = sz(v)/2;
		prep(vmi(begin(v),begin(v)+m),2*ind);
		prep(vmi(m+all(v)),2*ind+1);
		stor[ind] = conv(stor[2*ind],stor[2*ind+1]);
	}
	vmi res;
	void eval(vmi v, int ind = 1) {
		v = divi(v,stor[ind]).s;
		if (sz(stor[ind]) == 2) { res.pb(v[0]); return; }
		eval(v,2*ind); eval(v,2*ind+1);
	}
};