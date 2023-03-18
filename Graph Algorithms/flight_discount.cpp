#ifdef ONLINE_JUDGE
  #define debug(x...)
#else
  #include "/home/william/cp/debug.h"
#endif

#include <bits/stdc++.h>

using namespace std;

#define PMOD(n,m) ((((n) % (m)) + m) % m)
#define F first
#define S second
#define PB push_back
#define FFIO ios_base::sync_with_stdio(false);cin.tie(NULL);


typedef long long ll;
typedef pair<int, int> pii;
const int INF=1e9+7;
const ll INFLL=1e18+7;
const int NIL=-1;

typedef vector<vector<pair<int, int>>> adj;

vector<int> dijkstra(int v, adj &G){
  int n = G.size();

  vector<ll> dist(n, INFLL);
  vector<int> parent(n, NIL);

  dist[v] = 0;
  set<pair<ll, int>> pq;
  map<pair<int, int>> edg;

  for(int i = 0; i < n; i++){
    for(auto [j, w] : G[i]){
      edg[make_pair(i, j)] = w;
    }
  }

  for(int i = 0; i < n; i++){
    if(i == v)
      pq.insert({0, v});
    else
      pq.insert({INFLL, i});
  }

  while(!q.empty()){
    int u = q.begin()->second;
    q.erase(q.begin());

    for(auto [x, w] : G[u]){

      // x not in priority queue
      if(pq.find({dist[x], x}) == pq.end()) continue;

      if(dist[x] < dist[u] + w || (parent[u] != NIL && dist[x] == dist[u] + w && w > edg[make_pair(u, parent[u])])){
        parent[x] = u;
        pq.erase({dist[x], x});
        dist[x] = dist[u] + w;
        pq.insert({dist[x], x});
      }
    }
  }
  for(int i = 0; i < n; i++){
  }

}

int main(){
  FFIO;


}



// Stuck? Answer these:
//
// Did I understand the problem correctly?
// Did I read the restrictions carefully? i.e: there is something like n*m < 2e5, when n <= 2e5 and m <= 2e5
// Should I be using long long instead of int somewhere?
// Should I be using double instead of int somewhere?
// Do in need to reset any values after a procedure?
// Is there a tricky pattern to be found? Try bruteforcing a solution to find it.
// No good ideas after around 2h? Try another problem / look up the solution

