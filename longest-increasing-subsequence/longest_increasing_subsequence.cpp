#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

class Solution {
  public:
    // O(n^2)
    int lengthOfLIS(vector<int>& nums) {
      if(nums.empty()) return 0;

      int n = nums.size();
      vector<int> len(n);

      for(int i = 0; i < n; ++i ){
        int maxi = 1;
        for( int j = 0; j < i; ++j ) {
          if( nums[j] < nums[i] )
            maxi = max( maxi, len[j] + 1);
        }
        len[i] = maxi;
      }

      return *max_element(len.begin(), len.end());
    }

    // O(nlogn)
    int lengthOfLIS_nlogn(vector<int> &nums) {
      if(nums.empty()) return 0;

      vector<int> ans {nums[0]};
      for(int n : nums)
        if( n > ans.back() ) ans.push_back(n);
        else *lower_bound(ans.begin(), ans.end(), n) = n;
      return ans.size();

    }
};

int main() {
  vector<int> nums = {10,9,2,5,3,7,101,18};
  Solution s;
  cout<<s.lengthOfLIS_nlogn(nums);
  return 0;
}
