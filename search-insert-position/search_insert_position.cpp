#include <iostream>
#include <vector>
using namespace std;

class Solution {
  public:
    int searchInsert(vector<int>& nums, int target) {
      int begin = 0, end = nums.size() - 1, mid = -1;
      if( end == -1 ) return 0;

      while( end >= begin ) {
        mid = (begin + end) / 2;
        if( nums[mid] == target ) return mid;
        else if( nums[mid] > target ) end = mid - 1; 
        else begin = mid + 1;
      }

      if(nums[mid] > target) return mid;
      else return mid+1;

    }
};

int main() {
  vector<int> v {};
  Solution s;
  cout<<s.searchInsert(v,5);
  cout<<s.searchInsert(v,2);
  cout<<s.searchInsert(v,7);
  cout<<s.searchInsert(v,0);
  return 0;
}
