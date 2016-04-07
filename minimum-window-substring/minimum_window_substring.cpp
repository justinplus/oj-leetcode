#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
#include <climits>
using namespace std;

class Solution {
  public:
    using Hash = unordered_map<char, int>;
    string minWindow(string s, string t) {
      int m = s.size();
      // NOTE: no need to maintain a vec when a minimum is only required
      vector<int> vec(m);

      unordered_map<char, int> counter;
      Hash::iterator it;

      for(char ch : t) {
        it = counter.find(ch);
        if( it == counter.end() )
          counter.insert({ch, -1});
        else
          --it->second;
      }

      int i = 0, j = 0;
      char target = -1;
      for(; j < m; ++j) {
        it = counter.find(s[j]);
        if( it == counter.end() ) continue;
        ++it->second;

        if( target == s[j] ||
            (target == -1 &&
              all_of(counter.begin(), counter.end(), [](const pair<char,int> p) {return p.second >= 0;})) ) {
          // cout<<"i: "<<i<<" j: "<<j<<endl;

          for(; i <= j; ++i){  // < ? <=
            it = counter.find(s[i]);
            if(it == counter.end()) continue;
            if( it->second >= 0 ){
              // cout<<"left: "<<it->second<<endl;
              --it->second;
              vec[i] = j - i + 1;
              // cout<<"len: "<<vec[i]<<endl;
              if(it->second == -1) {
                target = s[i];
                ++i;
                break;
              }
            }
          }
        }
      }

      // for(int n : vec) cout<<n<<' ';
      // cout<<endl;
      // for(auto ch : s) cout<<ch<<' ';
      // cout<<endl;
      // for(auto& p : counter) cout<<p.first<<"->"<<p.second<<' ';
      // cout<<endl;

      int k = 0, min = -1;
      for(; k < m; ++k)
        if(vec[k] > 0) { min = k; break; }
      for(; k < m; ++k)
        if(vec[k] > 0 && vec[k] < vec[min])
          min = k;

      if( min == -1 ) return "";
      else
        return s.substr(min, vec[min]);
    }

    // learn from others
    // TODO: review
    string minWindow_learn(string s, string t) {
      vector<int> hsh(128, 0);
      int counter = t.size();
      int begin = 0, end = 0;
      int head = 0, len = INT_MAX;
      for(char ch : t) ++hsh[ch];

      while( end < (int) s.size() ) {
        if(--hsh[s[end]] >= 0) --counter;
        ++end;
        while( counter == 0 ){
          if(len > end-begin) {
            len = end-begin;
            head = begin;
          }
          if(++hsh[s[begin++]] > 0)
            ++counter;
        }
      }

      return len == INT_MAX ? "" : s.substr(head, len);
    }

};

int main() {
  string str = "ADOBECODEBANC";
  string str2 = "A.AEAB.C..ABC..A.BD";
  string str3 = "...AAAAAB";

  Solution s;
  // WA
  cout<<s.minWindow(str3, "AAAAB")<<endl;
  cout<<s.minWindow_learn(str3, "AAAAB");
  return 0;
}

