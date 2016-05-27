#include <iostream>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <sstream>
using namespace std;

class Solution {
  public:
    string fractionToDecimal(int numerator, int denominator) {

      stringstream ss;
      unordered_map<int,size_t> map;
      string dec_part, res;

      // determine the sign
      if( numerator != 0 && (numerator ^ denominator) < 0 ) ss<<'-';

      long long denom = abs( (long long) denominator );
      long long rem = abs(numerator % denom);

      // NOTE: integer overflow
      ss << abs((long long)numerator/denom);
      ss >> res;

      pair<unordered_map<int,size_t>::iterator, bool> p;

      for(size_t i = 0; rem != 0 && (p = map.insert({rem, i})).second; ++i ) {
        rem *= 10;
        dec_part += '0' + rem / denom;
        rem %= denom;
      }

      if( dec_part != "" ) {
        res += '.';
        if( rem == 0 ) res += dec_part;
        else {
          res += dec_part.substr(0, p.first->second);
          res += '(';
          res += dec_part.substr(p.first->second);
          res += ')';
        }
      }

      return res;
    }
};

int main() {
  Solution s;
  cout<<s.fractionToDecimal(1, 122)<<endl;
  cout<<s.fractionToDecimal(1, 14)<<endl;

  // RE: Integer overflow
  cout<<s.fractionToDecimal(-2147483648, -1);
  return 0;
}
