/**
 * Author: Amul Agrawal
 * Description: Representing each number in 2D vector space,
 * finding basis of that vector space. total elements = $2^{sz}$. 
 * ways to represent $x$ is $2^{n-sz}$, unique basis combination for every subset.
 * Time: O(N*log(A[i]))
 */
#pragma once

int lb[31], tim[31]; // T = r
void insert(int x, int T) {
	for (int i = 59; i >= 0 && x; i--) {
		if (x >> i & 1) {
			if (lb[i]) {
				if (T > tim[i]) swap(lb[i], x), swap(T, tim[i]);
				x ^= lb[i];
			} else lb[i] = x, tim[i] = T, x = 0;
		}
	}
}