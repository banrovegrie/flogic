/**
 * Author: Arjo
 * Date: Unknown
 * License: CC0
 * Description: $C_k = \sum_{i\otimes{j} = k} A_i B_j$
 * Usage: Apply the transform, point multiply and invert 
 * Time: O(N \log N) 
 * Status: untested
 */
void WalshHadamard(Poly &P, bool invert) {
  for (int len = 1; 2 * len <= sz(P); len <<= 1) {
    for (int i = 0; i < sz(P); i += 2 * len) {
      rep(j, 0, len) {
        auto u = P[i + j], v = P[i + len + j];
        P[i + j] = u + v, P[i + len + j] = u - v; // XOR
      }
    }
  }
  if (invert) for (auto &x : P) x /= sz(P);
}