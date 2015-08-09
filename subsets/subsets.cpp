#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
  public:
    vector<vector<int>> subsets(vector<int>& nums) {
      sort(nums.begin(), nums.end());
      vector<vector<int>> sets;
      sets.push_back(vector<int>());
      for(unsigned i = 0; i < nums.size(); i++) {
        unsigned size = sets.size();
        for(unsigned n = 0; n < size; n++) {
          vector<int> tmp = sets[n];
          tmp.push_back(nums[i]);
          sets.push_back(tmp);
        }
      }
      return sets;
    }
};

void inspect( const vector<vector<int>> & sets ) {
  for(unsigned i = 0; i < sets.size(); i++) {
    for(unsigned j = 0; j < sets[i].size(); j++) {
      cout<<sets[i][j]<<' ';
    }
    cout<<endl;
  }
}

int main() {
  vector<int> n0 = {};
  vector<int> n1 = {1};
  vector<int> n2 = {1,2};
  vector<int> n3 = {1,2,3};
  vector<int> n4 = {1,6,5,2,3};
  Solution s;

  inspect( s.subsets(n0) );
  return 0;
}
