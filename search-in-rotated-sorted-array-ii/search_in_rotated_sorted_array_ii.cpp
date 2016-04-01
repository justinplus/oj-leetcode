#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
  public:
    // by finding the rotation pos
    bool search(vector<int>& nums, int target) {

      int len = nums.size();
      int l = 0, r = len - 1, m;

      // find the index of pivot
      for( ; l < r; ++l)
        if(nums[l] > nums[l+1]) break;

      int offset = l+1;
      cout<<offset<<endl;

      l = 0, r = len -1;
      while( l <= r ) {
        m = (l + r) / 2;
        int trans = ( m + offset ) % len;
        if( target == nums[trans] ) return true;
        else if( target > nums[trans] ) l = m + 1;
        else r = m - 1;
      }
        
      return false;
    }

    // TODO: binary search directly
};

int main() {
  vector<int> nums {2,2,2,2,2,2};
  Solution s;
  cout<<s.search(nums, 2);
  return 0;
}
