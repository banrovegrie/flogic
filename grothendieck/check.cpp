// C++ implementation to check
// if three points form a triangle

#include <bits/stdc++.h>
using namespace std;

// Function to check if three
// points make a triangle
void checkTriangle(int x1, int y1, int x2,
				int y2, int x3, int y3)
{

	// Calcultion the area of
	// triangle. We have skipped
	// multiplication with 0.5
	// to avoid floating point
	// computations
	int a = x1 * (y2 - y3)
			+ x2 * (y3 - y1)
			+ x3 * (y1 - y2);

	// Condition to check if
	// area is not equal to 0
	if (a == 0)
		cout << "No";
	else
		cout << "Yes";
}

// Driver Code
int main()
{
	int x1 = 1, x2 = 4, x3 = 2,
		y1 = 1, y2 = 1, y3 = 4;
	checkTriangle(x1, y1, x2,
				y2, x3, y3);
	return 0;
}
