#include <bits/stdc++.h>
using namespace std;
int main()
{
    static const int n = 3;

    // Enter some number greater than 10 please
    scanf("%d", ((int*) &n));
    std::array<int, n> a;

    int count = 0;
    for (int i = 0; i < 10; i++)
        a[i] = ++count;

    for (int i = 0; i < 10; i++)
        cout << a[i] << endl;

    return 0;
}
