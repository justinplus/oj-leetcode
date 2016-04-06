#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

class Solution {
  public:
    // heap
    int findKthLargest(vector<int>& nums, int k) {
      make_heap( nums.begin(), nums.end() );
      for( int i=0; i<k-1; i++ ){
        pop_heap( nums.begin(), nums.end()-i );
        // nums.pop_back();
      }
      return nums.front();
    }

    // random select
    // TODO: why slower
    int findKthLargest_rs(vector<int>& nums, int k) {
      if(k < 1 || k > nums.size()) return -1;
      r_select(nums, 0, nums.size()-1, nums.size()+1-k);
    }

    static int partition(vector<int> &nums, int front, int back) {
      int i = front;
      for(int j = front+1; j <= back; ++j)
        if(nums[j] < nums[front]) swap(nums[++i], nums[j]);
      swap(nums[front], nums[i]);
      return i;
    }

    static int r_select(vector<int> &nums, int front, int back, int nth) {
      int p = partition(nums, front, back);
      int k = p - front + 1;
      if( k == nth ) return nums[p];
      else if( k > nth )
        return r_select(nums, front, p-1, nth);
      else
        return r_select(nums, p+1, back, nth-k);
    }
};

int main() {
  int test[] = {3, 2, 1, 5, 6, 4};
  vector<int> v(test, test+6);
  Solution solu;
  cout<< solu.findKthLargest(v, 3);
  cout<< "the array: \n";
  for(unsigned int i=0; i<v.size(); i++){
    cout<<v[i]<<'\t';
  }
  return 0;
}


