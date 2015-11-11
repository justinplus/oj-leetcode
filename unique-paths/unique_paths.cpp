#include <iostream>
#include <vector>
#include <utility>
using namespace std;

class Solution {
  public:
    int uniquePaths(int m, int n) {
      if( m == 0 || n == 0 ) return 0;
      if( m > n ) swap(m, n);

      int record[m][n]; 
      for( int i = 0; i < n; record[0][i] = 1, i++ );
      for( int i = 1; i < m; record[i][0] = 1, i++ );


      for( int i = 1; i < m; i++ ) {
        for( int j = i; j < n; j++ ) {
            record[i][j] = record[i-1][j] + record[i][j-1];
            if( j < m ) record[j][i] = record[i][j];
        }
      }

      return record[m-1][n-1];
    }
};

int main() {
  Solution s;
  cout<<s.uniquePaths(0, 0);
  return 0;
}
