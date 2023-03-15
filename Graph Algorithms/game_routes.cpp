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
const int MOD = 1e9+7;


int main(){
  FFIO;

  int n, m; cin >> n >> m;
  vector<vector<int>> g;
  g.resize(n);
  for(int i = 0; i < m; i++){
    int a, b; cin >> a >> b;
    a--, b--;
    g[a].PB(b);
  }


  auto top_sort = [&](){
    vector<int> top;
    vector<bool> visited(n, false);

    function<void(int)> dfs = [&](int v){
      visited[v] = true;
      for(auto u : g[v]){
        if(!visited[u]) dfs(u);
      }
      if(v != n-1)
        top.PB(v);
    };

    for(int i = 0; i < n; i++){
      if(!visited[i]){
        dfs(i);
      }
    }

    reverse(top.begin(), top.end());
    return top;
  };

  vector<int> top = top_sort();
  top.push_back(n-1);

  vector<ll> dp(n, 0);
  vector<bool> mark(n, false);

  dp[n-1] = 1;
  mark[n-1] = true;

  for(int i = top.size()-2; i >= 0; i--){
    int v = top[i];
    dp[v] = 0;
    for(int u : g[v]){
      if(mark[u]){
        dp[v] += dp[u];
        dp[v] %= MOD;
        mark[v] = true;
      }
    }
  }



  cout << dp[0] << '\n';


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

