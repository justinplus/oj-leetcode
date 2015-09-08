#include <unordered_set>
#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;

class Solution {
  public:
    bool containsDuplicate(vector<int>& nums) {
      unordered_set<int> set;
      for(int n : nums) {
        if( !set.insert(n).second ) return true;
      }
      return false;
    }

    bool containsDuplicateSort(vector<int>& nums) {
      sort(nums.begin(), nums.end());
      // for(auto it = nums.begin(); it != nums.end()-1; ++it) {
        // if(*it == *(it+1)) return true;
      // }
      // Attn: invalid dereference when nums is empty
      for(unsigned i = 1; i < nums.size(); ++i)
        if(nums[i] == nums[i-1]) return true;
      return false;
    }
};

int main(){
  Solution s;
  vector<int> v = {1,2,3,4,5,6};
  cout<<s.containsDuplicateSort(v)<<endl;
  v.push_back(1);
  cout<<s.containsDuplicateSort(v)<<endl;
  vector<int> v1;
  cout<<s.containsDuplicateSort(v1)<<endl;
  return 0;
}
