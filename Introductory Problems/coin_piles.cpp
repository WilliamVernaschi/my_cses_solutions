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
#define FFIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);


typedef long long ll;
typedef pair<int, int> pii;
const int INF=1e9+7;
const ll INFLL=1e18+7;


// a = #ones + #twos*2
// b = #ones*2 + #twos
//
// a = x + 2y
// b = y + 2x
//
// a - 2y = x
// b = y + 2*(a - 2y)
//
// b = y + 2a - 4y
// b = 2a - 3y
// b - 2a = - 3y
// 2a - b = 3y
// 
//
int main(){
  FFIO;

  int q; cin >> q;
  while(q--){
    int a, b; cin >> a >> b;
    if(a > b) swap(a, b);
    bool exp = ((a<<1) - b)%3 == 0 && b <= (a<<1);
    if(exp)
      puts("YES");
    else
      puts("NO");
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

