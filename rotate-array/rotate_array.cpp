#include <iostream>
#include <vecotor>
using namespace std;

class Solution {
  public:
    // NOTE: the idea of reversion
    void rotate(vector<int>& nums, int k) {
      k %= nums.size();

      reverse(nums.begin(), nums.end());
      reverse(nums.begin(), nums.begin() + k);
      reverse(nums.begin() + k , nums.end());
    }
};
