#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
  public:
    int rob(vector<int>& nums) {
      int ppre = 0, pre = 0, cur = 0;
      for(int n : nums) {
        int tmp = max(n + pre, n + ppre);
        ppre = pre;
        pre = cur;
        cur = tmp;
      }

      return max(ppre, max(pre, cur) );
    }
};

int main() {
  vector<int> nums = {1,212,3,2,1,3,2,1};
  Solution s;
  cout<<s.rob(nums);

  return 0;
}
