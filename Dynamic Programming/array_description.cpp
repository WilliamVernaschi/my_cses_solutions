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
const int MOD=1e9+7;

ll dp[(int)1e5+5][100+5];
int arr[(int)1e5+5];
int n, m;

ll solve(int idx, int c){
  if(dp[idx][c] != -1) return dp[idx][c];
  if(idx == n){
    dp[idx][c] = 1;
  }
  else if(arr[idx] == 0 && idx == 0){
    ll ans=0;
    for(int i = 1; i <= m; i++){
      ans += solve(idx+1, i);
      ans %= MOD;
    }
    dp[idx][c] = ans;
  }
  else if(arr[idx] == 0){
    dp[idx][c] = 0;

    if(c-1 >= 1) dp[idx][c] += solve(idx+1, c-1)%MOD;
    dp[idx][c] += solve(idx+1, c)%MOD;
    if(c+1 <= m) dp[idx][c] += solve(idx+1, c+1)%MOD;

    dp[idx][c] %= MOD;

  }
  else{
    if((abs(c - arr[idx]) > 1) && c != 101){
      dp[idx][c] = 0;
    }
    else{
      dp[idx][c] = solve(idx+1, arr[idx]);
      dp[idx][c] %= MOD;
    }
  }
  return dp[idx][c];
}

int main(){
  FFIO;
  cin >> n >> m;
  for(int i = 0; i < n; i++){
    cin >> arr[i];
  }

  memset(dp, -1, sizeof(dp));
  cout << solve(0, 101) << '\n';

  //dp[0][101] = dp[1][1] + dp[1][2] + dp[1][3] + ... + dp[1][m]
  //arr[5] == 0, dp[5][4] = dp[6][3] + dp[6][4] + dp[6][5]
  //arr[6] != 0, dp[6][3] = dp[7][arr[6]]

  if(arr[n-1] == 0){
    for(int i = 1; i <= m; i++){
      dp[n-1][i] = m;
    }
  }
  for(int i = n-1; i >= 0; i--){
    for(int j = 1; j <= m; j++){
      
    }
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

