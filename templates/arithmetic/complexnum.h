#include <bits/stdc++.h>
using namespace std;
#define int long long

// for (a+i*b)^n
// Real component = (a^2+b^2)^(n/2)*cos(n*arctan(b/a))
// Imaginary component =(a^2+b^2)^(n/2)*sin(n*arctan(b/a))

long double* cmul(long double* sq1, long double* sq2)
{
    long double* ans = new long double[2];
 
    // For real part
    ans[0] = (sq1[0] * sq2[0]) - (sq1[1] * sq2[1]);
 
    // For imaginary part
    ans[1] = (sq1[1] * sq2[0]) + sq1[0] * sq2[1];
 
    return ans;
}
 

long double* power(long double* x, int n)
{
    long double* ans = new long double[2];
    if (n == 0) {
        ans[0] = 0;
        ans[1] = 0;
        return ans;
    }
    if (n == 1)
        return x;
 
    long double* sq = power(x, n / 2);
    if (n % 2 == 0)
        return cmul(sq, sq);
    return cmul(x, cmul(sq, sq));
}
 
// Driver code
// signed main()
// {
//     int n = 8;
//     long double* x = new long double[2];
//     x[0] = 18, x[1] = -13;
 
//     long double* a = power(x, n);
//     cout << a[0] << " + i ( " << a[1] << " )" << endl;
 
//     return 0;
// }