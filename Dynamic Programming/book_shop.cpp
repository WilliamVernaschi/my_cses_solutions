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

// solve(x, i) = max(pages[i]+solve(x-price[i], i+1), solve(x, i+1))
int main(){
  FFIO;

  int n, x; cin >> n >> x;

  int price[n], pages[n];

  for(int i = 0; i < n; i++) cin >> price[i];
  for(int i = 0; i < n; i++) cin >> pages[i];

  vector<vector<int>> dp(2, vector<int>(x+1, 0));


  for(int i = n-1; i >= 0; i--){
    for(int j = 0; j <= x; j++){
      dp[0][j] = dp[1][j];
      if(j-price[i] >= 0){
        dp[0][j] = max(dp[1][j], pages[i] + dp[1][j-price[i]]);
      }
    }
    copy(dp[0].begin(), dp[0].end(), dp[1].begin());
  }

  cout << dp[0][x] << '\n';



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

