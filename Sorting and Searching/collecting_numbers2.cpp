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


// 4 2 1 5 3  -> 3 2 5 1 4
int main(){
  FFIO;

  int n, q; cin >> n >> q;
  vector<int> arr(n+1);
  vector<int> pos(n+1);
  for(int i = 0; i < n; i++){
    int x; cin >> x;
    arr[x] = i+1;
    pos[i+1] = x;
  }
  debug(arr);
  debug(pos);
  int ans=1;
  for(int i = 1; i < n; i++){
    if(arr[i+1] < arr[i]) ans++;
  }
  while(q--){
    int a, b; cin >> a >> b;
    int x = pos[a];
    int y = pos[b];
    swap(pos[a], pos[b]);
    if(x > 1){
      ans += (arr[x] < arr[x-1]) - arr[]
    }


    

  }
  cout << ans << endl;
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

