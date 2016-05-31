#include <iostream>
#include <vector>
using namespace std;

class Solution {
  public:
    vector<int> countBits(int num) {
      vector<int> res( num + 1 );

      for( size_t i = 1, m = 1; i <= (size_t)num; ++i ) {
        if( i >= m * 2) m *= 2;
        res[i] = 1 + res[i - m];
      }

      return res;
    }

    vector<int> countBits_odd_even(int num) {
      // if the ith number is even, the bit count is the same as i/2;
      // otherwise the bit count is one more than i/2.
      vector<int> res(num+1,0);
      for(int i=1;i<=num;i++){
        if (i%2==1) res[i]= res[i/2]+1;
        else res[i]= res[i/2];
      }
      return res;
    }
};

int main() {
}
