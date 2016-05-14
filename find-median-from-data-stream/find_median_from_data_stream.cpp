#include <iostream>
#include <queue>
#include <functional>
#include <cassert>
#include <climits>
using namespace std;

class MedianFinder {
  public:
    priority_queue<int> max_heap;
    priority_queue<int, vector<int>, std::greater<int>> min_heap;

    MedianFinder() {
      max_heap.push(INT_MIN);
      min_heap.push(INT_MAX);
    }

    // Adds a number into the data structure.
    void addNum(int num) {
      if( num > min_heap.top() ) {
        min_heap.push(num);
        if( min_heap.size() == max_heap.size() + 2 ) {
          max_heap.push(min_heap.top());
          min_heap.pop();
        }
      }
      else if( num < max_heap.top() ) {
        max_heap.push(num);
        if( max_heap.size() == min_heap.size() + 2 ) {
          min_heap.push(max_heap.top());
          max_heap.pop();
        }
      }
      else {
        if( max_heap.size() > min_heap.size() )
          min_heap.push(num);
        else
          max_heap.push(num);
      }
      // cout<<"min_heap top: " << min_heap.top()<<endl;
      // cout<<"max_heap top: " << max_heap.top()<<endl;
    }

    // Returns the median of current data stream
    double findMedian() {
      if( max_heap.size() == min_heap.size() )
        return double(max_heap.top() + min_heap.top()) / 2;
      else if( max_heap.size() == min_heap.size() + 1 )
        return max_heap.top();
      else if( max_heap.size() + 1 == min_heap.size() )
        return min_heap.top();
      else
        assert(false);
    }
};

int main() {
  MedianFinder mf;
  mf.addNum(-1);
  cout<<mf.findMedian()<<endl;
  mf.addNum(0);
  cout<<mf.findMedian()<<endl;
  mf.addNum(1012);
  cout<<mf.findMedian()<<endl;
  mf.addNum(3);
  cout<<mf.findMedian()<<endl;
  mf.addNum(4);
  cout<<mf.findMedian()<<endl;
  mf.addNum(1012);
  cout<<mf.findMedian()<<endl;
  mf.addNum(1012);
  cout<<mf.findMedian()<<endl;
  mf.addNum(1012);
  cout<<mf.findMedian()<<endl;
  mf.addNum(1012);
  cout<<mf.findMedian()<<endl;

  return 0;
}

// Your MedianFinder object will be instantiated and called as such:
// MedianFinder mf;
// mf.addNum(1);
// mf.findMedian();
