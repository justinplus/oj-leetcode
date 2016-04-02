#include <iostream>
#include <vector>
using namespace std;

class Solution {
  public:
    int findMin(vector<int>& nums) {
      int l = 0, r = nums.size() - 1, m;
      while( l < r) {
        if( nums[l] == nums[r] ) --r;
        else {
          m = (l+r)/2;
          if(nums[m] > nums[r]) l = m+1;
          else r = m;
        }
      }

      return r;
    }
};

int main() {
  vector<int> nums {2,2,0,0,2,2};
  Solution s;
  cout<<s.findMin(nums);
  return 0;
}
