/*
	SOS DP
*/
// O(N * 2^N)
// A[i] = initial values
// Calculate F[i] = Sum of A[j] for j subset of i
for(int i = 0; i < (1 << N); i++)
	F[i] = A[i];
for(int i = 0; i < N; i++)
	for(int j = 0; j < (1 << N); j++)
		if(j & (1 << i))
			F[j] += F[j ^ (1 << i)];

/*
	From permutations to subsets
*/
pair<int,int> best[1<<N];
best[0] = {1,0};
// stuff ...
for (int s = 1; s < (1<<n); s++) {
    // initial value: n+1 rides are needed
    best[s] = {n+1,0};
    for (int p = 0; p < n; p++) {
        if (s&(1<<p)) {
            auto option = best[s^(1<<p)];
            if (option.second+weight[p] <= x) {
                // add p to an existing ride
                option.second += weight[p];
            } else {
                // reserve a new ride for p
                option.first++;
                option.second = weight[p];
            }
            best[s] = min(best[s], option);
        }
    }
}

/* 
	Optimal selection
*/

for (int x = 0; x < k; x++) {
    total[1<<x][0] = price[x][0];
}
// Then, the recurrence translates into the following code:

for (int d = 1; d < n; d++) {
    for (int s = 0; s < (1<<k); s++) {
        total[s][d] = total[s][d-1];
        for (int x = 0; x < k; x++) {
            if (s&(1<<x))
                total[s][d] = min(total[s][d],
                total[s^(1<<x)][d-1]+price[x][d]);
        }
    }
}