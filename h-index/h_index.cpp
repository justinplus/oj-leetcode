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
  // TODO: 0(n) using hash
};

int main() {
  vector<int> citations {3,0,6,1,5,12,3,3,1,2,3,2,3,4,2,3,4,2,3,3};
  Solution s;
  cout<<s.hIndex(citations);

  return 0;
}
