#include <iostream>
#include <string>
using namespace std;

class Solution {
  public:
    // TODO: check the performance
    string convert(string s, int numRows) {
      int size = s.size();
      if(numRows < 2 || numRows >= size) return s;
      string res;
      for( int i = 0; i < size; i += 2*numRows - 2 ) res += s[i];

      for( int i = 1; i < numRows-1; ++i) {
        int d = 0, offset = 0;
        while( true ) {
          if( d % 2 == 0 ) {
            if( offset + i < size )
              res += s[offset + i];
            else
              break;
            offset += numRows;
          } else {
            if( offset + numRows - 2 - i < size )
              res += s[offset + numRows - 2 - i];
            else
              break;

            offset += numRows - 2;
          }
          d++;
        }
      }

      for( int i = numRows-1; i < size; i += 2*numRows - 2 ) res += s[i];
      return res;
    }
};

int main() {
  Solution s;
  cout<<s.convert("PAYPALISHIRING", 3)<<endl;
  cout<<s.convert("", 3)<<endl;
  return 0;
}
