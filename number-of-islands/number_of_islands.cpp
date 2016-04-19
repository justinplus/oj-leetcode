#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
using namespace std;

class UnionSet {
  static const char land = '1';
  vector<int> ids;

  public:
  UnionSet(vector<vector<char>> &grid) {
    for( auto &vec : grid)
      for(auto ch : vec)
        ids.push_back(ch == land ? -1 : -2);
  }

  void connect(int i, int j) {
    // NOTE:
    int r_i = find(i), r_j = find(j);
    if( r_i != r_j) ids[r_i] = r_j;
  }

  bool connected(int i, int j) {
    return find(j) == find(i);
  }

  int find(int i) {
    while( ids[i] >= 0 ) i = ids[i];
    return i;
  }

  int count() {
    return std::count(ids.begin(), ids.end(), -1);
  }

  void inspect() {
    for(auto n : ids) cout<<n<<' ';
    cout<<endl;
  }
};

class Solution {
  public:
    static const char land = '1';
    static const char water = '0';
    using Graph = vector<unordered_set<int>>;
    int numIslands(vector<vector<char>>& grid) {
      int m, n;
      if( (m = grid.size()) == 0 || (n = grid.front().size()) == 0 ) return 0;

      UnionSet us(grid);

      for(int i = 1; i < m; ++i)
        if( grid[i][0] == land && grid[i-1][0] == land)
          us.connect( i * n, (i-1) * n);

      for(int i = 1; i < n; ++i)
        if( grid[0][i] == land && grid[0][i-1] == land)
          us.connect( i , i-1 );

      for( int i = 1; i < m; ++i )
        for( int j = 1; j < n; ++j ) {
          if( grid[i][j] == land ) {
            if( grid[i][j-1] == land ) us.connect( i*n +j, i*n +j-1);
            if( grid[i-1][j] == land ) us.connect( i*n +j, (i-1)*n +j);
          }
        }

      return us.count();
    }

    int numIslands_graph(vector<vector<char>>& grid) {
      int m, n;
      if( (m = grid.size()) == 0 || (n = grid.front().size()) == 0 ) return 0;

      Graph g(m*n);

      for(int i = 1; i < m; ++i)
        if( grid[i][0] == land && grid[i-1][0] == land) {
          g[i*n].insert((i-1)*n);
          g[(i-1)*n].insert(i*n);
        }

      for(int i = 1; i < n; ++i)
        if( grid[0][i] == land && grid[0][i-1] == land) {
          g[i].insert(i-1);
          g[i-1].insert(i);
        }

      for( int i = 1; i < m; ++i )
        for( int j = 1; j < n; ++j )
          if( grid[i][j] == land ) {
            if( grid[i][j-1] == land ) {
              g[i*n + j].insert(i*n + j -1);
              g[i*n + j -1].insert(i*n + j);
            }
            if( grid[i-1][j] == land ) {
              g[i*n +j].insert((i-1)*n + j);
              g[(i-1)*n +j].insert(i*n + j);
            }
          }

      vector<bool> visited(m*n);
      int sum = 0;
      for( int i = 0; i < m*n ; ++i )
        if( grid[i/n][i%n] == land && !visited[i] ){
          for( auto i : visited ) cout<<i<<' ';
          cout<<endl;
          DFS(visited, g, i);
          ++sum;
        }

      return sum;
    }

    void DFS(vector<bool> &visited, Graph &g, int cur) {
      if( !visited[cur] ) {
        visited[cur] = true;
        for( int i : g[cur] ) DFS(visited, g, i);
      }

    }

    //TODO: BFS
    void BFS(vector<bool> &visited, Graph &g, int cur) {
    }
};

int main() {
  vector<vector<char>> grid = {
    { '1', '1', '1', '1', '0' },
    { '1', '1', '0', '1', '0' },
    { '1', '1', '0', '0', '0' },
    { '0', '0', '1', '1', '0' },
    { '1', '1', '0', '1', '0' }
  };
  vector<vector<char>> grid2={{}};
  vector<vector<char>> grid3={
    { '1', '0', '1', '0', '1' }
  };
  vector<vector<char>> grid4={
    {'1'}, {'1'}, {'1'}, {'0'}, {'1'}
  };


  Solution s;
  cout<<s.numIslands_graph(grid);
  return 0;
}
