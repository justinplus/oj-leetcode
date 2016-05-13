#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cctype>
using namespace std;

class Solution {
  public:
    // numeric pattern: / *[-+]?\d+(\.\d*)?(e[-+]?\d+)? */
    // very ugly solution
    bool isNumber(string s) {
      size_t pos = s.find_first_not_of(' ');
      if( pos == string::npos ) return false;

      if( s[pos] == '-' || s[pos] == '+' ) ++pos;
      if( pos == s.size() ) return false;

      size_t bg_of_num = pos;
      for(; pos < s.size() && isdigit(s[pos]); ++pos );

      if( pos < s.size() ) {
        if(s[pos] == '.') {
          ++pos;
          for(; pos < s.size() && isdigit(s[pos]); ++pos );
          if( bg_of_num + 1 == pos ) return false;
        }
        if(pos < s.size() && s[pos] == 'e') {
          ++pos;
          if( bg_of_num + 1 == pos ) return false;
          if( pos == s.size() ) return false;
          if( s[pos] == '-' || s[pos] == '+' ) ++pos;
          size_t bg_of_exp = pos;
          if( pos == s.size() ) return false;
          for(; pos < s.size() && isdigit(s[pos]); ++pos );
          if(bg_of_exp == pos) return false;
        }
      }

      if( pos < s.size() ) {
        pos = s.find_first_not_of(' ', pos);
        return pos == string::npos ? true : false;
      }

      return true;

    }

    // TODO: using DFA
};

int main() {
  Solution s;
  cout<<s.isNumber("")<<endl;
  cout<<s.isNumber("    ")<<endl;
  cout<<s.isNumber("+")<<endl;
  cout<<s.isNumber("-")<<endl;
  cout<<s.isNumber("f")<<endl;
  //Note:
  cout<<s.isNumber("e")<<endl;
  cout<<s.isNumber(".")<<endl;
  cout<<s.isNumber("e9")<<endl;
  cout<<s.isNumber("0e ")<<endl;
  cout<<s.isNumber("0e+ ")<<endl;

  cout<<s.isNumber("    123f")<<endl;
  cout<<s.isNumber("123.+123e12")<<endl;
  cout<<s.isNumber("    123e")<<endl;
  cout<<s.isNumber("    123e-")<<endl;
  cout<<"-----------------"<<endl;
  cout<<s.isNumber("123.e12")<<endl;
  cout<<s.isNumber("123.")<<endl;
  cout<<s.isNumber("    123")<<endl;
  cout<<s.isNumber("    123     ")<<endl;
  cout<<s.isNumber("-123123123")<<endl;
  cout<<s.isNumber("+123123123")<<endl;
  cout<<s.isNumber("+12312.3123")<<endl;
  cout<<s.isNumber("+12312e+3123")<<endl;
  cout<<s.isNumber("+12.312e+3123")<<endl;
  return 0;
}
