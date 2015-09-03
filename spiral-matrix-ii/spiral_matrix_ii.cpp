#include <iostream>
#include <vector>
using namespace std;

class Solution {
  public:
    vector<vector<int>> generateMatrix(int n) {
      vector<vector<int>> m;
      for(int i = 0; i < n; i++) m.push_back( vector<int>(n) ); 

      int t = 0, l = 0, b = m.size()-1;
      int r = b == -1? -1 : m.front().size()-1;
      
      int i, c = 0;

      while(true) {
        for( i = l; i <= r; i++ ) m[t][i] = ++c;
        if( ++t > b ) break;
        for( i = t; i <= b; i++ ) m[i][r] = ++c;
        if( l > --r ) break;
        for( i = r; i >= l; i-- ) m[b][i] = ++c;
        if( t > --b ) break;
        for( i = b; i >= t; i-- ) m[i][l] = ++c;
        if( ++l > r ) break;
      }
      
      return m;
    }
};

void inspect( const vector<vector<int>>& m ) {
  for(auto& v : m) {
    for(auto& e : v) cout<<e<<' ';
    cout<<endl;
  }
}

int main() {
  Solution s;
  inspect(s.generateMatrix(100));
  return 0;
}
