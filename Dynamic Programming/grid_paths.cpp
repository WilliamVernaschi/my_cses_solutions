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

const int MOD = 1e9+7;


int main(){
  FFIO;

  int n; cin >> n;
  char map[n][n];
  for(int i = 0; i < n; i++){
    string l; cin >> l;
    for(int j = 0; j < n; j++){
      map[i][j] = l[j];
    }
  }

  int dp[n+1][n+1];

  if(map[n-1][n-1] == '.' && map[0][0] == '.')
    dp[n-1][n-1] = 1;
  else
    dp[n-1][n-1] = 0;
  
  for(int i = n-1; i >= 0; i--){
    for(int j = n-1; j >= 0; j--){
      if(i == n-1 && j == n-1) continue;

      dp[i][j] = 0;
      if(i+1 < n && map[i+1][j] == '.'){
        dp[i][j] += dp[i+1][j];
        dp[i][j] %= MOD;
      }
      if(j+1 < n && map[i][j+1] == '.'){
        dp[i][j] += dp[i][j+1];
        dp[i][j] %= MOD;
      }
    }
  }
  cout << dp[0][0] << '\n';
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

