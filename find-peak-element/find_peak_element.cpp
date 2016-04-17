#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

// NOTE: make full use of conditions
// nums[i] != nums[i+1]
// The array may contain multiple peaks, in that case return the index to any one of the peaks is fine.
// You may imagine that num[-1] = num[n] = -∞.

class Solution {
  public:
    // 8ms
    int findPeakElement_8ms(vector<int>& nums) {
      if( nums.size() <= 1 || nums[0] > nums[1]) return 0;
      int m = nums.size();
      if( nums[m-1] > nums[m-2] ) return m-1;

      for( int i = 1; i < m - 1; ++i )
        if( nums[i] > nums[i-1] && nums[i] > nums[i+1] ) return i;

      // should never arrive here
      assert(false);
      return -1;
    }

    int findPeakElement(vector<int>& nums) {
      if( nums.size() <= 1 ) return 0;

      size_t i = 1;
      for( ; i < nums.size(); ++i )
        if( nums[i] < nums[i-1] ) break;

      return i - 1;
    }

    // TODO: review
    int findPeakElement_binSearch(vector<int> &nums) {
      int bg = 0, end = nums.size() - 1, mid;
      while( bg < end ) {
        mid = (bg+end) / 2;
        if( nums[mid] > nums[mid+1] )
          end = mid;
        else
          bg = mid + 1;
      }
      return bg;
    }

};

int main() {
  Solution s;
  vector<int> nums {1,1,2};
  cout<<s.findPeakElement(nums);
  return 0;
}
