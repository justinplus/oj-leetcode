#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

class Solution {
  public:
    vector<int> grayCode(int n) {
      if( n < 0 ) return {};
      if( n == 0 ) return {0};
      if( n == 1 ) return {0, 1};
      
      vector<int> res = grayCode(n-1);
      int size = (int)res.size();
      int inc = pow(2, n - 1);
      for(int i = size - 1; i >= 0; --i)
        res.push_back(inc + res[i]);

      return res;
    }
};

int main() {
  Solution s;
  auto res = s.grayCode(4);
  for(auto n : res) cout<<n<<' ';
  cout<<endl;
  return 0;
}
