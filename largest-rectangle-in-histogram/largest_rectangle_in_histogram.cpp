#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

class Solution {
  public:
    int largestRectangleArea(vector<int>& heights) {
      int res = 0;
      int m = heights.size();

      for( int i = 0; i < m; ++i ) {
        // checking this prevents from TLE
        // find the local max (greater than left and right)
        if (i + 1 < m && heights[i] <= heights[i+1]) continue;
        int min_height = INT_MAX;
        for( int j = i; j >= 0; --j ) {
          if( heights[j] == 0 ) break;
          min_height = min(min_height, heights[j]);
          res = max( (i-j+1) * min_height, res);
        }
      }

      return res;
    }

    // using stack
    // TODO: review & understand
    int largestRectangleArea_stack(vector<int>& heights) {
      heights.push_back(0);
      int len = heights.size(), res = 0, cur = 1;
      vector<int> s(len+1, 0);
      s[0] = -1;

      for(int i = 1; i < len; ++i){
        while(cur && heights[i] < heights[s[cur]]) {
          // NOTE: undefined behavior
          // not guaranteed whether the left or the right side of `*` is evaluated first
          // heights[s[cur]] * (i - s[--cur] - 1);

          res = max(res, heights[s[cur]] * (i - s[cur-1] - 1));
          --cur;
        }

        s[++cur] = i;
      }
      return res;
    }
};

int main() {
  Solution s;
  vector<int> h = {2,1,5,6,2,3};
  cout<<s.largestRectangleArea_stack(h);
  return 0;
}


