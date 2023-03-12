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

  int cnt[26] = {0};
  string s; cin >> s;
  int n = s.size();

  for(int i = 0; i < n; i++){
    cnt[s[i]-'A']++;
  }

  char ans[n+1];
  ans[n] = '\0';
  


  int l=0, r=n-1, m=0;

  for(int i = 0; i < 26; i++){
    if(cnt[i]%2 && m){
      cout << "NO SOLUTION" << endl;
      return 0;
    }
    else if(cnt[i]%2){
      m = n/2 - cnt[i]/2;
      while(cnt[i]){
        ans[m] = (i+'A');
        m++;
        cnt[i]--;
      }
    }
    else{
      while(cnt[i]){
        ans[l] = ans[r] = i+'A';
        l++;
        r--;
        cnt[i]-=2;
      }
    }
  }

  puts(ans);
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

