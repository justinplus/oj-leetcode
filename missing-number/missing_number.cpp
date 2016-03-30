#include <iostream>
#include <vector>
#include <stdexcept>
#include <algorithm>
using namespace std;

class Solution {
  public:
    // bit operation
    int missingNumber_bit(vector<int>& nums) {
      int missing = 0;

      for( int i = 0; i < (int)nums.size(); ++i ) {
        missing ^= (i+1)^nums[i];
      }
      
      return missing;
    }

    // indexing
    int missingNumber_index(vector<int> &nums) {
      int n = nums.size();

      for(int i = 0; i < n; )
        if( nums[i] < n && nums[i] != nums[nums[i]] )
          swap(nums[i], nums[nums[i]]);
        else
          ++i;

      for(int i = 0; i < n; ++i)
        if(i != nums[i] ) return i;

      return n;
    }
    
};

int main() {
  vector<int> n{1,2,3,4,0};
  Solution s;
  cout<<s.missingNumber_bit(n)<<endl;
  cout<<s.missingNumber_index(n)<<endl;
  return 0;
}
