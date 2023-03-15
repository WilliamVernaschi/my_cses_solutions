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
  vector<vector<pair<int, int>>> g;
  g.resize(n);
  for(int i = 0; i < m; i++){
    int a, b, w; cin >> a >> b >> w;
    a--, b--;
    g[a].push_back({b, w});
    g[b].push_back({a, w});
  }

  vector<bool> visited(n, false);
  int vc=0;

  function<void(int)> dfs = [&](int v){
    visited[v] = true;
    vc++;
    for(auto [u, _] : g[v]){
      if(!visited[u]) dfs(u);
    }
  };
  dfs(0);

  set<pair<ll, int>> pq;
  for(int i = 1; i < n; i++){
    pq.insert({INFLL, i});
  }
  pq.insert({0, 0});
  vector<ll> key(n, INFLL);

  if(vc != n){
    cout << "IMPOSSIBLE" << '\n';
    return 0;
  }

  ll t = 0;

  while(!pq.empty()){
    int u = pq.begin()->second;
    t += pq.begin()->first;
    pq.erase(pq.begin());

    for(auto [v, w] : g[u]){
      if(pq.find({key[v], v}) == pq.end()) continue;
      if(w < key[v]){
        pq.erase({key[v], v});
        key[v] = w;
        pq.insert({key[v], v});
      }
    }
  }

  cout << t << '\n';




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

