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

  int n, m, k; cin >> n >> m >> k;
  int people[n];
  int apartments[m];
  for(int i = 0; i < n; i++) cin >> people[i];
  for(int i = 0; i < m; i++) cin >> apartments[i];
  sort(people, people+n);
  sort(apartments, apartments+m);
  int ap=0, pp=0;
  int cnt=0;

  // sort the arrays
  // try to give the smallest apartment to the first person
  // if we can't, it's because:
  //
  // 1. the apartment is too small, in that case, it doesnt make sense to 
  // allocate this apartment to the next person, since they are ordered
  // and the next person will certanly not fit in this apartment,
  // so check the next apartment.
  //
  // 2. the apartment is too big, similarly, we wont try to increase
  // the apartment size, the only option that makes sense is to check if 
  // the next person can have this apartment.
  //
  // if we can, we have three options:
  // 1. skip this person and dont give it the apartment.
  // 2. skip the apartment.
  // 3. give the apartment to the person.
  // 
  // 3 is the best option, one can show that options one and two will
  // yield worse or just as good solutions as the third, but never better.
  //
  while(pp < n && ap < m){
    if(abs(apartments[ap]-people[pp]) <= k){
      ap++;
      pp++;
      cnt++;
    }
    else if(apartments[ap] > people[pp]){
      pp++;
    }
    else{
      ap++;
    }
  }
  cout << cnt << endl;

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

