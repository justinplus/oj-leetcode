#include <iostream>
#include <vector>
#include <algorithm>
#include <array>
#include <climits>
using namespace std;

class Solution {
  public:
    static const char one = '1';
    static const char zero = '0';
    // low performance (472ms)
    int maximalRectangle_lp(vector<vector<char>>& matrix) {

      size_t m, n;
      if( (m = matrix.size()) == 0 || ( n = matrix.front().size() ) == 0 ) return 0;

      vector<vector<int>> height( m, vector<int>(n) );

      int ans = 0;
      if( matrix[0][0] == one ) ans = height[0][0] = 1;

      for( size_t i = 1; i < n; ++i )
        if( matrix[0][i] == one ) {
          height[0][i] = 1;
          for( int k = (int) i; k >= 0; --k) {
            if( height[0][k] == 0 ) break;
            ans = max( (int)i-k+1, ans);
          }
        }

      for( size_t i = 1; i < m; ++i )
        for( size_t j = 0; j < n; ++j )
          if( matrix[i][j] == one ) {
            height[i][j] = 1 + height[i-1][j];
            int min_height = INT_MAX;
            for( int k = (int) j; k >= 0; --k) {
              if( height[i][k] == 0 ) break;
              min_height = min(min_height, height[i][k]);
              ans = max( ((int)j-k+1) * min_height, ans);
            }
          }

      return ans;
    }

    // 20ms, TODO: why? just because using 2D vector
    int maximalRectangle(vector<vector<char>>& matrix) {

      size_t m, n;
      if( (m = matrix.size()) == 0 || ( n = matrix.front().size() ) == 0 ) return 0;

      vector<int> height( n, 0 );
      int ans = 0;

      for( size_t i = 0; i < m; ++i )
        for( size_t j = 0; j < n; ++j )
          if( matrix[i][j] == one ) {
            ++height[j];
            int min_height = INT_MAX;
            for( int k = (int) j; k >= 0; --k) {
              if( height[k] == 0 ) break;
              min_height = min(min_height, height[k]);
              ans = max( ((int)j-k+1) * min_height, ans);
            }
          } else {
            height[j] = 0;
          }
      return ans;
    }

};

int main() {
  // wrong answer
  vector<vector<char>> m {{'0','1'},{'0','1'}};
  Solution s;
  cout<<s.maximalRectangle(m);
  return 0;
}
