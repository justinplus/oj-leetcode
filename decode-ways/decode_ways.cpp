#include <string>
#include <iostream>
using namespace std;

class Solution {
  public:
    int numDecodings(string s) {
      int pre = 1, cur = 1, tmp;

      if( s.size() == 0 || s.front() == '0' ) return 0;

      for( unsigned i = 1; i < s.size(); i++ ) {
        tmp = hasDecoding(s[i] - '0') * cur + 
          (s[i-1] - '0' == 0 ? 0 : hasDecoding( (s[i-1] - '0') * 10 + s[i] - '0')) * pre;
        // Attn: 01 and 1 is not discriminable 
        pre = cur;
        cur = tmp;
      } 

      return cur;
    }

    int hasDecoding(int n) {
      if( n >= 1 && n <= 26 ) return 1;
      else return 0;
    }
};

int main() {
  Solution s;
  cout<<s.numDecodings("101"); 
  return 0;
}
