#include <iostream>
#include <utility>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
  using Matrix = vector<vector<int>>;
  using graph = vector<unordered_set<int>>;
  public:
    // memory limit exceeded
    bool canFinish_mle(int numCourses, vector<pair<int, int>>& prerequisites) {
      Matrix m { numCourses, vector<int>(numCourses, 0) };
      vector<int> indegrees(numCourses, 0);
      for( auto & p : prerequisites ) {
        m[p.second][p.first] = 1;
        indegrees[p.first]++;
      }

      for( int i = 0; i < numCourses; ++i ) {
        int j = 0;
        for( ; j < numCourses; ++j )
          if( indegrees[j] == 0 ) break;
        if( j == numCourses ) return false;
        --indegrees[j];
        for( int n = 0; n < numCourses; ++n ) 
          if( m[j][n] != 0 )
            --indegrees[n];
      }
      return true;
    }

    // TODO: improve performance
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
      graph g { numCourses, unordered_set<int>{} };
      vector<int> indegrees(numCourses, 0);
      for( auto & p : prerequisites ) {
        if(g[p.second].count(p.first) == 0) { // Note!!
          g[p.second].insert(p.first);
          indegrees[p.first]++;
        }
      }

      for( int i = 0; i < numCourses; ++i ) {
        int j = 0;
        for( ; j < numCourses; ++j )
          if( indegrees[j] == 0 ) break;
        if( j == numCourses ) return false;
        --indegrees[j];
        for( auto n : g[j] ) 
          --indegrees[n];
      }
      return true;
    }

};

int main() {
  vector<pair<int,int>> edges {{2,0}, {2,1}, {3,2}, {4,3}, {5,3}};
  // wrong answer!! duplicate edges [1,9]
  vector<pair<int,int>> edges_2 {{5,8},{3,5},{1,9},{4,5},{0,2},{1,9},{7,8},{4,9}};
  Solution s;
  cout<<s.canFinish(10, edges_2)<<endl;
  return 0;
}
