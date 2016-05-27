#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

class Solution {
  public:
    int threeSumClosest(vector<int>& nums, int target) {
      sort( nums.begin(), nums.end() );

      int pos_dist = INT_MAX;
      int neg_dist = INT_MIN;

      for( size_t i = 0; i < nums.size(); ++i ) {
        int j = i+1, k = nums.size() - 1;
        int rem = target - nums[i];

        while( j < k ) {
          int sum = nums[j] + nums[k];
          if( sum > rem ) {
            --k;
            pos_dist = min( sum - rem, pos_dist);
          }
          else if( sum < rem ) {
            ++j;
            neg_dist = max( sum - rem, neg_dist);
          }
          else
            return target;
        }

        while( i < nums.size() - 1 && nums[i] == nums[i+1] ) ++i;
      }

      // NOTE: `? :` and `+` predecence
      return target + ( abs((long)pos_dist) > abs((long)neg_dist) ? neg_dist : pos_dist );
    }
};

int main() {
  vector<int> nums {0,0,0};
  Solution s;
  cout<<s.threeSumClosest(nums, 1);
  return 0;
}
