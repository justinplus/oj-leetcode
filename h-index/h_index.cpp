#include <vector>
#include <iostream>
#include <algorithm>
#include <functional>
using namespace std;

class Solution {
  public:
    int hIndex(vector<int>& citations) {
      sort(citations.begin(), citations.end(), std::greater<int>());

      int i = 0;
      while( i < (int)citations.size() && citations[i] >= i+1 ) ++i;

      return i;

    }

    // 0(n) using hash
    // TODO: review
    int hIndex_hash(vector<int>& citations) {
      vector<int> counter (citations.size() + 1);
      for( int c : citations )
        if( c >= (int)citations.size() ) ++counter.back();
        else ++counter[c];

      for(int c : counter) cout<<c<<' ';
      cout<<endl;

      int sum = 0, i = citations.size();
      for( ; i > 0 && i >= sum; --i ) {
        sum += counter[i];
        if( sum > i )
          return i;
      }

      return sum;
    }
};

int main() {
  vector<int> citations {3,0,5,12,23,2,2,2,3,2,12,3,2,2,2,23,2,2};
  Solution s;
  cout<<s.hIndex(citations)<<endl;
  cout<<s.hIndex_hash(citations)<<endl;

  return 0;
}
