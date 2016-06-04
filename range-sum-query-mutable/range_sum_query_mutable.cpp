#include <iostream>
#include <vector>
using namespace std;

class NumArray {
  public:
    NumArray(vector<int> &nums) : nums(nums) {
      tree.resize(nums.size() + 1);
      for( int i = 1; i <= (int)nums.size(); ++i ) {
        int sum = nums[i-1];
        int idx = i - 1;
        int limit = i - (i & -i);
        while( idx > limit ) {
          sum += tree[idx];
          idx -= idx & -idx;
        }
        tree[i] = sum;
      }
    }

    void update(int i, int val) {
      int idx = i + 1;
      int delta = val - nums[i];
      nums[i] = val;

      while( idx < (int)tree.size() ) {
        tree[idx] += delta;
        idx += idx & -idx;
      }
    }

    int sumRange(int i, int j) {
      return sum(j+1) - sum(i);
    }

  private:
    int sum(int idx) {
      int sum = 0;
      while( idx > 0 ) {
        sum += tree[idx];
        idx -= idx & -idx;
      }
      return sum;
    }

    // TODO: without nums; review
    vector<int> nums;
    vector<int> tree;
};

void WA() {
  // NOTE: the `i`th of nums can be updated more than once
  vector<int> nums = {7,2,7,2,0};
  NumArray bit(nums);
  bit.update(4,6);
  bit.update(0,2);
  bit.update(0,9);
  cout<<bit.sumRange(4,4)<<endl;
  bit.update(3,8);
  cout<<bit.sumRange(0,4)<<endl;
  bit.update(4,1);
  cout<<bit.sumRange(0,3)<<endl;
  cout<<bit.sumRange(0,4)<<endl;
  bit.update(0,4);
}

void WA2() {
  vector<int> nums {-28,-39,53,65,11,-56,-65,-39,-43,97};
  NumArray bit(nums);
  cout<<bit.sumRange(0,0)<<endl;
  cout<<bit.sumRange(1,1)<<endl;
  cout<<bit.sumRange(2,2)<<endl;
  cout<<bit.sumRange(3,3)<<endl;
  cout<<bit.sumRange(4,4)<<endl;
  cout<<bit.sumRange(5,5)<<endl;
  cout<<bit.sumRange(6,6)<<endl;
  cout<<bit.sumRange(7,7)<<endl;
  cout<<bit.sumRange(8,8)<<endl;
  cout<<bit.sumRange(9,9)<<endl;

  cout<<"--"<<endl;

  cout<<bit.sumRange(5,6)<<endl;
  bit.update(9,27);
  cout<<bit.sumRange(2,3)<<endl;
  cout<<bit.sumRange(6,7)<<endl;
  bit.update(1,-82);
  bit.update(3,-72);
  cout<<bit.sumRange(3,7)<<endl;
  cout<<bit.sumRange(1,8)<<endl;
  bit.update(5,13);
  bit.update(4,-67);
}

int main() {
  // NOTE the `-` of unsigned int;
  // int a = 6;
  // unsigned int ua = 6;
  // cout<<( a & -a )<<endl;
  // cout<<( ua & -ua )<<endl;
  // return 0;

  WA2();
}
// Your NumArray object will be instantiated and called as such:
// NumArray numArray(nums);
// numArray.sumRange(0, 1);
// numArray.update(1, 10);
// numArray.sumRange(1, 2);
