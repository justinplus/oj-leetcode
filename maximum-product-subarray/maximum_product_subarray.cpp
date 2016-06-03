#include <iostream>
#include <vector>
#include <climits>
#include <cassert>
#include <utility>
#include <algorithm>
using namespace std;

class Solution {
  public:
    int maxProduct(vector<int>& nums) {
      assert( !nums.empty() );

      int res = nums[0];

      vector<pair<int,int>> mul(nums.size());
      if( nums[0] > 0 )
        mul[0].first = nums[0];
      else
        mul[0].second = nums[0];

      for( size_t i = 1; i < nums.size(); ++i ) {
        if( nums[i] > 0 ) {
          mul[i].first = max( mul[i-1].first * nums[i], nums[i] );
          mul[i].second = mul[i-1].second * nums[i];
        } else if( nums[i] < 0 ) {
          mul[i].first = mul[i-1].second * nums[i];
          mul[i].second = min( mul[i-1].first * nums[i], nums[i] );
        }

        res = max( res, mul[i].first );
      }

      return res;
    }

    // O(1) space is just enough
    int maxProduct_O1(vector<int>& nums) {
      assert( !nums.empty() );

      int cur_max = nums[0] > 0 ? nums[0] : 0;
      int cur_min = nums[0] < 0 ? nums[0] : 0;
      int res = nums[0];
      for( size_t i = 1; i < nums.size(); ++i ) {
        if( nums[i] > 0 ) {
          cur_max = max( cur_max * nums[i], nums[i] );
          cur_min = cur_min * nums[i];
        } else if( nums[i] < 0 ) {
          int first = cur_max;
          cur_max = cur_min * nums[i];
          cur_min = min( first * nums[i], nums[i] );
        } else {
          // NOTE
          cur_max = cur_min = 0;
        }

        res = max( res, cur_max );
      }

      return res;

    }
};

void WA1() {
  Solution s;
  vector<int> nums {-2, 0, -1};
  cout<<s.maxProduct_O1(nums)<<endl;
}

void WA2() {
  Solution s;
  vector<int> nums {6,3,-10,0,2};
  cout<<s.maxProduct_O1(nums)<<endl;
}

int main() {
  WA2();
  return 0;
}
