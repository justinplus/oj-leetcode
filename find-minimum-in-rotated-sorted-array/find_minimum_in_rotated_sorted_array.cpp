#include <iostream>
#include <vector>
using namespace std;

class Solution {
  public:
    int findMin(vector<int>& nums, int target) {

      int len = nums.size();
      int l = 0, r = len - 1, m;

      // find the index of pivot
      // TODO: review
      while( l < r ) {
        m = (l + r) / 2;
        if(nums[m] > nums[r]) l = m + 1;
        else r = m;
      }

      return nums[l];
    }
};

