#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Solution {
  public:
    int minSubArrayLen(int s, vector<int>& nums) {
      size_t start = 0, end = 0, min_len = INT_MAX;
      int sum = 0;

      bool is_qualified = false;

      while( end < nums.size() ) {

        if( (sum += nums[end++]) >= s ) is_qualified = true;

        while( is_qualified ) {
          min_len = min( min_len, end - start);
          if( (sum -= nums[start++] ) < s) is_qualified = false;
        }
      }

      return min_len == INT_MAX? 0 : min_len;
    }
};

int main() {
  vector<int> nums = {2,3,1,2,4,3};
  vector<int> empty = {};
  Solution s;
  cout<<s.minSubArrayLen(7, empty);
  return 0;
}
