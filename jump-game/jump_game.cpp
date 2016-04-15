#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
  public:
    bool canJump(vector<int>& nums) {
      int  pre = -1;
      for( int i = 0; i < (int) nums.size(); ++i ) {
        if( nums[i] == 0 ) {
          int j = (int) i - 1;
          for( ; j > pre; --j ) if( nums[j] > i - j ) break;
          if( j == pre && i != int(nums.size() - 1) )
            return false;
        }
      }

      return true;
    }

    // greedy: jump as far as you can
    bool canJump_greedy(vector<int>& nums) {
      int max_jump = nums[0];
      int len = nums.size();

      for( int i = 1; i < len; ++i) {
        if(i > max_jump) return false;
        max_jump = max( max_jump, i + nums[i]);
        if(max_jump >= len-1) return true;
      }
    }
};

int main() {
  vector<int> nums = {3,2,1,0,4};
  vector<int> nums1 = {1,0,1};
  vector<int> nums_wrong = {3,0,0,0};
  Solution s;
  cout<<s.canJump(nums_wrong);
  return 0;
}
