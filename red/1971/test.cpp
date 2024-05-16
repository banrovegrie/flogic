#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cassert>
#include <cstring>

// Driver code
int main()
{
	std::vector<int> v{ 0, 10 };

	// Print vector
	std::cout << "Vector contains :";
	for (int i = 0; i < v.size(); i++)
		std::cout << " " << v[i];
	std::cout << "\n";

	std::vector<int>::iterator upper1, upper2;

	// std :: upper_bound
	upper1 = std::upper_bound(v.begin(), v.end(), 0);
	upper2 = std::upper_bound(v.begin(), v.end(), 4);

	std::cout << "\nupper_bound for element 0 is at position : " 
			<< (upper1 - v.begin());
	std::cout << "\nupper_bound for element 4 is at position : "
			<< (upper2 - v.begin());

	return 0;
}
