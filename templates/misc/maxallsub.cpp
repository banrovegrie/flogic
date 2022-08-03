/*
    Finding the maximum for all subarrays of fixed length
*/
std::deque<int> Q(k);
int i = 0;
for (; i < k; i++)
{
		while(!Q.empty() and arr[i] >= arr[Q.back()])
				Q.pop_back();
}

for (; i < n; i++) 
{
    cout << arr[Q.front()] << " ";
    while (!Q.empty() && Q.front() <= i - k)
        Q.pop_front();
    while ((!Q.empty()) && arr[i] >= arr[Q.back()])
        Q.pop_back();
    Q.push_back(i);
}
cout << arr[Q.front()];