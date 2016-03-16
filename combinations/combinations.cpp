#include<iostream>
#include<vector>
using namespace std;

class Solution {
  public:
    vector<vector<int>> combine(int n, int k) {
      vector<int> flag(n, -1);
      vector<vector<int>> res;

      _combine( res, flag, k, 0, 0);

      return res;
    }

    void _combine(vector<vector<int>>& res, vector<int>& flag, int k, int offset, int curr) {
      if( curr == k ) {
        res.push_back( vector<int>(k, 0) );
        for(unsigned i = 0; i < flag.size(); ++i )
          if(flag[i] != -1) res.back()[flag[i]] = i+1; 

      } else {

        for(unsigned i = offset; i < flag.size(); ++i) {
          if(flag[i] == -1){
            flag[i] = curr;
            _combine(res, flag, k, i, curr+1);
            flag[i] = -1;
          }
        }

      }
    }
};

int main() {
  Solution s;

  for( auto &vec : s.combine(7,3) ) {
    for( auto n : vec )
      cout<<n<<' ';
    cout<<endl;
  }
  return 0;
}
