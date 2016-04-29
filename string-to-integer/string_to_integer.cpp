#include <iostream>
#include <string>
#include <climits>
#include <cctype>
using namespace std;

class Solution {
  public:
    int myAtoi(string str) {
      // Attn: g++ now do not offer a full support for regex
      // either can regex be used on leetcode

      // What should be considered
      // 1. the sign
      // 2. the range of int
      // 3. the heading `0` and whitespace
      // 4. the tailing nonnumeric char [Attn]
      //
      // / *[-+]?0*[1-9]*\d*/

      // Skip heading whitespace
      size_t pos = str.find_first_not_of(' ');
      // NOTE: the return of string.find
      if( pos == string::npos) return 0;
      int sign = 1;

      // Get the sign
      switch( str[pos] ) {
        case '-':
          sign = -1;
        case '+':
          pos++;
          break;
      }

      // Skip heading 0
      pos = str.find_first_not_of('0', pos);

      // TODO: avoid using long long

      long long res = 0;

      for( size_t i = pos; i < str.size() && isdigit(str[i]); i++) {
        res = res * 10 + sign * (str[i]-'0');
        if( res >= INT_MAX ) return INT_MAX;
        else if( res <= INT_MIN) return INT_MIN;
      }

      return res;
    }
};

int main(){
  Solution s;
  cout<<s.myAtoi("123")<<endl;
  cout<<s.myAtoi("+123")<<endl;
  cout<<s.myAtoi("-123")<<endl;

  cout<<s.myAtoi("000123")<<endl;
  cout<<s.myAtoi("+000123")<<endl;
  cout<<s.myAtoi("-000123")<<endl;

  cout<<s.myAtoi("2147483648")<<endl;
  cout<<s.myAtoi("-2147483649")<<endl;

  cout<<s.myAtoi("++123")<<endl;
  cout<<s.myAtoi("a123")<<endl;
  cout<<s.myAtoi("1a23")<<endl;

  cout<<s.myAtoi("0")<<endl;
  cout<<s.myAtoi("+0")<<endl;
  cout<<s.myAtoi("-0")<<endl;

  cout<<"--"<<endl;
  cout<<s.myAtoi("010")<<endl;
  cout<<s.myAtoi("   010")<<endl;
  cout<<s.myAtoi("  010asd")<<endl;
  cout<<s.myAtoi("  -010asdf")<<endl;
  cout<<s.myAtoi("  -010   ")<<endl;
  cout<<s.myAtoi("  +010   ")<<endl;
  cout<<s.myAtoi("    10522545459")<<endl; // Attn!!!

  return 0;
}
