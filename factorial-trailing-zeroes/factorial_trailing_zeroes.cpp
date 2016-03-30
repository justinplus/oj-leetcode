#include <iostream>
#include <vector>
#include <climits>
#include <cmath>
#include <iterator>
#include <algorithm>
using namespace std;

class Solution {
  public:
    int trailingZeroes(int n) {

      int exp = 5, res = 0;
      // NOTE: int(...)
      for(int i = 0; exp <= n && i < int(log(INT_MAX) / log(5)); ++i) {
        res += n / exp;
        exp *= 5;
      }

      return res;
    }
};

int main() {
  cout<<INT_MAX<<endl;
  cout<<log(5)/log(5)<<endl; 

  Solution s;
  cout<<s.trailingZeroes(2000000000);
}
