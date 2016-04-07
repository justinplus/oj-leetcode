#include <iostream>
#include <vector>
using namespace std;

class Solution {
  public:
    int climbStairs(int n) {
      vector<int> nums {1, 1};

      for( int i = 2; i <= n; ++i )
        nums.push_back(nums[i-1] + nums[i-2]);

      return nums.back();
    }
};


int main() {
  Solution s;
  cout<<s.climbStairs( 0);
  return 0;
}
