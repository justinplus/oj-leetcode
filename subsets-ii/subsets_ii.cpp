#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
  public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
      vector<vector<int>> res;
      vector<int> vec(nums.size(), 0);

      sort(nums.begin(), nums.end());
      subsetsWithDup(res, vec, nums, 0);

      return res;
    }

    void subsetsWithDup(vector<vector<int>> &res, vector<int> &vec, const vector<int>& nums, int d) {
      if( d == (int)vec.size() ) {
        // for(auto x:vec) cout<<x<<' ';
        // cout<<endl;

        res.push_back({});
        for( unsigned i = 0; i < vec.size(); ++i )
          if( vec[i] == 1 ) res.back().push_back(nums[i]);
        return;
      }

      for( int i = 0; i < 2; ++i) {
        // NOTE: `nums.size() > 1` ->  `d > 0`
        if( d > 0 && nums[d] == nums[d-1] && vec[d-1] == 0 && i == 1 )
          continue;

        vec[d] = i;
        subsetsWithDup(res, vec, nums, d+1);
        vec[d] = 0;
      }
    }
};

int main() {
  // wrong answer
  vector<int> nums {4, 1, 0}; 
  Solution s;
  auto res = s.subsetsWithDup(nums);

  for(auto &vec : res){
    for(auto n : vec) cout<<n<<' ';
    cout<<endl;
  }

  return 0;
}
