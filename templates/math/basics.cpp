#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
#define ull unsigned long long int
#define N (int)1e7
#define MOD 1000000007

// Greatest Common Divisor & Lowest Common Multiple
ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
ll lcm(ll a, ll b) { return a/gcd(a, b)*b; }

// Fast exponentiation
ll power(ll a, ll b, ll m = MOD) {
  ll ans = 1;
  while (b) {
    if (b & 1) 
      ans = (ans * a) % m;
    a = (a * a) % m;
    b >>= 1;
  }
  return ans;
}

// Multiply caring overflow
ll mulmod(ll a, ll b, ll m = MOD) {
  ll r=0;
  for (a %= m; b; b>>=1, a=(a*2)%m) if (b&1) r=(r+a)%m;
  return r;
}

// Another option for mulmod is using long double
ull mulmod(ull a, ull b, ull m = MOD) {
  ull q = (ld) a * (ld) b / (ld) m;
  ull r = a * b - q * m;
  return (r + m) % m;
}

// Matrix exponentiation
vector<vector<ll>> matmul(vector<vector<ll>> a, vector<vector<ll>> b) {
  int n = a.size();
  vector<vector<ll>> ans(n, vector<ll>(n));
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      for (int k = 0; k < n; k++)
        ans[i][j] = (ans[i][j] + a[i][k] * b[k][j]) % MOD;
  return ans;
}

vector<vector<ll>> matpow(vector<vector<ll>> a, ll n) {
  if (n == 0) return vector<vector<ll>>(1, vector<ll>(1, 1));
  if (n == 1) return a;
  vector<vector<ll>> b = matpow(a, n/2);
  b = matmul(b, b);
  if (n % 2) b = matmul(b, a);
  return b;
}

// nCr % p using Fermat's little theorem.
ll f[N];
void factorial(int n) {
  f[0] = 1;
  for (int i = 1; i <= n; i++)
    f[i] = (f[i - 1] * i) % MOD;
}
ll modinv(ll n, int p) {
  return power(n, p - 2, p);
}
ll C(ll n, int r, int p) {
  if (n < r)
    return 0;
  if (r == 0)
    return 1;
  return (f[n] * modinv(f[r], p) % p * modinv(f[n - r], p) % p) % p;
}