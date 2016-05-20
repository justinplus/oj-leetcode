#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
  public:
    // citations is sorted in ascending order
    int hIndex(vector<int>& citations) {
      int i = citations.size() - 1;

      while( i >= 0 && citations[i] >= (int)citations.size() - i ) --i;

      return citations.size() - 1 - i;
    }

    int hIndex_bin(vector<int>& citations) {
      int lo = 0, hi = citations.size(), mid = 0;
      while( lo < hi ) {
        mid = ( lo + hi ) / 2;
        if( citations[mid] >= (int)citations.size() - mid ) hi = mid;
        else lo = mid + 1;
      }

      // NOTE: here
      return citations.size() - hi;
    }
};

int main() {
  vector<int> citations {1,1,1,1,1,1,2,2,2,2,2,2,3,4,5,6,6,7};
  Solution s;
  cout<<s.hIndex(citations)<<endl;
  cout<<s.hIndex_bin(citations)<<endl;
  return 0;
}
