#include <unordered_set>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
  public:
    // Hash table
    int singleNumber(vector<int>& nums) {
      unordered_set<int> set;
      for( unsigned i = 0; i < nums.size(); i++ ){
        if( set.find( nums[i] ) != set.end() ){
          set.erase( nums[i] );
        }else{
          set.insert( nums[i] );
        }
      }
      return * set.begin();
    }

    // Bit manipulation
    int singleNumberBM(vector<int>& nums) {
      int single = 0;
      for(int &n : nums) single ^= n; // &n, n (with or without reference) leads to 4ms performance difference
      return single;
    }

    // Shortest using std::accumulate()
    int singleNumberBM2(vector<int>& nums) {
      return accumulate(nums.begin(), nums.end(), 0, bit_xor<int>());
    }
};

int main(){
  vector<int> v{5, 2, 9, 0, 5, 9, 2};
  Solution solu;
  cout<<solu.singleNumberBM2(v)<<endl;
  return 0;
}

