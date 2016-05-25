#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
  public:
    // TLE
    bool containsNearbyDuplicate_TLE(vector<int>& nums, int k) {
      for( size_t i = 0; i < nums.size() - 1; ++i )
        for( size_t j = 1; j <= (size_t)k && i + j < nums.size(); ++j )
          if(nums[i] == nums[i+j]) return true;

      return false;
    }

    // assume the k is valid
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
      unordered_map<int,size_t> map;

      for( size_t i = 0; i < nums.size(); ++i ) {
        auto it = map.find(nums[i]);
        if( it == map.end() ) map[nums[i]] = i;
        else
          if( i - it->second <= (size_t)k )
            return true;
          else
            it->second = i;
      }

      return false;
    }
};

int main() {
  return 0;
}
