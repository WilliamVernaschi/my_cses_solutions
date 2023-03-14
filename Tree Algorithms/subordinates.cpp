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

int values[(int)2e5+5];

int solve(int emp){
  int ans=0;
  for(int u : g[emp]){
    ans += 1 + solve(u);
  }
  values[emp] = ans;
  return ans;
}


int main(){
  FFIO;

  int n; cin >> n;
  g.resize(n);
  for(int i = 1; i < n; i++){
    int x; cin >> x;
    x--;
    g[x].push_back(i);
  }
  solve(0);

  for(int i = 0; i < n; i++){
    cout << values[i] << ' ';
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

