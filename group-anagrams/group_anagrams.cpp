#include <iostream>
#include <vector>
#include <algorithm>
#include <array>
#include <utility>
#include <unordered_map>
#include <sstream>
#include <cstring>
#include <string>
using namespace std;

class Solution { // TODO: low performance, improve it
  public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
      sort(strs.begin(), strs.end());

      unordered_map<string, vector<string *>> maps;
      unordered_map<string, vector<string *>>::iterator it;

      array<int, 26> letters;
      stringstream ss;

      vector<vector<string>> ans;

      for( string & str : strs ){
        memset( letters.data(), 0, sizeof(int) * 26);
        ss.str("");
        for( char ch : str ) letters[ch - 'a'] ++;
        for( int n : letters ) {
          ss << n;
          ss << ';';
        }
        it = maps.find(ss.str());
        if( it == maps.end() ){
          maps.insert({ss.str(), {&str}});
        } else {
          it->second.push_back(&str);
        }
      }

      for( auto & map : maps ){
        ans.push_back({});
        for( auto str : map.second )
          ans.back().push_back(*str);
      }

      return ans;
    }
};

void inspect( const vector<vector<string>> &strs) {
  for(auto &v : strs) {
    for(auto &str : v )
      cout<<str<<' ';
    cout<<endl;
  }
}

int main() {
  vector<string> strs = {"eat", "tea", "tan", "ate", "nat", "bat"};

  Solution s;
  inspect( s.groupAnagrams(strs) );

  return 0;
}
