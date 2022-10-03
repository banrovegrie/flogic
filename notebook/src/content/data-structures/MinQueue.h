/**
 * Author: Amul Agrawal
 * Date: 2022-09-18
 * Description: Minimum Queue Applications
 * Time: $O(1)$ push pop etc.
 */
#pragma once

template<class T>
struct MinQueue {
	deque<pair<T, T>> q; 
  int ca = 0, cr = 0, plus = 0, sze = 0;
	void push(T x) {
    x -= plus;
		// change '>' to '<' and you get max-queue
		while (!q.empty() && q.back().first > x)
		  q.pop_back();
		q.push_back({x, ca}); ca++; sze++;
	}
	T pop() {
		T re = 0;
		if (!q.empty() && q.front().second == cr) {
			re = q.front().first; q.pop_front();
		}
		cr++; sze--; return re + plus;
	}
  // Returns minimum in the queue
	T min() { return q.front().first + plus; }
  int size() { return sze; }
  // Adds x to every element in the queue
  void add(int x) { plus += x; }
};