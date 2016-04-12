#include <iostream>
#include <vector>
using namespace std;
/**
 * Definition for an interval.
 */
struct Interval {
  int start;
  int end;
  Interval() : start(0), end(0) {}
  Interval(int s, int e) : start(s), end(e) {}
};

class Solution {
  public:
    // TODO: review
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {

      int index[2] {};
      int i = 0;

      int m = intervals.size();

      for( auto target : { newInterval.start, newInterval.end} ) {
        int begin = 0, end = m, mid;
        while( begin < end ) {
          mid = (begin + end) / 2;
          if( intervals[mid].end >= target) end = mid;
          else begin = mid + 1;
        }
        index[i++] = begin;
      }

      if( index[1] < m)
        if( intervals[index[1]].start > newInterval.end ) --index[1];
        else newInterval.end = intervals[index[1]].end;

      if( index[0] < m && newInterval.start > intervals[index[0]].start )
        newInterval.start = intervals[index[0]].start;

      if( index[0] < m ) intervals.erase( intervals.begin() + index[0],
          index[1] >= m ? intervals.end() : intervals.begin() + index[1] + 1 );

      intervals.insert(intervals.begin() + index[0], newInterval);

      return intervals;

    }
};

ins

int main() {
  vector<Interval> case1 ={{1,3},{6,9}};

  return 0;
}
