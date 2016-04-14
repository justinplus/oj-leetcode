#include <iostream>
#include <vector>
using namespace std;

class Solution {
  public:
    bool isPalindrome(int x) {
      if( x < 0 ) return false;

      int orig = x;
      int sum = 0;
      while( x != 0 ) {
        sum = sum*10 + x % 10;
        x /= 10;
      }

      return sum == orig;
    }
};

int main() {
  Solution s;
  cout<<s.isPalindrome(10122101);
  return 0;
}
