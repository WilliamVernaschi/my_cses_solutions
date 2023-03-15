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
const int NIL = -1;


int main(){
  FFIO;

  int n, m; cin >> n >> m;
  vector<vector<pair<int, ll>>> g;
  vector<vector<pair<int, ll>>> gT;
  g.resize(n);
  gT.resize(n);
  for(int i = 0; i < m; i++){
    int a, b; cin >> a >> b;
    ll w; cin >> w;
    a--; b--;
    g[a].push_back({b, w});
    gT[b].push_back({a, w});
  }

  vector<vector<tuple<int, int, ll>>> scc_edges(n);
  vector<vector<int>> scc_vertices(n);
  vector<bool> visited(n, false);
  vector<int> otp;
  int scc_id=0;

  function<void(int)> dfs2 = [&](int v){
    scc_vertices[scc_id].push_back(v);
    visited[v] = true;
    for(auto [u, w] : gT[v]){
      scc_edges[scc_id].push_back({v, u, w});
      if(!visited[u]) dfs2(u);
    }
  };


  function<void()> dfs1 = [&](){
    function<void(int)> dfs1_visit = [&](int v){
      visited[v] = true;
      for(auto [u, _] : g[v]){
        if(!visited[u]) dfs1_visit((int)u);
      }
      otp.push_back(v);
    };

    for(int i = 0; i < n; i++){
      if(!visited[i]){
        dfs1_visit(i);
      }
    }
  };

  auto scc = [&](){
    dfs1();
    fill(visited.begin(), visited.end(), false);
    scc_id = 0;
    for(int v : otp){
      if(!visited[v]){
        dfs2(v);
        scc_id++;
      }
    }
  };


  vector<ll> distance(n, INFLL);
  vector<int> parent(n, NIL);
  vector<int> neg_cycle;

  scc();

  auto bellman_ford = [&](vector<int> &scc_vertices, vector<tuple<int, int, ll>> &scc_edges){
    if(scc_vertices.size() == 1) return false;

    vector<tuple<int, int, ll>> edges;

    for(int x : scc_vertices){
      for(auto [u, w] : g[x]){
        edges.push_back({x, u, w});
      }
    }

    distance[scc_vertices[0]] = 0;

    for(int i = 0; i < scc_vertices.size()-1; i++){
      for(auto [u, v, w] : scc_edges){
        if(distance[u] + w < distance[v]){
          distance[v] = distance[u] + w;
          parent[v] = u;
        }
      }
    }
    bool ok = false;
    int end_vertex;
    for(auto [u, v, w] : scc_edges){
      if(distance[u] + w < distance[v]){
        parent[v] = u;
        ok = true;
        end_vertex = u;
        break;
      }
    }
    if(!ok) return false;

    vector<int> visited(n, false);

    while(!visited[end_vertex]){
      visited[end_vertex] = true;
      neg_cycle.push_back(end_vertex+1);
      end_vertex = parent[end_vertex];
    }
    neg_cycle.push_back(end_vertex+1);

    fill(visited.begin(), visited.end(), false);
    int s = (find(neg_cycle.begin(), neg_cycle.end(), neg_cycle[neg_cycle.size()-1]) - neg_cycle.begin());
    vector<int> ans;
    for(int i = s; i < neg_cycle.size(); i++){
      ans.push_back(neg_cycle[i]);
    }
    neg_cycle = ans;
    //reverse(neg_cycle.begin(), neg_cycle.end());

    return true;
  };

  for(int i = 0; i < scc_id; i++){
    if(bellman_ford(scc_vertices[i], scc_edges[i])){
      cout << "YES" << '\n';
      for(int u : neg_cycle){
        cout << u << ' ';
      }
      cout << '\n';
      return 0;
    }
  }

  cout << "NO" << '\n';


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

