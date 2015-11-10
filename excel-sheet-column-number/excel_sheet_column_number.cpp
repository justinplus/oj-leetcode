#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
  public:
    int titleToNumberClosure(string s) { // 12ms, 1000case
      int num = 0, multiple = 1;
      for_each( s.crbegin(), s.crend(), [&num, &multiple](const char ch){ num += (ch-'A'+1) * multiple; multiple *= 26; });
      return num;
    }

    int titleToNumberIterator(string s) { // 8ms
      int num = 0, multiple = 1;
      for( auto it = s.crbegin(); it != s.crend(); ++it ) {
        num += (*it-'A'+1) * multiple;
        multiple *= 26;
      }
      return num;
    }

    int titleToNumber(string s) { // 8ms
      int num = 0, multiple = 1;
      for( int i = s.size() - 1; i >=0; --i ) {
        num += (s[i]-'A'+1) * multiple;
        multiple *= 26;
      }
      return num;
    }

    
};

int main() {
  Solution s;
  cout<<s.titleToNumber("AAAA");

  return 0;
}
