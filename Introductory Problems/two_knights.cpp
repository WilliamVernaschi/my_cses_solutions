#ifdef ONLINE_JUDGE
  #define debug(x...)
#else
  #include "/mnt/d/dev/cp/debug.h"
#endif

#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second
#define PB push_back
#define FFIO ios_base::sync_with_stdio(false);cin.tie(NULL);


typedef long long ll;
typedef pair<int, int> pii;
const int INF=1e9+7;
const ll INFLL=1e18+7;

/*
 *    # @ - - - - - - @ #
 *    @ + * * * * * * + @
 *    - * . . . . . . * -
 *    - * . . . . . . * -
 *    - * . . . . . . * -
 *    - * . . . . . . * -
 *    - * . . . . . . * -
 *    - * . . . . . . * -
 *    @ + * * * * * * + @
 *    # @ - - - - - - @ #
*/

ll calc(ll n){
  // in each line, we count the number of 
  // ways two knights could be placed so that
  // they attack each other
  
  ll ans=(((n-4)*(n-4))*8);  // counting '.'
  // any knight in the '.' positions could be placed
  // so that it attacks 8 other knights.
  
  ans += (n-4)*4*4;          // counting '-'
  ans += (n-4)*4*6;          // counting '*'
  ans += 2*4;                // counting '#'
  ans += 8*3;                // counting '@'
  ans += 4*4;                // counting '+'

  // n^2 choose two - ans
  return ((n-1)*n*n*(n+1) - ans)/2;
}

int main(){
  FFIO;

  
  int n; cin >> n;
  for(int i = 1; i <= n; i++){
    cout << calc(i) << '\n';
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

