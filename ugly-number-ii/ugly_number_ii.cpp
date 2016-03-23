#include <iostream>
#include <vector>
using namespace std;

class Solution {
  public:
    
    // TODO: improve performance
    int nthUglyNumber(int n) {
      vector<int> res({1});

      int pos[6] = {};
      int val[6] = {};
      int min_v;
      for( int i = 1; i < n; ++i ) {
        min_v = 0;
        for( int  p : {2,3,5} ) {
          val[p] = res[pos[p]] * p;
          if( min_v == 0 || val[p] < min_v )
            min_v = val[p];
        }

        for( int p : {2,3,5} ) 
          if(val[p] == min_v)
            ++pos[p];

        res.push_back(min_v);
      }

      return res.back();
    }
};

int main() {
  Solution s;
  cout<<s.nthUglyNumber(100)<<endl;

  return 0;
}
