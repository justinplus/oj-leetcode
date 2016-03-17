#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

class Solution {
public:
    void reverseWords(string &s) {
      s.erase(0, s.find_first_not_of(' '));
      s.erase(s.find_last_not_of(' ')+1);

      reverse(s.begin(), s.end());

      int index = 0, cnt = 0;
      for(unsigned i = 0; i < s.size(); ++i) {
        if( s[i] != ' ' ) {
          s[index++] = s[i];
          cnt = 0;
        } else {
          if( cnt == 0) s[index++] = s[i];
          ++cnt;
        }
      }
      
      // NOTE: wrong!!!
      // s.resize(index+1);
      s.resize(index);

      // s = regex_replace(s, regex(" +"), " ");
      auto it_1 = s.begin(), it_2 = it_1;
      while(true ) {
        while( *it_2 != ' ' && it_2 != s.end() ) ++it_2;
        reverse(it_1, it_2);
        if(it_2 == s.end()) return;
        ++it_2;
        it_1 = it_2;
      }
    }
};

int main() {
  Solution s;
  string str = "   the  sky   is    blue    ";
  string str_2 = "   ";
  s.reverseWords(str_2);
  cout<<str_2<<endl;
  cout<<bool(str_2 == "")<<endl;
  return 0;
}
