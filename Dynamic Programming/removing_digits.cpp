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


int main(){
  FFIO;

  int distance[(int)1e6+5];

  int nn; cin >> nn;

  fill(distance, distance+nn, 0);

  auto bfs = [&](int n){
    distance[n] = 1;
    queue<int> q;
    q.push(n);
    while(!q.empty()){
      
      int nc1 = q.front();
      int nc2 = nc1;

      q.pop();
      while(nc2){
        if(!distance[nc1 - nc2%10]){
          distance[nc1 - nc2%10] = distance[nc1] + 1;
          if(nc1 - nc2%10 == 0){
            return distance[nc1 - nc2%10]-1;
          }
          q.push(nc1 - nc2%10);
        }
        nc2 /= 10;
      }
    }
    return -1;
  };

  cout << bfs(nn) << '\n';


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

