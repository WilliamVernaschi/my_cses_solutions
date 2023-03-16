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

int smallest_div[(int)1e6+5];

void sieve(){

  for(int i = 2; i <= 1e6; i++){
    if(smallest_div[i] == 0){
      for(int j = i; j <= 1e6; j+=i){
        smallest_div[j] = i;
      }
    }
  }

}


int main(){
  FFIO;

  sieve();
  int n; cin >> n;
  while(n--){
    int x; cin >> x;
    ll ans=1;

    while(x != 1){
      int curr_prime = smallest_div[x];
      int cnt=0;
      while(curr_prime == smallest_div[x]){
        cnt++;
        x /= smallest_div[x];
      }
      ans *= (cnt+1);
    }
    cout << ans << '\n';
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

