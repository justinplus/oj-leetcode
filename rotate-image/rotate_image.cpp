#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
  public:
    void rotate(vector<vector<int>>& matrix) {
      float offset = float(matrix.size()-1) / 2;
      int odd = matrix.size()%2;
      int half = matrix.size()/2;

      float x, y;
      int t1, t2;

      for(int i = 0; i < half; i++) {
        for(int j = 0; j < half + odd; j++) { // extra handling for odd matrix
          x = j; y = i; // index i, j map to coordinates x, y 
          t1 = matrix[y][x];
          for(int n = 0; n < 3; n++ ) {
            rotateXY( x, y, offset );
            t2 = matrix[y][x];
            matrix[y][x] = t1;
            t1 = t2;
          }
          matrix[i][j] = t1;
        }
      }
    }

    void rotateXY( float & x, float & y, float offset ) {
      x -= offset;
      y -= offset;
      y = -y;
      swap(x, y);
      x += offset;
      y += offset;
    }
}; // TODO: Specific method for 90 degrees

void inspect( const vector<vector<int>> & m ) {
  for( unsigned i = 0; i < m.size(); i++) {
    for( unsigned j = 0; j < m.size(); j++) {
      cout<<m[i][j]<<' ';
    }
    cout<<endl;
  }
}

int main() {
  float x = 0, y = 1;
  Solution s;
  s.rotateXY(y, x, 1.5);
  cout<<x<<' '<<y<<endl;
  vector<vector<int>> m;
  m.push_back({1,2,3});
  m.push_back({4,5,6});
  m.push_back({7,8,9});
  inspect(m);
  s.rotate(m);
  inspect(m);
  return 0;
}

