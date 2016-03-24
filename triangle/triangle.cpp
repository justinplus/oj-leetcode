#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
      if( triangle.empty() || triangle[0].empty()) return 0;

      vector<int> pre_sum( triangle.size() );
      vector<int> sum( triangle.size() );
      sum[0] = pre_sum[0] = triangle[0][0];

      for(unsigned i = 1; i < sum.size(); ++i ) {
        sum.front() =  pre_sum[0] + triangle[i].front();
        sum[i] = pre_sum[i-1] + triangle[i].back();

        for( unsigned j = 1; j < i ; ++j ) 
          sum[j] = min( pre_sum[j-1], pre_sum[j] ) + triangle[i][j];

        pre_sum = sum;
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
