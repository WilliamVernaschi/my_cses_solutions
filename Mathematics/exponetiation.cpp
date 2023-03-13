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

ll fastpow(ll a, ll b){
  if(b == 0) return 1;
  if(b%2 == 1)
    return ((a%MOD)*(fastpow(a, b-1)%MOD))%MOD;
  else
    return ((fastpow(a, b/2)%MOD) * (fastpow(a, b/2)%MOD))%MOD;
  
}


int main(){
  FFIO;

  int n; cin >> n;
  while(n--){
    int a, b; cin >> a >> b;
    cout << fastpow(a, b) << '\n';
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

