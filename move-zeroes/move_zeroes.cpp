#include <iostream>
#include <vector>
#include <utility>
using namespace std;

class Solution {
  public:
    // one pointer with an offset
    void moveZeroes(vector<int>& nums) {
      size_t i = 0, cnt = 0;
      for(; i < nums.size() && nums[i] != 0; i++);
      for(; i < nums.size(); i++) {
        if( nums[i] == 0 )
          cnt++;
        else 
          swap(nums[i], nums[i-cnt]);
      }
    }

    // tow pointers
    void moveZeroes_2p(vector<int> & nums) {
      size_t i, j;
      for(i = 0; i < nums.size() && nums[i] != 0; ++i);
      for(j = i+1; j < nums.size(); ++j) if( nums[j] != 0 ) swap( nums[i++], nums[j] );
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
  // s.moveZeroes_2p(ary);
  inspect(ary);

  return 0;
}
