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

  // even though this solution has complexity O(nlogn),
  // and the hash map approach has complexity O(n), this
  // is faster, since there is no complex data strucutre
  // being maintaned, and only simple operations are
  // performed.

  int n; cin >> n;
  int nums[n];
  for(int i = 0; i < n; i++){
    cin >> nums[i];
  }
  sort(nums, nums+n);
  int cnt = 1;
  for(int i = 0; i < n-1; i++){
    if(nums[i] != nums[i+1]){
      cnt++;
    }
  }
  cout << cnt << '\n';


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

