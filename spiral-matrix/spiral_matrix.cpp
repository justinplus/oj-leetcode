#include <iostream>
#include <vector>
using namespace std;

class Solution {
  public:
    vector<int> spiralOrder(vector<vector<int>>& m) {
      vector<int> ans;
      int t = 0, l = 0, b = m.size()-1;
      int r = b == -1? -1 : m.front().size()-1;
      
      int i;

      while(true) {
        for( i = l; i <= r; i++ ) ans.push_back(m[t][i]);
        if( ++t > b ) break;
        for( i = t; i <= b; i++ ) ans.push_back(m[i][r]);
        if( l > --r ) break;
        for( i = r; i >= l; i-- ) ans.push_back(m[b][i]);
        if( t > --b ) break;
        for( i = b; i >= t; i-- ) ans.push_back(m[i][l]);
        if( ++l > r ) break;
      }
      
      return ans;
    }
};

void inspect(const vector<int>& v) {
  for(auto e : v) cout<<e<<' ';
  cout<<endl;
}

int main() {
  vector<vector<int>> m = { {1,2,3,4}, {5,6,7,8}, {9,10,11,12} };
  Solution s;
  inspect(s.spiralOrder(m));
  return 0;
}
