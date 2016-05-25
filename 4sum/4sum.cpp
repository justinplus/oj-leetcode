#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
  public:
    // NOTE: unordered_map is not that quick
    // TODO: improve
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
      vector<vector<int>> res;

      sort( nums.begin(), nums.end() );

      for( size_t i = 0; i < nums.size(); ++i ) {
        for( size_t j = i+1; j < nums.size(); ++j ) {
          size_t lo = j+1, hi = nums.size()-1;
          int rem = target - nums[i] - nums[j];
          while( lo < hi ) {
            if( nums[lo] + nums[hi] > rem ) --hi;
            else if( nums[lo] + nums[hi] < rem ) ++lo;
            else {
              res.push_back( {nums[i], nums[j], nums[lo], nums[hi]} );

              while( ++lo <= hi && nums[lo-1] == nums[lo] );
              while( lo <= --hi && nums[hi] == nums[hi+1] );
            }
          }
          while( j < nums.size() -1 && nums[j] == nums[j+1] ) ++j;
        }
        while( i < nums.size() -1 && nums[i] == nums[i+1] ) ++i;
      }

      return res;
    }
};

int main() {

  return 0;
}
