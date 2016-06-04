#include <iostream>
#include <vector>
using namespace std;

class NumArray {
  public:
    NumArray(vector<int> &nums) {
      partial_sums.resize(nums.size());

      int sum = 0;
      for(size_t i = 0; i < nums.size(); ++i ) {
        sum += nums[i];
        partial_sums[i] = sum;
      }

    }

    // NOTE: do not validate the i, j
    int sumRange(int i, int j) {
      return partial_sums[j] - (i <= 0 ? 0 : partial_sums[i-1]);
    }

  private:
    vector<int> partial_sums;
};

int main() {
  vector<int> nums = {-2, 0, 3,-5, 2, -1};
  NumArray num_arr(nums);
  cout<<num_arr.sumRange(0,2)<<endl;
  cout<<num_arr.sumRange(2,2)<<endl;
  cout<<num_arr.sumRange(2,5)<<endl;
  cout<<num_arr.sumRange(0,5)<<endl;
  return 0;
}
