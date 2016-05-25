#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>
#include <algorithm>
using namespace std;

class Solution {
  public:
    // TLE
    // assume the k, j is valid
    bool containsNearbyAlmostDuplicate_TLE(vector<int>& nums, int k, int t) {
      unordered_map<int,size_t> map;

      for( size_t i = 0; i < nums.size(); ++i ) {
        auto it = map.find(nums[i]);
        if( it == map.end() ) map[nums[i]] = i;
        else
          if( i - it->second <= (size_t)k )
            return true;
          else
            it->second = i;

        for( int j = 1; j <= t; ++j ) {
          it = map.find(nums[i] - j);
          if( it != map.end() && i - it->second <= (size_t)k ) return true;
          it = map.find(nums[i] + j);
          if( it != map.end() && i - it->second <= (size_t)k ) return true;
        }
      }

      return false;
    }

    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
      if( k <= 0 || t < 0 ) return false;

      map<long,size_t> map;

      for( size_t i = 0; i < nums.size(); ++i ) {
        auto p = map.insert({nums[i],i});
        auto it = p.first;
        if( p.second == false ) {
          if( i - it->second <= (size_t)k )
            return true;
          else
            it->second = i;
        }

        for( ++it; it != map.end() && it->first - nums[i] <= t; ++it)
          if( i - it->second <= (size_t)k) {
            return true;
          }

        it = p.first;

        while(true) {
          if( it != map.begin() ) --it;
          else break;
          if( nums[i] - it->first <= t ) {
            if( i - it->second <= (size_t)k) return true;
          }
          else break;
        }

      }

      return false;
    }

    // TODO: try solving by sorting

};

int main() {
  vector<int> nums = {0,9,6,324,12,43,12,3};
  Solution s;
  // cout<<s.containsNearbyAlmostDuplicate(nums, 1, 2)<<endl;

  // wrong answer
  vector<int> nums_1 = {-1, -1};
  // cout<<s.containsNearbyAlmostDuplicate(nums_1, 1, -1)<<endl;

  // wrong answer [-1, 2147483647] 1 2147483647
  vector<int> nums_2 = {-1, 2147483647};
  cout<<s.containsNearbyAlmostDuplicate(nums_2, 1, 2147483647)<<endl;
  return 0;
}
