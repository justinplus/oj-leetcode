#include <iostream>
#include <queue>
#include <deque>
#include <vector>
using namespace std;

class Solution {
  public:
    // assume `1 <= k <= nums.size()`
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
      deque<int> deq;
      vector<int> res;

      for( int i = 0; i < k; ++i ) {
        while( !deq.empty() && nums[i] > deq.back() ) { deq.pop_back(); }
        deq.push_back( nums[i] );
      }

      if(!deq.empty()) res.push_back(deq.front());

      for( int i = k; i < (int) nums.size(); ++i ) {
        if( deq.front() == nums[i-k] ) deq.pop_front();
        while( !deq.empty() && nums[i] > deq.back() ) { deq.pop_back(); }
        deq.push_back( nums[i] );
        res.push_back(deq.front());
      }

      return res;
    }
};

int main() {
  return 0;
}
