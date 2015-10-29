#include <iostream>
#include <vector>
#include <utility>
using namespace std;

class Solution {
  public:
    void moveZeroes(vector<int>& nums) {
      unsigned i = 0, cnt = 0;
      for(; i < nums.size() && nums[i] != 0; i++);
      for(; i < nums.size(); i++) {
        if( nums[i] == 0 )
          cnt++;
        else 
          swap(nums[i], nums[i-cnt]);
      }
    }
};

void inspect( const vector<int> & nums ) {
  for(int n : nums ) cout<<n<<' ';
  cout<<endl;
}

int main() {
  vector<int> ary = {0,0,12,22,1,0,0,0,0,0,0,3,0,1,0};
  Solution s;
  inspect(ary);
  s.moveZeroes(ary);
  inspect(ary);

  return 0;
}
