#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
      if( triangle.empty() || triangle[0].empty()) return 0;

      vector<int> sum( triangle.size() );
      sum[0] = triangle[0][0];

      for(unsigned i = 1; i < sum.size(); ++i ) {
        sum[i] = sum[i-1] + triangle[i].back();

        // NOTE: iterate in reverse order
        for( unsigned j = i - 1; j >= 1 ; --j ) 
          sum[j] = min( sum[j-1], sum[j] ) + triangle[i][j];

        sum[0] = sum[0] + triangle[i].front();
      }

      return *min_element(sum.begin(), sum.end());
    }
};

int main() {
  vector<vector<int>> triangle {{2},{3,4},{6,5,7},{4,1,8,3}};
  Solution s;
  cout<<s.minimumTotal(triangle);
  return 0;
}
