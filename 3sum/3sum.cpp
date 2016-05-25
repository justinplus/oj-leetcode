#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
  public:
    // TODO: improve, try new methods
    vector<vector<int>> threeSum(vector<int>& nums) {
      vector<vector<int>> res;
      unordered_map<int, size_t> counter;
      for( int num : nums ) ++counter[num];

      sort( nums.begin(), nums.end() );

      for( size_t i = 0; i < nums.size(); ++i ) {
        for( size_t j = i+1; j < nums.size(); ++j ) {
          int comp = -( nums[i] + nums[j] );
          if( nums[j] <= comp ) {
            size_t c = 1;
            if( comp == nums[i] ) ++c;
            if( comp == nums[j] ) ++c;
            if( counter[comp] >= c )
              res.push_back( {nums[i], nums[j], comp} );
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
