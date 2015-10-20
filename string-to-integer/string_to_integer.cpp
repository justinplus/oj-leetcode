#include <iostream>
#include <string>
#include <climits>
using namespace std;

class Solution {
  public:
    int myAtoi(string str) { // TODO: make code concise
      // Attn: g++ now do not offer a full support for regex
      // either can regex be used on leetcode

      // What should be considered
      // 1. the sign
      // 2. the range of int 
      // 3. the heading 0 or whitespace
      // 4. the tailing nonnumeric char [Attn]
      //
      // / *(\+|-)?0*(\d*)[^0-9]*/

      int begin = 0;
      int sign = 1;

      // Skip heading whitespace
      while( str[begin] == ' ' ) begin++;

      // Get the sign
      switch( str[begin] ) {
        case '-':
          sign = -1;
        case '+':
          begin++;
          break;
      }

      // Skip heading 0
      while( str[begin] == '0' ) begin++;

      // Get the end of numeric seq
      int end = begin; 
      for(; end < (int)str.size() && str[end] >='0' && str[end] <= '9'; end++);


      long long res = 0;
      long long card = 1;

      for( int i = end-1; i >= begin; i--) {
        res += sign * card * (str[i]-'0');
        card *= 10;
        if( res >= INT_MAX ) return INT_MAX; // TODO: Any better idea?
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
