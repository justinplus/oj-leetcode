#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
  public:
    // TODO: understand
    string convertToTitle(int n) {
      string t;

      while( n > 0 ) {
        --n;
        t += 'A' + n % 26;
        n = n/26;
      }

      reverse(t.begin(), t.end());

      return t;
    }
};

int main() {
  return 0;
}
