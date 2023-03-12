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

  ll n; cin >> n;
  if((n*(n+1)/2) % 2){
    cout << "NO" << endl;
  }
  else{
    cout << "YES" << endl;
    ll need = n*(n+1)/4;
    vector<int> s1;
    vector<int> s2;
    bool done1st=false;

    ll dont=-1;
    for(ll i = n; i >= 1; i--){
      if(need - i < 0 && !done1st){
        dont = need;
        done1st = true;
        s1.push_back(dont);
        s2.push_back(i);
      }
      else if(need - i >= 0 && !done1st){
        s1.push_back(i);
        need-=i;
        if(need == 0){
          done1st = true;
        }
      }
      else if(done1st && i != dont){
        s2.push_back(i);
      }
    }
    cout << s1.size() << endl;
    for(auto x : s1){
      cout << x << " ";
    }
    cout << endl;
    cout << s2.size() << endl;
    for(auto x : s2){
      cout << x << " ";
    }
    cout << endl;


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

