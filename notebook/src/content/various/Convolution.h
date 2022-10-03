/**
 * Author: Amul Agrawal
 * Description: Getting different convolutions
 * Time: O(n 2^n)
 */
#pragma once

// Zeta/SOS, N*2^N
rep(i,0,M) 
  for(int mask = (1<<M) - 1; mask >= 0; mask--) 
    if((mask>>i)&1) 
      F[mask] += F[mask ^ (1 << i)];
// Rev mask loop and invert bit condition for superset sum

// Base from SOS
for(int i = M - 1; i >= 0; i--) 
		for(int mask = (1 << M) - 1; mask >= 0; mask--) 
			if((mask >> i)&1) 
				F[mask] -= F[mask ^ (1 << i)];
// Rev mask loop and invert condition for base from Sum over superset


// Mobius, F[s] = SUM(-1^{s/s'} * F[s']), N*2^N
// F[1011] = F[1011] - F[0011] - F[1001] - F[1010] + F[1000] ...
rep(i,0,M) rep(mask, 0, 1<<M) if((mask>>i)&1)
      F[mask] -= F[mask ^ (1 << i)];

// sos(mu(f(x))) = f(x) = mu(sos(f(x)))

// fog[s] = SUM(f[s']*g[s/s']), N^2 * 2^N
// Make fhat[][] = {0} and ghat[][] = {0}
rep(mask,0,1<<N) {
    fhat[__builtin_popcount(mask)][mask] = f[mask];
    ghat[__builtin_popcount(mask)][mask] = g[mask];
}
// Apply zeta transform on fhat[][] and ghat[][]
rep(i,0,N+1) rep(j,0,N) rep(mask,0,1<<N) if((mask>>j)&1) {
  fhat[i][mask] += fhat[i][mask ^ (1 << j)];
  ghat[i][mask] += ghat[i][mask ^ (1 << j)];
}
// Do the convolution and store into h[][] = {0}
rep(mask,0,(1<<N)) rep(i,0,N+1) rep(j,0,i+1)
            h[i][mask] += fhat[j][mask] * ghat[i - j][mask];
// Apply inverse SOS dp on h[][]
rep(i,0,N+1) rep(j,0,N) rep(mask,0,1<<N) if((mask>>j)&1)
  h[i][mask] -= h[i][mask ^ (1 << j)];

rep(mask,0,1<<N) fog[mask] = h[__builtin_popcount(mask)][mask];


