#include <bits/stdc++.h>
using namespace std;

#define int long long;
#define MAX (int)(1e6+5);
#define INF (int)(1e18);

typedef vector<int> vi;
typedef pair<int, pair<int, int>> ii;

vector<bool> primes(MAX, true);
vi smol(MAX);
vi wow(MAX);
vi flr(MAX);

void precompute() {
  for (int i = 0; i < MAX; i++) {
    smol[i] = i;
  }

  primes[0] = false;
  primes[1] = false;
  for (int i = 2; i < MAX; i++) {
    if (!primes[i]) {
      continue;
    }

    for (int j = i * i; j < MAX; j += i) {
      primes[j] = false;
      smol[j] = min(smol[j], (ll)i);
    }
  }

  wow[0] = 0;
  wow[1] = 0;
  for (int i = 2; i < MAX; i++) {
    set<ll> s;

    ll x = i;
    while(smol[x] != 1) {
      s.insert(smol[x]);
      x /= smol[x];
    }

    wow[i] = s.size();
  }

  flr[0] = 0;
  flr[1] = 0;
  for (int i = 2; i < MAX; i++) {
    flr[i] = (ll)sqrt((double)i);
  }
}

int dk(ll N, vector<vector<ll>> G) 
{
  priority_queue<ii, vector<ii>, greater<ii>> q;

  q.push({0, {0, 0}});

  vector<vector<ll>> dist(N, vector<ll>(N, INF));
  dist[0][0] = 0;

  while(!q.empty()) {
    auto p = q.top();
    q.pop();

    ll curr = p.first, x = p.second.first, y = p.second.second;

    if (curr != dist[x][y])
      continue;

    if (x == N - 1 and y == N - 1)
      break;

    ll cost = flr[G[x][y]];
    ll md = wow[G[x][y]];

    for (int i = -md; i <= md; i++) {
      int j = md - abs(i);
      ll newx, newy;

      // positive j
      newx = x + i, newy = y + j;

      if (newx >= 0 and newx < N and newy >= 0 and newx < N) {
        if (dist[newx][newy] > cost + dist[x][y]) {
          dist[newx][newy] = cost + dist[x][y];
          q.push({dist[newx][newy], {newx, newy}});
        }
      }
      
      // negative j
      newx = x + i, newy = y - j;
      if (newx >= 0 and newx < N and newy >= 0 and newx < N) {
        if (dist[newx][newy] > cost + dist[x][y]) {
          dist[newx][newy] = cost + dist[x][y];
          q.push({dist[newx][newy], {newx, newy}});
        }
      }

    }
  }

  return dist[N - 1][N - 1];
}