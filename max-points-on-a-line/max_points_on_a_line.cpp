#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

/**
 * Definition for a point.
 */
struct Point {
  int x;
  int y;
  Point() : x(0), y(0) {}
  Point(int a, int b) : x(a), y(b) {}
};

class Solution {
  public:
    int maxPoints(vector<Point>& points) {
      unordered_map<double,int> counter;
      int infinite = 0;
      int dup = 0;
      int res = 0;

      for( size_t i = 0; i < points.size(); ++i ) {
        for( size_t j = i+1; j < points.size(); ++j ) {
          if(points[j].x - points[i].x == 0)
            if( points[j].y - points[i].y == 0 )
              ++dup;
            else
              ++infinite;
          else
            ++counter[ double(points[j].y - points[i].y) / (points[j].x - points[i].x) ];
        }
        auto it = max_element(counter.begin(), counter.end(),
                  [](const pair<double,int> &a, const pair<double,int> &b){ return a.second < b.second; });
        res = max( res, dup + 1 +  max(infinite,  it == counter.end() ? 0 : it->second  ));
        counter.clear();
        dup = 0;
        infinite = 0;
      }

      return res;
    }
};

int main() {
  vector<Point> points { {4,4},{4,4}};
  Solution s;
  cout<<s.maxPoints(points);
  return 0;
}
