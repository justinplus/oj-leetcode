#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
  public:
    static int partition(vector<int> &nums, int front, int back) {
      int i = front;
      for(int j = front+1; j <= back; ++j)
        if(nums[j] < nums[front]) swap(nums[++i], nums[j]);
      swap(nums[front], nums[i]);
      return i;
    }

    static int r_select(vector<int> &nums, int front, int back, int nth) {
      for(auto n : nums) cout<<n<<' ';
      cout<<endl;
      int p = partition(nums, front, back); 
      int k = p - front + 1;
      cout<<"front: "<<front<<" back: "<<back<<" nth: "<<nth<<" p: "<<p<<endl;
      if( k == nth ) return nums[p];
      else if( k > nth )
        return r_select(nums, front, p-1, nth);
      else 
        return r_select(nums, p+1, back, nth-k);
    }

    // TODO: review, use self to index
    int firstMissingPositive(vector<int>& nums) {
      int n = (int)nums.size();
      for(int i = 0; i < n; )
        if(nums[i] > 0 && nums[i] <= n && nums[i] != nums[nums[i] - 1] )
          swap(nums[i], nums[nums[i] - 1]);
        else
          ++i;

      for(int i = 0; i < n; ++i)
        if( nums[i] != i+1 ) return i+1;

      return n + 1;
    }
};

int main() {
  vector<int> nums = { 2,2,2,2,2,8,6 };
  Solution s;
  cout<<s.firstMissingPositive(nums);
  return 0;
}
