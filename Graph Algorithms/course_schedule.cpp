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

vector<vector<int>> g;
int n;

bool has_cycle(int v, vector<int> &color){
  color[v] = 1;
  bool ok = false;
  for(auto u : g[v]){
    if(color[u] == 1) return true;
    else if(color[u] == 0){
      ok |= has_cycle(u, color);
    }
  }
  color[v] = 2;
  return ok;
}

bool has_cycle(){
  vector<int> color(n, 0);
  for(int i = 0; i < n; i++){
    if(color[i] == 0){
      if(has_cycle(i, color)){
        return true;
      }
    }
  }
  return false;
}

vector<int> tp;
vector<bool> visited;

void top_sort(int v){
  visited[v] = true;
  for(auto u : g[v]){
    if(!visited[u])
      top_sort(u);
  }
  tp.push_back(v);
}

int main(){
  FFIO;

  int m; cin >> n >> m;
  g.resize(n);
  visited.assign(n, false);
  for(int i = 0; i < m; i++){
    int a, b; cin >> a >> b;
    a--; b--;
    g[a].push_back(b);
  }
  
  if(has_cycle()){
    cout << "IMPOSSIBLE" << '\n';
  }
  else{
    for(int i = 0; i < n; i++){
      if(!visited[i]){
        top_sort(i);
      }
    }
    reverse(tp.begin(), tp.end());
    for(int p : tp){
      cout << p+1 << ' ';
    }
    cout << '\n';
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

