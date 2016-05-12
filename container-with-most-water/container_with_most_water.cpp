#include <iostream>
#include <vector>
#include <stack>
#include <utility>
#include <algorithm>
using namespace std;

// misunderstand the problem
class Solution1 {
  public:
    // assume: elements of height are non-negative
    int maxArea(vector<int>& height) {
      height.push_back(0);

      stack<pair<int,int>> stk;
      stk.push({-1, 0});
      if( !height.empty() ) stk.push({0,height.front()});

      size_t max_area = 0;

      for( size_t i = 1; i < height.size(); ++i ) {
        if( height[i] < height[i-1] ) {
          while( !stk.empty() && stk.top().second > height[i] ) {
            max_area = max(max_area, (i - stk.top().first) * stk.top().second);
            // cout<<"top: "<<stk.top().first<<":"<<stk.top().second<<endl;
            // cout<<"max_area: "<<max_area<<endl;
            stk.pop();
          }
          stk.push( {stk.top().first + 1, height[i]} );
        } else {
          stk.push( {i, height[i] });
        }
      }

      return max_area;

    }
};

// TODO: [CMP] largest rectangle in histogram
class Solution {
  public:
    int maxArea(vector<int>& height) {
      size_t i = 0, j = height.size()-1, max_area = 0;

      while( i < j ) {
        if ( height[i] > height[j] ) {
          max_area = max( max_area, (j-i) * height[j]);
          size_t next_j = j-1;
          for( ; next_j > i && height[j] >= height[next_j]; --next_j );
          j = next_j;

        } else { /* height[i] <= height[j] */
          max_area = max( max_area, (j-i) * height[i]);
          size_t next_i = i+1;
          for( ; next_i < j && height[i] >= height[next_i]; ++next_i );
          i = next_i;
        }

      }

      return max_area;

    }
};

int main() {
  vector<int> height {1,2,3};
  Solution s;
  cout<<s.maxArea(height)<<endl;
  return 0;
}
