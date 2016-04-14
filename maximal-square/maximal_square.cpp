#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
  public:
    int maximalSquare(vector<vector<char>>& matrix) {
      size_t m, n;
      if( (m = matrix.size()) == 0 || ( n = matrix.front().size() ) == 0 ) return 0;

      vector<vector<int>> area( m, vector<int>(n) );

      int maxi = 0;
      for( size_t i = 0; i < m; ++i ){ area[i][0] = matrix[i][0] - '0'; maxi = max( area[i][0], maxi); }
      for( size_t i = 0; i < n; ++i ){ area[0][i] = matrix[0][i] - '0'; maxi = max( area[0][i], maxi); }

      for( size_t i = 1; i < m; ++i )
        for( size_t j = 1; j < n; ++j )
          if( matrix[i][j] != '0' ) {
            area[i][j] = 1 +  min( area[i-1][j-1], min( area[i][j-1], area[i-1][j]) );
            maxi = max( maxi, area[i][j] );
          }

      return maxi * maxi;
    }
};

int main() {
  // wrong answer
  vector<vector<char>> m {{'0'},{'1'}};
  Solution s;
  cout<<s.maximalSquare(m);
  return 0;
}
