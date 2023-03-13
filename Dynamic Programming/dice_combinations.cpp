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


int main(){
  FFIO;

  // dp[n] = dp[n-1] + dp[n-2] + dp[n-3] + dp[n-4] + dp[n-5] + dp[n-6];
  // a state depends only on the 6 previous states, we
  // store these on the array prev.
  
  int n; cin >> n;
  if(n <= 6){
    cout << (1 << (n-1)) << '\n';
    return 0;
  }
  ll prev[7];

  for(int i = 0; i < 6; i++){
    prev[i] = (1 << i);
  }

  for(int i = 7; i <= n; i++){
    prev[6] = 0;
    for(int j = 0; j < 6; j++){
      prev[6] += prev[j];
      prev[6] %= MOD;
    }
    for(int j = 0; j < 6; j++){
      prev[j] = prev[j+1];
    }
  }
  cout << prev[6] << '\n';
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

