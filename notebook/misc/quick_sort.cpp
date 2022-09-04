/* 
    Implement Quick Sort to sort an array of 
    integers in ascending order.
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void quick_sort(vector<int> &v, int left, int right)
{
    if (left >= right)
        return;
    int pivot = v[left];
    int i = left, j = right;
    while (i < j)
    {
        while (i < j && v[j] >= pivot)
            j--;
        if (i < j)
            v[i++] = v[j];
        while (i < j && v[i] <= pivot)
            i++;
        if (i < j)
            v[j--] = v[i];
    }
    v[i] = pivot;
    quick_sort(v, left, i - 1);
    quick_sort(v, i + 1, right);
}

int main()
{
    vector<int> v = {3, 2, 1, 4, 5, 6, 7, 8, 9, 10};
    quick_sort(v, 0, v.size() - 1);
    for (int i = 0; i < v.size(); i++)
        cout << v[i] << " ";
    cout << endl;
    return 0;
}

// time: O(nlogn)
// space: O(1)
// stable: yes
// in place: yes
// divide and conquer: yes
// average: O(nlogn)
// worst: O(n^2)
// best: O(nlogn)
// online: yes
// offline: yes

/*
    Implement Quick Select to find the kth smallest 
    element in an array.
*/

int quick_select(vector<int> &v, int left, int right, int k)
{
    if (left >= right)
        return v[left];
    int pivot = v[left];
    int i = left, j = right;
    while (i < j)
    {
        while (i < j && v[j] >= pivot)
            j--;
        if (i < j)
            v[i++] = v[j];
        while (i < j && v[i] <= pivot)
            i++;
        if (i < j)
            v[j--] = v[i];
    }
    v[i] = pivot;
    if (i == k)
        return v[i];
    else if (i < k)
        return quick_select(v, i + 1, right, k);
    else
        return quick_select(v, left, i - 1, k);
}