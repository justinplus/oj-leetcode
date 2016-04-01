#include <iostream>
#include <vector>
using namespace std;

class Solution {
  public:
    int search(vector<int>& nums, int target) {

      int len = nums.size();
      int l = 0, r = len - 1, m;

      // find the index of pivot
      // TODO: review
      while( l < r ) {
        m = (l + r) / 2;
        if(nums[m] > nums[r]) l = m + 1;
        else r = m;
      }

      int offset = l;

      l = 0, r = len -1;
      while( l <= r ) {
        m = (l + r) / 2;
        int trans = ( m + offset ) % len;
        if( target == nums[trans] ) return trans;
        else if( target > nums[trans] ) l = m + 1;
        else r = m - 1;
      }
        
      return -1;
    }
};

int main() {
  vector<int> nums {1,3};
  Solution s;
  cout<<s.search(nums, 3);

  return 0;
}
