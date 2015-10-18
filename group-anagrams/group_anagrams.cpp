#include <iostream>
#include <vector>
#include <algorithm>
#include <array>
#include <list>
#include <utility>
using namespace std;

class Solution {
  public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
      sort(strs.begin(), strs.end());

      list<pair<array<int, 26>, string *>> maps;
      list<pair<array<int, 26>, string *>>::iterator it;
      
      vector<vector<string>> ans;

      for( string & str : strs ){
        maps.push_back({{}, &str});
        for( char ch : str ) maps.back().first[ch - 'a'] ++;
      }

      while(true) {
        it = maps.begin();
        if( it == maps.end() ) break;
        array<int, 26> criteria = it->first;
        ans.push_back( {*it->second} );
        maps.pop_front();

        for(it = maps.begin(); it != maps.end(); ) {
          int eql = true;
          for(int i = 0; i < 26; i++){
            if( criteria[i] != it->first[i] ){
              eql = false;
              break;
            }
          }
          if( eql ) {
            ans.back().push_back(*it->second);
            it = maps.erase(it);
          } else {
            it++;
          }
        }
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
