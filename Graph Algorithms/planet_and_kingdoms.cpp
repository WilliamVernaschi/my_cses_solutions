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
  vector<vector<int>> gT;
  g.resize(n);
  gT.resize(n);

  for(int i = 0; i < m; i++){
    int a, b; cin >> a >> b;
    a--, b--;
    g[a].PB(b);
    gT[b].PB(a);
  }

  vector<int> scc(n, 0);
  int scc_count=0;

  auto make_scc = [&](){
    vector<int> visit_order;
    vector<bool> visited(n, false);


    function<void(int)> dfs1 = [&](int v){
      visited[v] = true;
      for(int u : g[v]){
        if(!visited[u]) dfs1(u);
      }
      visit_order.push_back(v);
    };

    function<void(int)> dfs2 = [&](int v){
      scc[v] = scc_count;
      visited[v] = true;
      for(int u : gT[v]){
        if(!visited[u]) dfs2(u);
      }
    };

    for(int i = 0; i < n; i++){
      if(!visited[i]) dfs1(i);
    }
    fill(visited.begin(), visited.end(), false);
    reverse(visit_order.begin(), visit_order.end());
    for(int i : visit_order){
      if(!visited[i]){
        dfs2(i);
        scc_count++;
      }
    }
  };

  make_scc();

  cout << scc_count << '\n';
  for(int i = 0; i < n; i++){
    cout << scc[i]+1 << ' ';
  }
  cout << '\n';


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

