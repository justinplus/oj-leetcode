#include <iostream>
#include <sstream>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
using namespace std;

class Solution {
  public:
    bool wordPattern(string pattern, string str) {
      unordered_map<char,string> map;
      unordered_set<string> set;
      stringstream ss(str);

      string s;
      unordered_map<char,string>::iterator it;
      for( char ch : pattern ) {
        if( ss>>s ) {
          it = map.find(ch);
          if( it == map.end() )
            if( set.count(s) ) return false;
            else {
              map[ch] = s;
              set.insert(s);
            }
          else
            if( it->second != s ) return false;

        } else {
          return false;
        }
      }

      return ss.eof();
    }
};

int main() {
  Solution s;
  cout<<s.wordPattern("abba", "dog dog dog dog")<<endl;
  return 0;
}
