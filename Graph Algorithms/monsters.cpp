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

enum Entity{Human, Monster};


int main(){
  FFIO;

  int n, m; cin >> n >> m;
  vector<vector<char>> map(n, vector<char>(m));
  vector<pii> monsters;
  vector<pii> human;
  pii beg;
  for(int i = 0; i < n; i++){
    string s; cin >> s;
    for(int j = 0; j < m; j++){
      map[i][j] = s[j];
      if(map[i][j] == 'M') monsters.PB({i, j});
      else if(map[i][j] == 'A'){
        human.PB({i, j});
        beg = {i, j};
      }
    }
  }

  vector<vector<bool>> visited(n, vector<bool>(m, false));
  vector<vector<pair<int, int>>> parent(n, vector<pair<int, int>>(m, make_pair(-1, -1)));

  vector<vector<int>> human_arrival_time(n, vector<int>(m, INF));
  vector<vector<int>> monster_arrival_time(n, vector<int>(m, INF));

  int dx[4] = {1, -1, 0, 0};
  int dy[4] = {0, 0, 1, -1};

  auto valid = [&](int i, int j){
    return !(i < 0 || j < 0 || i >= n || j >= m);
  };

  auto bfs = [&](vector<pii> start_positions, Entity entity){

    queue<pii> q;
    for(pii v : start_positions){
      if(entity == Human) human_arrival_time[v.F][v.S] = 0;
      else monster_arrival_time[v.F][v.S] = 0;
      visited[v.F][v.S] = true;
      q.push(v);
    }

    while(!q.empty()){

      pii v = q.front();
      q.pop();

      for(int i = 0; i < 4; i++){
        int new_row = v.F + dx[i];
        int new_col = v.S + dy[i];


        if(!valid(new_row, new_col) || map[new_row][new_col] == '#' || visited[new_row][new_col]) continue;
        
        if(entity == Human){
          human_arrival_time[new_row][new_col] = human_arrival_time[v.F][v.S] + 1;
          parent[new_row][new_col] = v;
        }
        else{
          monster_arrival_time[new_row][new_col] = monster_arrival_time[v.F][v.S] + 1;
        }

        visited[new_row][new_col] = true;

        q.push({new_row, new_col});
      }
    }
    for(int i = 0; i < n; i++) fill(visited[i].begin(), visited[i].end(), false);
  };


  bfs(monsters, Monster);
  bfs(human, Human);

  pair<int, int> ans = {-1, -1};

  for(int i = 0; i < n; i++){
    if(human_arrival_time[i][0] < monster_arrival_time[i][0]){
      ans = {i, 0};    
    }
    else if(human_arrival_time[i][m-1] < monster_arrival_time[i][m-1]){
      ans = {i, m-1};    
    }
  }
  for(int i = 0; i < m; i++){
    if(human_arrival_time[0][i] < monster_arrival_time[0][i]){
      ans = {0, i};    

    }
    else if(human_arrival_time[n-1][i] < monster_arrival_time[n-1][i]){
      ans = {n-1, i};    
    }
  }


  auto make_path = [&](pii end_pos, pii start_pos){
    vector<char> path;
    while(end_pos != start_pos){
      if(parent[end_pos.F][end_pos.S].F - end_pos.F == 1){
        path.PB('U');
      }
      else if(parent[end_pos.F][end_pos.S].F - end_pos.F == -1){
        path.PB('D');
      }
      else if(parent[end_pos.F][end_pos.S].S - end_pos.S == -1){
        path.PB('R');
      }
      else if(parent[end_pos.F][end_pos.S].S - end_pos.S == 1){
        path.PB('L');
      }
      end_pos = parent[end_pos.F][end_pos.S];
    }
    reverse(path.begin(), path.end());
    return path;
  };

  if(ans == make_pair(-1, -1)){
    cout << "NO" << '\n';
  }
  else{
    cout << "YES" << '\n';
    vector<char> path = make_path(ans, beg);
    cout << path.size() << '\n';
    for(char c : path) cout << c;
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

