#include <iostream>
#include <vector>
using namespace std;

class Solution {
  public:
    // O(n)
    void setZeroes(vector<vector<int>>& matrix) {
      int m, n;
      if( ( m = matrix.size() ) == 0 || ( n = matrix.front().size() ) == 0) return;
      int rows[m] {};
      int cols[n] {};

      for( int i = 0; i < m; ++i )
        for(int j = 0; j < n; ++j )
          if( matrix[i][j] == 0 ) {
            rows[i] = 1;
            cols[j] = 1;
          }

      for( int i = 0; i < m; ++i )
        if(rows[i] == 1)
          for(int j = 0; j < n; ++j )
            matrix[i][j] = 0;

      for( int i = 0; i < n; ++i )
        if(cols[i] == 1)
          for(int j = 0; j < m; ++j )
            matrix[j][i] = 0;
    }

    // O(1)
    void setZeroes_O1(vector<vector<int>>& matrix) {
      size_t m, n;
      if( ( m = matrix.size() ) == 0 || ( n = matrix.front().size() ) == 0) return;
      bool is_first_col_zero = false, is_first_row_zero = false;
      size_t i, j;
      for( i = 0; i < n; ++i )
        if(matrix[0][i] == 0) {
          is_first_row_zero = true;
          break;
        }

      for( i = 0; i < m; ++i )
        if(matrix[i][0] == 0) {
          is_first_col_zero = true;
          break;
        }

      for( i = 1; i < m; ++i )
        for( j = 1; j < n; ++j )
          if( matrix[i][j] == 0 )
            matrix[i][0] = matrix[0][j] = 0;

      for( i = 1; i < n; ++i )
        if(matrix[0][i] == 0)
          for( size_t k = 1; k < m; ++k)
            matrix[k][i] = 0;

      for( i = 1; i < m; ++i )
        if(matrix[i][0] == 0 )
          for( size_t k = 1; k < n; ++k )
            matrix[i][k] = 0;

      if(is_first_row_zero == true)
        for( size_t k = 0; k < n; ++k )
          matrix[0][k] = 0;

      if(is_first_col_zero == true)
        for(size_t k = 0; k < m; ++k )
          matrix[k][0] = 0;

    }
};
