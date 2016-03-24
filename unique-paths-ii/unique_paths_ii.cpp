#include <iostream>
#include <vector>
using namespace std;

class Solution {
  using Matrix = vector<vector<int>>;
  public:
    int uniquePathsWithObstacles(Matrix &obstacleGrid) {
      if( obstacleGrid.empty() || obstacleGrid[0].empty() ) return 0;

      int m = obstacleGrid.size();
      int n = obstacleGrid.front().size();

      Matrix paths (m, vector<int>(n));
      // NOTE: take care of initialization
      paths[0][0] = obstacleGrid[0][0] == 0 ? 1 : 0;

      for(int i = 1; i < n; ++i )
        if(obstacleGrid[0][i] == 0 )
          paths[0][i] = paths[0][i-1];

      for(int j = 1; j < m; ++j )
        if(obstacleGrid[j][0] == 0 )
          paths[j][0] = paths[j-1][0];


      for(int i = 1; i < n; ++i )
        for(int j = 1; j < m; ++j ) 
          if(obstacleGrid[j][i] == 0 )
            paths[j][i] = paths[j-1][i] + paths[j][i-1];

      return paths.back().back();
    }
};

int main() {
  vector<vector<int>> grid = { {0,0,0}, {0,1,0}, {0,0,0}};
  Solution s;
  cout<<s.uniquePathsWithObstacles(grid);
  return 0;
}
