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
const ll INFLL=1e17+7;

typedef array<ll, 502> line;
typedef array<line, 500> matrix;

void init_matrix(matrix &A, ll init_val = 0){
  for(line &a : A){
    a.fill(init_val);
  }
}

matrix matrix_mult(const matrix &A, const matrix &W){
  matrix l;
  init_matrix(l);

  int n = W.size();

  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++){
      l[i][j] = A[i][j];
      for(int k = 0; k < n; k++){
        l[i][j] = min(l[i][j], A[i][k] + W[k][j]);
      }
    }
  }

  return l;
}

matrix extend_paths(int n, matrix &W){
  matrix A;
  init_matrix(A, INFLL);
  for(int i = 0; i < n; i++) A[i][i] = 0;

  while(n){
    if(n&1)
      A = matrix_mult(A, W);
    
    n >>= 1;
    W = matrix_mult(W, W);
  }

  return A;
}

int main(){
  FFIO;

  int n, m, q; cin >> n >> m >> q;

  matrix W;
  init_matrix(W, INFLL);

  for(int i = 0; i < m; i++){
    int a, b;
    ll w;
    cin >> a >> b >> w;
    a--; b--;
    W[a][b] = W[b][a] = w;
  }


  matrix A;
  init_matrix(A, INFLL);
  for(int i = 0; i < n; i++) A[i][i] = 0;


  matrix ans = extend_paths(n-1, W);

  while(q--){
    int a, b; cin >> a >> b;
    a--, b--;
    cout << (ans[a][b] != INFLL ? ans[a][b] : -1) << '\n';
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

