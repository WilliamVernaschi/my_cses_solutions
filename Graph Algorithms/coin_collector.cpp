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

int scc_count=0;
int n;
vector<int> visited;
vector<int> scc;
vector<ll> scores;
vector<ll> coins;
vector<vector<int>> g;
vector<vector<int>> gT;

void dfs1_visit(const vector<vector<int>> &G, int v, vector<int> &order){
  visited[v] = true;
  for(int u : G[v]){
    if(!visited[u]){
      dfs1_visit(G, u, order);
    }
  }
  order.push_back(v);
}

vector<int> dfs1(vector<vector<int>> &G){
  fill(visited.begin(), visited.end(), false);
  
  vector<int> order;
  for(int i = 0; i < G.size(); i++){
    if(!visited[i]){
      dfs1_visit(G, i, order);
    }
  }
  reverse(order.begin(), order.end());
  return order;
}

void dfs2_visit(int v){
  visited[v] = true;
  scc[v] = scc_count;
  scores[scc_count] += coins[v];
  for(int u: gT[v]){
    if(!visited[u]){
      dfs2_visit(u); 
    }
  }
}

void dfs2(const vector<int> &order){
  fill(visited.begin(), visited.end(), false);
  
  for(int i : order){
    if(!visited[i]){
      scores.push_back(0);
      dfs2_visit(i);
      scc_count++;
    }
  }
}

void make_scc(){
  vector<int> order = dfs1(g);
  dfs2(order);
}

vector<vector<int>> scc_graph(){
  make_scc();
  vector<vector<int>> Gscc(scc_count);
  vector<bool> forbidden(scc_count, false);
  for(int v = 0; v < n; v++){
    forbidden[scc[v]] = true;
    for(int u : g[v]){
      if(!forbidden[scc[u]]){
        Gscc[scc[v]].push_back(scc[u]);
      }
    }
    for(int u : g[v]){
      forbidden[scc[u]] = false;
    }
    forbidden[scc[v]] = false;
  }

  return Gscc;
}

int main(){
  FFIO;

  int m; cin >> n >> m;

  visited.assign(n, false);
  coins.resize(n);
  scc.resize(n);
  g.resize(n);
  gT.resize(n);

  for(int i = 0; i < n; i++){
    cin >> coins[i];
  }
  for(int i = 0; i < m; i++){
    int a, b; cin >> a >> b;
    a--, b--;
    g[a].push_back(b);
    gT[b].push_back(a);
  }

  vector<vector<int>> Gscc = scc_graph();

  vector<int> top_order = dfs1(Gscc);


  vector<ll> dp(scc_count+1, 0);

  ll ans = 0;
  for(int i = scc_count-1; i >= 0; i--){
    int v = top_order[i];
    dp[v] = scores[v];
    ll best=0;
    for(int u : Gscc[v]){
      best = max(best, dp[u]);
      
    }
    dp[v] += best;
    ans = max(ans, dp[v]);
  }

  cout << ans << '\n';



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

