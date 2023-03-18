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

int dp[501][501];
int solve(int a, int b){
  if(dp[a][b] != -1) return dp[a][b];
  if(a == b) return 0;
  dp[a][b] = INF;
  for(int i = 1; i < a; i++){
    dp[a][b] = min(dp[a][b], 1 + solve(i, b) + solve(a-i, b));
  }
  for(int i = 1; i < b; i++){
    dp[a][b] = min(dp[a][b], 1 + solve(a, i) + solve(a, b-i));
  }
  return dp[a][b];
}

int main(){
  FFIO;

  int a, b; cin >> a >> b;
  int dp[501][501];
  for(int i = 0; i < max(a, b); i++) dp[i][i] = 0;

  memset(dp, -1, sizeof(dp));
  cout << solve(a, b) << '\n';


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

