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

  int n, m; cin >> n >> m;

  vector<vector<char>> map(n, vector<char>(m));

  for(int i = 0; i < n; i++){
    string s; cin >> s;
    for(int j = 0; j < m; j++){
      map[i][j] = s[j];
    }
  }
  int cnt=0;

  int dx[4] = {1, -1, 0, 0};
  int dy[4] = {0, 0, 1, -1};

  function<void(int, int)> flood_fill = [&](int i, int j){
    map[i][j] = '#';
    for(int k = 0; k < 4; k++){
      if(i+dx[k] < 0 || j+dy[k] < 0 || i+dx[k] >= n || j+dy[k] >= m) continue;
      if(map[i+dx[k]][j+dy[k]] == '.') 
        flood_fill(i+dx[k], j+dy[k]);
    }
  };

  for(int i = 0;i < n; i++){
    for(int j = 0; j < m; j++){
      if(map[i][j] == '.'){
        cnt++;
        flood_fill(i, j);
      }
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

