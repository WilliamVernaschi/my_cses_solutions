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

  vector<vector<int>> g(n);

  for(int i = 0; i < m; i++){
    int a, b; cin >> a >> b;
    a--; b--;
    g[a].push_back(b);
    g[b].push_back(a);
  }

  vector<int> distance(n, INF);

  auto bfs = [&](int start){
    queue<int> q;

    distance[start] = 0;
    q.push(start);
    while(!q.empty()){
      int v = q.front();
      q.pop();
      for(int u : g[v]){
        if(distance[u] == INF){
          distance[u] = distance[v] + 1;
          q.push(u);
        }
        else{
          if((distance[u] + distance[v]) % 2 == 0){
            return false;
            break;
          }
        }
      }
    }
    return true;
  };

  for(int i = 0; i < n; i++){
    if(distance[i] == INF){
      bool valid = bfs(i);
      if(!valid){
        cout << "IMPOSSIBLE" << '\n';
        return 0;
      }
    }
  }

  for(int i = 0; i < n; i++){
    if(distance[i] % 2) cout << 1 << ' ';
    else cout << 2 << ' ';
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

