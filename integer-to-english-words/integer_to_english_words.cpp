#include <iostream>
#include <string>
#include <vector>
using namespace std;

const char *CH_0_19[20] = {
  "",
  "One",
  "Two",
  "Three",
  "Four",
  "Five",
  "Six",
  "Seven",
  "Eight",
  "Nine",
  "Ten",
  "Eleven",
  "Twelve",
  "Thirteen",
  "Fourteen",
  "Fifteen",
  "Sixteen",
  "Seventeen",
  "Eighteen",
  "Nineteen"
};

const char *CH_10_90[10] = {
  "",
  "Ten",
  "Twenty",
  "Thirty",
  "Forty",
  "Fifty",
  "Sixty",
  "Seventy",
  "Eighty",
  "Ninety"
};

const char *QUANTITY[4] = {
  "", "Thousand", "Million", "Billion"
};

const char * HRD = "Hundred";

// TODO: make code more concise
class Solution {
  public:
    string numberToWords(int num) {
      if(num == 0) return "Zero";

      vector<string> ress;
      while( num != 0 ) {
        ress.push_back( numberToWords_1000(num % 1000) );
        num /= 1000;
      }

      string res;
      for( size_t i = ress.size() - 1; i > 0; --i )
        if( !ress[i].empty() )
          res += ress[i] + QUANTITY[i] + ' ';

      res += ress.front();

      return res.substr(0, res.size() - 1);
    }

    string numberToWords_1000(int num) {
      string res;
      int n = num / 100;
      if( n != 0 )
        res = res + CH_0_19[n] + ' ' + HRD + ' ';

      n = num % 100;
      if( n <= 19 ) {
        if(n != 0) res = res + CH_0_19[n] + ' ';
      } else {
        res = res + CH_10_90[n/10] + ' ';
        if( n % 10 )
          res = res + CH_0_19[n%10] + ' ';
      }

      return res;
    }
};

int main() {
  Solution s;
  cout<<s.numberToWords(80000000)<<endl;
  return 0;
}
