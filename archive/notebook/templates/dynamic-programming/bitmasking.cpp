/*
    Optimal selection
*/

// We are given the prices of k products over n days, 
// and we want to buy each product exactly once. However,
// we are allowed to buy at most one product in a day. 
// What is the minimum total price?

// f[mask][i] = denote the minimum total price for buying 
// a subset mask of products by day i
for (int j = 0; j < k; j++) {
    f[1<<j][0] = price[j][0];
}

for (int i = 1; i < n; i++) {
    for (int mask = 0; mask < (1<<k); mask++) {
        f[mask][i] = f[mask][i - 1];
        for (int j = 0; j < k; j++) {
            if (mask & (1<<j)) {
                f[mask][i] = min(f[mask][i],
                f[mask ^ (1<<j)][i - 1]+price[j][i]);
            }
        }
    }
}

/*
    From permutations to subsets
*/

// Take input and initialize stuff with default values.
// Then, we have the following.

// f[mask][i] = denotes the case where for all possible permutations,
// wrt the subset mask, i is the last element of the permutation.
for (int mask = 1; mask < (1 << n); mask++) {
    for (int i = 0; i < n; i++) {
        if (mask & (1 << i)) {
            // You might be required to initialize stuff here.
            for (int j: adj[i]) {
            // or, f(int j = 0; j < n; j++) whatever is more suitable
                if (mask & (1 << j) and i != j)
                    f[mask][i] = min(f[mask][i], f[mask ^ (1<<i)][j] + cost[i][j]);
            }
        }
    }
}

// Answer might be f[(1<<n)-1][n] or something like min(f[(1<<n)-1][i]) for all i from 0 to n.