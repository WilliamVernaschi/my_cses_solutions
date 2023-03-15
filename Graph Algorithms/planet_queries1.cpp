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

const int MAXN=2e5+5;
const int MAXD=30;

int dp[MAXN][MAXD];


int main(){
  FFIO;

  int n, q;
  cin >> n >> q;

  for(int i = 0; i < n; i++){
    cin >> dp[i][0];
    dp[i][0]--;
  }


  for(int i = 1; i < 30; i++){
    for(int j = 0; j < n; j++){
      dp[j][i] = dp[dp[j][i-1]][i-1];
    }
  }

  string ans;
  while(q--){
    int v, k; cin >> v >> k;
    v--;

    int j = 0;

    while(k){
      if(k&1){
        v = dp[v][j];
      }
      k >>= 1;
      j++;
    }

    ans += to_string(v+1);
    ans += '\n';
  }
  cout << ans;
  
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

