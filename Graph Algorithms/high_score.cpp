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

int main(){
  FFIO;

  int n, m; cin >> n >> m;
  vector<vector<pair<int, ll>>> g;
  vector<vector<pair<int, ll>>> gT;
  g.resize(n);
  gT.resize(n);
  for(int i = 0; i < m; i++){
    ll a, b, w; cin >> a >> b >> w;
    a--; b--;
    g[a].PB({b, -w});
    gT[b].PB({a, -w});
  }

  vector<ll> distance(n, INFLL);


  auto dfs = [&](int v, vector<vector<pair<int, ll>>> &G){
    vector<bool> visited(n, false);

    function<void(int)> dfs_visit = [&](int v){
      visited[v] = true;
      for(auto [u, _] : G[v]){
        if(!visited[u]) dfs_visit(u);
      }
    };

    dfs_visit(v);

    return visited;
  };

  auto get_edges_on_path = [&](int from, int to){
    vector<bool> reachable_from = dfs(from, g);
    vector<bool> reachable_to = dfs(to, gT);

    vector<int> path;
    for(int i = 0; i < n; i++){
      if(reachable_from[i] == 1 && reachable_to[i] == 1){
        path.push_back(i);
      }
    }
    return path;
  };

  auto bellman_ford = [&](int v){
    vector<tuple<int, int, ll>> edges;
    for(int i = 0; i < n; i++){
      for(auto [u, w] : g[i]){
        edges.push_back({i, u, w});
      }
    }

    distance[v] = 0;

    for(int i = 0; i < n-1; i++){
      for(auto [u, v, w] : edges){
        distance[v] = min(distance[v], distance[u] + w);
      }
    }

    vector<int> edges_on_path = get_edges_on_path(0, n-1);

    for(int x : edges_on_path){
      //debug(edges_on_path);
      for(auto [u, v, w] : edges){
        if(v != x) continue;
        if(distance[u] + w < distance[v]) return false;
      }
    }
    return true;
  };

  if(!bellman_ford(0)){
    cout << -1 << endl;
  }
  else{
    cout << -distance[n-1] << '\n';
  }

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

