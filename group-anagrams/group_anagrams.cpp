#include <iostream>
#include <vector>
#include <algorithm>
#include <array>
#include <utility>
#include <unordered_map>
#include <cstring>
#include <string>
using namespace std;

class Solution {
  public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
      sort(strs.begin(), strs.end()); // change the strs, bad behavior

      unordered_map<string, vector<string *>> maps;

      vector<vector<string>> ans;

      int i = 0;
      for( string  str : strs ){
        sort(str.begin(), str.end());
        maps[str].push_back(&strs[i++]);
      }

      for( auto & map : maps ){
        ans.push_back({});
        for( auto str : map.second )
          ans.back().push_back(*str);
      }

      return ans;
    }

    // Do not store vector in hash, but the index of corresponding vector of ans
    vector<vector<string>> groupAnagrams2(vector<string>& strs) {
      vector<vector<string>> ans;
      unordered_map<string, int> hash;
      string ori;
      for(unsigned i=0; i<strs.size(); i++){
        ori = strs[i];
        sort(ori.begin(), ori.end());
        if(hash.count(ori)>0) {
          ans[hash[ori]].push_back(strs[i]);
        }
        else {
          hash[ori]=ans.size();
          ans.push_back(vector<string>(1, strs[i]));
        }
      }
      for(unsigned i=0; i<ans.size(); i++){
        sort(ans[i].begin(), ans[i].end()); //can use other method
      }
      return ans;
    }
};

// The reasion of low performance
// 1. the generation of key
// 2. unordered_map#[] is quicker than unordered_map::iterator ??
// 3. copy the memory block or dereference, which is quicker ??

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
  inspect( s.groupAnagrams2(strs) );

  return 0;
}
