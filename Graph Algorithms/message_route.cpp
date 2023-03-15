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


int main(){
  FFIO;

  int n, m; cin >> n >> m;

  vector<vector<int>> g(n);

  for(int i = 0; i < m; i++){
    int a, b; cin >> a >> b;
    a--; b--;
    g[a].push_back(b);
    g[b].push_back(a);
  }

  vector<int> parent(n, NIL);

  auto bfs = [&](int start){
    queue<int> q;
    q.push(start);
    while(!q.empty()){
      int v = q.front();
      q.pop();
      for(int u : g[v]){
        if(parent[u] == NIL && u != start){
          parent[u] = v;
          q.push(u);
        }
      }
    }
  };

  bfs(0);

  auto build_path = [&](int start, int end){
    vector<int> path;
    path.push_back(end);
    while(end != start){
      end = parent[end];
      path.push_back(end);
    }
    reverse(path.begin(), path.end());
    return path;
  };


  if(parent[n-1] != NIL){
    vector<int> path = build_path(0, n-1);
    cout << path.size() << '\n';
    for(int v : path){
      cout << v+1 << ' ';
    }
    cout << '\n';
  }
  else{
    cout << "IMPOSSIBLE" << '\n';
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

