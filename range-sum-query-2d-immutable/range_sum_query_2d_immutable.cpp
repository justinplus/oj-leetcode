#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <sstream>
using namespace std;

// TLE: using hash
class NumMatrix_TLE {
  using Matrix = vector<vector<int>>;
  using Hash = unordered_map<string, int>;

  const Matrix &m;
  Hash hsh;

  public:
    // TODO: why `m{matrix}` is wrong
    NumMatrix_TLE(Matrix &matrix): m(matrix), hsh() { }

    int sumRegion(int row1, int col1, int row2, int col2) {
      stringstream ss;
      ss<<row1<<','<<col1<<','<<row2<<','<<col2;
      const string &key = ss.str();
      // cout<<"key: "<<key<<endl;
      // cout<<"row2: "<<row2<<endl;

      auto it = hsh.find(key);
      if(it == hsh.end()) {
        int sum = 0;
        for(int i = row1; i <= row2; ++i) {
          for(int j = col1; j <= col2; ++j) {
            sum += m[i][j];
          }
        }

        hsh[key] = sum;
        return sum;

      } else {
        return it->second;
      }

    }
};

// TODO: review
// summed area table (aka integral image)
class NumMatrix{
  using Matrix = vector<vector<int>>;

  Matrix sum_m;

  public:
    NumMatrix(Matrix &matrix) {
      int m = matrix.size();
      if( m == 0 ) return;
      int n = matrix.front().size();
      if( n == 0 ) return;

      sum_m = Matrix(m, vector<int>(n));
      sum_m[m-1][n-1] = matrix[m-1][n-1];

      for( int i = m-1; i >= 0; --i )
        for( int j = n-1; j >= 0; --j )
          sum_m[i][j] = matrix[i][j] + sumRegion(i+1, j) + sumRegion(i, j+1)
            - sumRegion(i+1, j+1);

    }


    int sumRegion(int row1, int col1, int row2, int col2) {
      return sumRegion(row1, col1) - sumRegion(row1, col2+1) - sumRegion(row2+1, col1)
        + sumRegion(row2+1, col2+1);

    }

    int sumRegion(int row, int col) {
      if(row >= (int)sum_m.size() || col >= (int)sum_m.front().size())
        return 0;
      else
        return sum_m[row][col];
    }
};

int main() {
  vector<vector<int>> m { {3, 0, 1, 4, 2}, {5, 6, 3, 2, 1}, {1, 2, 0, 1, 5}, {4, 1, 0, 1, 7}, {1, 0, 3, 0, 5} };

  NumMatrix nm(m);

  cout<<nm.sumRegion(0,0,0,0)<<endl;
  cout<<nm.sumRegion(2,1,4,3)<<endl;
  cout<<nm.sumRegion(1,1,2,2)<<endl;
  cout<<nm.sumRegion(1,2,2,4)<<endl;
  return 0;
}


// Your NumMatrix object will be instantiated and called as such:
// NumMatrix numMatrix(matrix);
// numMatrix.sumRegion(0, 1, 2, 3);
// numMatrix.sumRegion(1, 2, 3, 4);
