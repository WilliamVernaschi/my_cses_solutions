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

vector<vector<pair<int, ll>>> g;
vector<ll> dist;
int n;

void dijkstra(int v){

  dist.assign(n, INFLL);
  dist[v] = 0;

  set<pair<ll, int>> q;
  for(int i = 1; i < n; i++){
    q.insert({INFLL, i});
  }
  q.insert({0, 0});

  while(!q.empty()){
    int u = q.begin()->second;
    q.erase(q.begin());

    for(auto [to, w] : g[u]){
      if(dist[u] + w < dist[to]){
        q.erase({dist[to], to});
        dist[to] = dist[u] + w;
        q.insert({dist[to], to});
      }
    }
  }
}

int main(){
  FFIO;

  int m; cin >> n >> m;
  g.resize(n);
  for(int i = 0; i < m; i++){
    int a, b, w; cin >> a >> b >> w;
    a--; b--;
    g[a].push_back({b, w});
  }
  dijkstra(0);
  for(int i = 0; i < n; i++){
    cout << dist[i] << ' ';
  }
  cout << endl;

  

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

