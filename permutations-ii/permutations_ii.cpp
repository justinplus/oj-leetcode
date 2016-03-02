#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
  public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
      vector<vector<int>> res;
      vector<int> vec(nums.size(), -1);
      // NOTE: must sort first
      sort(nums.begin(), nums.end());
      permuteUnique(nums, vec, 0, res);

      return res;
    }

    void permuteUnique(vector<int>& nums, vector<int>& vec, int c, vector<vector<int>>& res) {
      int size = (int) nums.size();
      if( c == size ) {
        res.push_back( vector<int>(size) );
        for(int n = 0; n < size; n++) {
          res.back()[vec[n]] = nums[n];
        }
      } else {
        int m = -1;
        for( int i = 0; i < size; i++ ) {
          if( vec[i] == -1 && ( m == -1 || nums[i] != nums[m])) {
            m = i;
            vec[i] = c;
            permuteUnique(nums, vec, c+1, res);
            vec[i] = -1;
          }
        }
      }
    }
};

int main() {
  Solution s;
  vector<int> nums = {3,3,0,3};

  vector<vector<int>> res = s.permuteUnique(nums);
  for( auto & vec : res ) {
    for( auto num : vec ) {
      cout<<num<<' ';
    }
    cout<<endl;
  }

  cout<<res.size()<<endl;

  return 0;
}
