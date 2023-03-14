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
  vector<vector<int>> g;
  g.resize(n);
  for(int i = 0; i < m; i++){
    int a, b; cin >> a >> b;
    a--; b--;
    g[a].push_back(b);
    g[b].push_back(a);
  }

  // a component leader is simply a vertex
  // that is a part of a connected component,
  // each component has only one arbitraraly chosen leader.
  vector<int> components_leaders;

  vector<bool> visited(n, false);

  function<void(int)> dfs_visit = [&](int v){
    visited[v] = true;
    for(int u : g[v]){
      if(!visited[u]) dfs_visit(u);
    }
  };

  function<void()> dfs = [&](){
    for(int i = 0; i < n; i++){
      if(!visited[i]){
        dfs_visit(i);
        components_leaders.push_back(i+1); // make 1-indexed.
      }
    }
  };

  dfs();

  // making a tree out of the component leaders.
  cout << components_leaders.size() - 1 << '\n';
  for(int i = 0; i < components_leaders.size()-1; i++){
    cout << components_leaders[i] << ' ' << components_leaders[i+1] << '\n';
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

