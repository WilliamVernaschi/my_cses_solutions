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


int main(){
  FFIO;

  int t; cin >> t;
  while(t--){
    ll r, c; cin >> r >> c;
    if(c <= r){
      if(r%2 == 0) cout << r*r - (c-1) << endl;
      else cout << (r-1)*(r-1) + c << endl;
    }
    else{
      if(c%2 == 1) cout << c*c - (r-1) << endl;
      else cout << (c-1)*(c-1) + r << endl;
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

