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
  vector<vector<int>> mp(n, vector<int>(m));

  pair<int, int> start_point, end_point;

  for(int i = 0; i < n; i++){
    string s; cin >> s;
    for(int j = 0; j < m; j++){
      mp[i][j] = s[j];
      if(mp[i][j] == 'A') start_point = {i, j};
      if(mp[i][j] == 'B') end_point = {i, j};
    }
  }

  vector<vector<pair<int, int>>> parent(n, vector<pair<int, int>>(m, make_pair(-1, -1)));

  int dx[4] = {1, -1, 0, 0};
  int dy[4] = {0, 0, 1, -1};

  function<bool(pair<int, int>)> valid = [&](pair<int, int> v){
    return v.first >= 0 && v.first < n && v.second >= 0 && v.second < m; 
  };

  function<void(pair<int, int>)> bfs = [&](pair<int, int> start){
    queue<pair<int, int>> q;

    parent[start.F][start.S] = start;
    q.push(start);

    while(!q.empty()){
      pair<int, int> u = q.front();
      q.pop();

      for(int k = 0; k < 4; k++){
        pair<int, int> v = {u.F + dx[k], u.S + dy[k]};
        if(valid(v) && (mp[v.F][v.S] == '.' || mp[v.F][v.S] == 'B') && parent[v.F][v.S] == make_pair(-1, -1)){
          parent[v.first][v.second] = u;
          if(v == end_point) break;
          q.push(v);
        }
      }
    }
  };

  bfs(start_point);

  function<vector<char>(pair<int, int>, pair<int, int>)> make_path = [&](pair<int, int> start, pair<int, int> end){
    vector<char> path;
    while(end != start){
      if(parent[end.F][end.S].F - end.F == 1){
        path.push_back('U');
      }
      else if(parent[end.F][end.S].F - end.F == -1){
        path.push_back('D');
      }
      else if(parent[end.F][end.S].S - end.S == 1){
        path.push_back('L');
      }
      else if(parent[end.F][end.S].S - end.S == -1){
        path.push_back('R');
      }
      else{
        assert(false);
      }
      end = parent[end.F][end.S];
    }
    reverse(path.begin(), path.end());
    return path;
  };

  if(parent[end_point.F][end_point.S] != make_pair(-1, -1)){
    cout << "YES" << endl;
    vector<char> path = make_path(start_point, end_point);

    cout << path.size() << '\n';
    for(char c : path)
      cout << c;
    cout << '\n';
  }
  else{
    cout << "NO" << endl;
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

