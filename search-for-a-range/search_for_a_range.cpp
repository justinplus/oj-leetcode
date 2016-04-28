#include <iostream>
#include <vector>
using namespace std;

class Solution {
  public:
    vector<int> searchRange(vector<int>& nums, int target) {
      int begin = 0, end = nums.size() - 1;
      int mid;
      int pos;
      vector<int> output;
      while( begin <= end ) {
        mid = (begin + end) / 2;
        if(nums[mid] == target){
          for( pos = mid-1; pos >= 0; pos-- ){
            if(nums[pos] != target) break;
          }
          output.push_back(pos+1);
          for( pos = mid+1; pos < (int)nums.size(); pos++) {
            if(nums[pos] != target) break;
          }
          output.push_back(pos-1);
          return output;
        } else if (nums[mid] > target) {
          end = mid - 1;
        } else {
          begin = mid + 1;
        }
      }

      output.push_back(-1);
      output.push_back(-1);
      return output;
    }

    // by find the upper and lower bound
    vector<int> searchRange_upper_lower(vector<int>& nums, int target) {
      vector<int> res {-1,-1};
      size_t bg = 0, end = nums.size(), mid;
      while( bg < end ) {
        mid = (bg + end) / 2;
        if( nums[mid] >= target ) end = mid;
        else bg = mid + 1;
      }
      if( bg == nums.size() || nums[bg] != target) return res;
      else
        res[0] = bg;

      bg = 0, end = nums.size();
      while( bg < end ) {
        mid = (bg + end) / 2;
        if( nums[mid] > target ) end = mid;
        else bg = mid + 1;
      }

      res[1] = --bg;
      return res;
    }
};



void inspect( const vector<int> & v ) {
  cout<<v[0]<<'~'<<v[1]<<endl;
}

int main() {
  vector<int> arr = { 5, 7, 7, 8, 8, 10 };
  Solution s;
  inspect(s.searchRange(arr, 4));
  inspect(s.searchRange(arr, 5));
  inspect(s.searchRange(arr, 6));
  inspect(s.searchRange(arr, 7));
  inspect(s.searchRange(arr, 8));
  inspect(s.searchRange(arr, 9));
  inspect(s.searchRange(arr, 10));
  inspect(s.searchRange(arr, 11));
  return 0;
}

