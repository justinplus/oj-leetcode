#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
  public:
    // twice binary search
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
      if(matrix[0].empty()) return false;

      // NOTE: the initial value of `end`
      int begin = 0, end = matrix.size(), mid;
      while( begin < end) {
        mid = (begin + end) / 2;
        if( matrix[mid].front() >= target ) end = mid;
        else begin = mid + 1;
      }

      if( begin < matrix.size() && matrix[begin].front() == target )
        return true;
      else if( begin > 0 )
        return binary_search(matrix[begin-1].begin(), matrix[begin-1].end(), target);
      else
        return false;
    }
};

int main() {
  vector<int> nums = {1,2,3,6,10};

  cout<<(lower_bound(nums.begin(), nums.end(), 11)==nums.end());

  return 0;
}
