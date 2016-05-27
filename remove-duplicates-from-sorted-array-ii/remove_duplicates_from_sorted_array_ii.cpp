#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
  public:
    int removeDuplicates(vector<int>& nums) {
      const size_t dup_c = 2;

      size_t c = 1, i = 0, j = 1;

      for(; j < nums.size(); ++j ) {
        if(nums[i] != nums[j]) {
          nums[++i] = nums[j];
          c = 1;
        }
        else if( c < dup_c ) {
          nums[++i] = nums[j];
          ++c;
        }
      }

      // NOTE: when nums is []
      return min( i+1, nums.size() );
    }
};

int main() {
  vector<int> nums {1,1,1,2,3,3,3,4,5,6,7,7,8,9};
  vector<int> empty {};
  Solution s;

  cout<<s.removeDuplicates(nums);
  return 0;
}
