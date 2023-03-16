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

const int MAXX=1e6+1;
int smallest_div[MAXX+1];

void sieve(){
  for(int i = 2; i < MAXX; i++){
    if(smallest_div[i] == 0){
      for(int j = i; j < MAXX; j+= i){
        smallest_div[j] = i;
      }
    }
  }
}

int main(){
  FFIO;

  sieve();

  int n; cin >> n;

  // cnt[i] = j means there are j numbers that have i as a divisor.
  int cnt[MAXX];
  memset(cnt, 0, sizeof(cnt));

  // build cnt
  for(int i = 0; i < n; i++){

    int x; cin >> x;

    while(x != 1){
      debug(x);
      cnt[x]++;
      if(x != smallest_div[x])
        cnt[smallest_div[x]]++;
      x /= smallest_div[x];
    }
  }

  int ans=1;


  // if cnt[i] = j >= 2 for some i, we can choose two of these j numbers and their gcd is at least i.
  for(int i = 2; i < MAXX; i++){
    if(cnt[i] >= 2) ans = i;
  }

  cout << ans << '\n';


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

