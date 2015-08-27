#include <iostream>
#include <vector>
#include <stdexcept>
using namespace std;

class Solution {
  public:
    int missingNumber(vector<int>& nums) {
      int missing = 0;

      for( int i = 0; i < (int)nums.size(); ++i ) {
        missing ^= (i+1)^nums[i];
      }
      
      return missing;
    }
};

int main() {
  vector<int> n{1,2,3,4,0,6};
  Solution s;
  cout<<s.missingNumber(n)<<endl;
  return 0;
}
