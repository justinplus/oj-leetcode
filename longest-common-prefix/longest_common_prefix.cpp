#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
  public:
    string longestCommonPrefix(vector<string>& strs) {
      if( strs.empty() ) return {};
      size_t pos = 0;

      // NOTE: diff of `any_of` and `all_of`
      while( !any_of( strs.begin(), strs.end(),
          [pos, &strs](const string & str){return str.size() <= pos || str[pos] != strs.front()[pos];} ))
      {
        ++pos;
      }



      return pos == 0 ? string() : strs.front().substr(0, pos) ;
    }
};

int main() {
  vector<string> strs {"asa", "as", "asee"};
  vector<string> emp_strs;
  Solution s;
  cout<<s.longestCommonPrefix(strs);
  return 0;
}
