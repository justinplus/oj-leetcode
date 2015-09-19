#include <iostream>
using namespace std;

class Solution {
  public:
    int hammingWeight(uint32_t n) {
      int weight = 0;
      for( unsigned i = 0; i < 8*sizeof(n); i++ ) {
        weight += n%2;
        n >>= 1;
      }
      return weight;
    }
};

int main() {
  Solution s;
  cout<< s.hammingWeight(1024) <<endl;
}
