#include <iostream>
#include <vector>
#include <utility>
using namespace std;

class Solution {
  public:
    int removeElement(vector<int>& nums, int val) {
      size_t i, j;
      for(i = 0; i < nums.size() && nums[i] != val; ++i);
      for(j = i+1; j < nums.size(); ++j) if( nums[j] != val ) swap(nums[i++], nums[j]);
    }
    return i;
};

