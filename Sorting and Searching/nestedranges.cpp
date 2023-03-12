#include <bits/stdc++.h>

using namespace std;

#define FFIO ios_base::sync_with_stdio(false);cin.tie(NULL);


typedef pair<int, int> pii;

int main(){
  FFIO;

  int n; cin >> n;
  pii vin[n];

  map<int, int> best2;
  map<int, int> best1;

  for(int i =0 ; i < n ;i++){
    cin >> vin[i].first >> vin[i].second;
    best1[vin[i].second] = max(best1[vin[i].second], vin[i].first);
    best2[vin[i].first] = max(best2[vin[i].first], vin[i].second);
  }

  for(auto it = next(best2.begin()); it != best2.end(); it++){
    best2[it->first] = max(best2[prev(it)->first], it->second);
  }
  for(auto it = next(best1.begin()); it != best1.end(); it++){
    best1[it->first] = max(best1[prev(it)->first], it->second);
  }

  for(pii p : vin){
    int pp = prev(best1.find(p.second))->first;
    if(best1.find(p.second) == best1.begin())
      pp = -1;

    if((best1[pp] >= p.first) || (best1[p.second] > p.first))
      cout << 1 << ' ';
    else
      cout << 0 << ' ';
  }
  cout << '\n';
  for(pii p : vin){

    int pp = prev(best2.find(p.first))->first;
    if(best2.find(p.first) == best2.begin())
      pp = -1;

    if(best2[pp] >= p.second || (best2[p.first] > p.second))
      cout << 1 << ' ';
    else
      cout << 0 << ' ';
  }
  cout << '\n';
}
