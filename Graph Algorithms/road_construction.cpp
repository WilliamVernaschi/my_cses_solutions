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

struct DSU{
  vector<int> link;
  vector<int> size;
  int largest_component=0;

  void make_set(int n){
    link.resize(n);

    for(int i = 0; i < n; i++){
      link[i] = i;
    }
    size.assign(n, 1);
  }

  int find(int x){
    while(x != link[x]) x = link[x];
    return x;
  }

  bool same(int a, int b){
    return find(a) == find(b);
  }

  void unite(int a, int b){
    a = find(a);
    b = find(b);
    if(size[a] < size[b]) swap(a, b);
    size[a] += size[b];
    link[b] = a;

    largest_component = max(largest_component, size[a]);
  }

};

int main(){
  FFIO;

  int n, m; cin >> n >> m;

  DSU dsu;

  dsu.make_set(n);

  for(int i = 0; i < m; i++){
    int a, b; cin >> a >> b;
    a--; b--;
    if(!dsu.same(a, b)){
      n--;
      dsu.unite(a, b);
    }
    cout << n << ' ' << dsu.largest_component << '\n';
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

