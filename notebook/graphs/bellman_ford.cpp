/**********************************************************************************
* BELLMAN-FORD ALGORITHM (SHORTEST PATH TO A VERTEX - WITH NEGATIVE COST)         *
* Time complexity: O(VE)                                                          *
* Usage: dist[node]                                                               *
* Notation: m:           number of edges                                          *
*           n:           number of vertices                                       *
*           (a, b, w):   edge between a and b with weight w                       *
*           s:           starting node                                            *
**********************************************************************************/
void solve()
{
  vector<int> d (n, INF);
  d[v] = 0;
  while (true)
  {
    bool any = false;
    for (int j=0; j<m; j++) // operate over all the edges 
      if ((d[e[j].a] < INF) and (d[e[j].b] > d[e[j].a] + e[j].cost))
        d[e[j].b] = d[e[j].a] + e[j].cost,
        any = true;
    
    if (!any) 
      break;
  }
}

// Negative cycles exist if distance gets lower with iterations > n - 1.