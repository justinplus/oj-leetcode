#include <iostream>
#include <string>
#include <cctype>
using namespace std;

class Solution {
  public:
    bool isPalindrome(string s) {
      int i = 0, j = (int) s.size() - 1;

      while( i < j ) {
        for(; !isdigit(s[i]) && !isalpha(s[i]); ++i)
          if( i >= j ) break;
        for(; !isdigit(s[j]) && !isalpha(s[j]); --j)
          if( i >= j) break;
        if( tolower(s[i]) != tolower(s[j]) ) return false;
        else {
          ++i; --j;
        }
      }

      return true;
    }
};

int main() {
  string str = "A man, a plan, a canal: Panama";
  string str1 = "   a         a    ";
  Solution s;
  cout<<s.isPalindrome(str)<<endl;
  cout<<s.isPalindrome(str1)<<endl;
  return 0;
}
