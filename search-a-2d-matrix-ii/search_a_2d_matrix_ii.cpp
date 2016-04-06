#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
  public:
    using Matrix = vector<vector<int>>;
    // TODO: improve
    bool searchMatrix(Matrix &matrix, int target) {
      if(matrix.empty() || matrix[0].empty()) return false;
      return searchMatrix(matrix, 0, matrix.size() -1, 0, matrix[0].size() - 1, target);
    }

    bool searchMatrix(Matrix &m, int top, int bottom, int left, int right, int target) {
      if(top > bottom || left > right){
        // cout<<"false: "<<"top: "<<top<<" bottom: "<<bottom<<" left: "<<left<<" right: "<<right<<endl;
        return false;
      }

      // cout<<"top: "<<top<<" bottom: "<<bottom<<" left: "<<left<<" right: "<<right<<endl;

      int begin = 0, end = min(bottom-top, right-left) + 1, mid;
      while( begin < end ) {
        mid = (begin + end) / 2;
        if(m[top+mid][left+mid] >= target) end = mid;
        else begin = mid + 1;
      }
      // cout<<"begin: "<<begin<<endl;

      if( begin <= min(bottom-top, right-left) && m[top+begin][left+begin] == target ) return true;
      else
        return searchMatrix(m, top+begin, bottom, left, left+begin - 1, target) ||
          searchMatrix(m, top, top+begin - 1, left+begin, right, target);

    }
};

int main() {
  vector<vector<int>> m = {
    {1,   4,  7, 11, 15},
    {2,   5,  8, 12, 19},
    {3,   6,  9, 16, 22},
    {10, 13, 14, 17, 24},
    {18, 21, 23, 26, 30}
  };
  vector<vector<int>> m2={{}};

  Solution s;
  cout<<s.searchMatrix(m, 13);

  return 0;
}
