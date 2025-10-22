#include <bits/stdc++.h>
using namespace std;

int main()
{
    int a[] = {4, 2, 3, 1, 5, 6};
    int b[] = {3, 1, 4, 6, 5, 2};

    int n = sizeof(a) / sizeof(a[0]);
    
    vector<vector<int>> f(n + 1, vector<int> (n + 1, 1));
    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j < n; j++)
        {
            if (a[i] == b[j])
                f[i][j] = f[i - 1][j - 1] + 1;
            else
                f[i][j] = max(f[i - 1][j], f[i][j - 1]);
        }
    }

    cout << f[n - 1][n - 1] << endl;
    return 0;
}