#include <string>
#include <iostream>
#include <stack>
#include <algorithm>
#include <utility>
#include <list>
using namespace std;

class Solution {
  public:
    string removeDuplicateLetters_wrong(string s) {
      using tuple = pair<int, char>;

      const int cnt = 26, nil = -1;
      unsigned int i = 0;
      string res;

      vector<tuple> vec(cnt, tuple(nil,'\0') );

      for(i = 0; i < vec.size(); ++i)
        vec[i].second = 'a' + i;

      for( i = 0; i < s.size(); ++i)
        vec[s[i]-'a'].first = i;

      sort( vec.begin(), vec.end(), [](const tuple& i, const tuple& j){return i.first < j.first;} );

      auto it = find_if(vec.begin(), vec.end(), [](const tuple& i){return i.first != nil;});

      for(; it != vec.end(); ++it ) 
        res.push_back(it->second);

      return res;
    }

    string removeDuplicateLetters_wrong_2(string s) {
      using ch_list = list<char>;
      using ch_list_it =ch_list::iterator;

      const int cnt = 26;
      ch_list l;
      vector<ch_list_it> vec(cnt, l.end());
      stack<char> st;
      string res;
      ch_list_it it, next_it;

      for(unsigned i = 0; i < s.size(); ++i) {

        int index = s[i] - 'a';
        it = vec[index];

        if( it == l.end() ) {
          l.push_back( s[i] );
          vec[index] = --l.end();
          // NOTE: char vs. unsigned char
          if(!st.empty()) st.push(-(s[i]-'a')); // NOTE

        } else {

          next_it = it; ++next_it;

          if( next_it == l.end()) continue; 

          if( *it > *next_it ) {
            int flag[cnt];
            for(auto & n : flag) n = 0;

            l.erase(it);
            l.push_back(s[i]);
            vec[index] = --l.end();
            ch_list_it pos = vec[index];
            flag[index] = 1;

            while( !st.empty() ) {
              char ch = st.top();
              st.pop();

              if(ch <= 0) { 
                pos = vec[-ch];
                continue;
              }

              int index = ch - 'a';
              it = vec[index];
              if( flag[index]==0 && *it > *(++it) ){
                l.erase(vec[index]);
                vec[index] = l.insert(pos, ch);
                flag[index] = 1;
                --pos;
              }
            }
          } else {
            if(st.empty() || s[i] != st.top()) st.push(s[i]);
          }
        }
      }

      for( auto ch : l )
        res.push_back( ch );

      return res;

    }

    string removeDuplicateLetters(string s) {
      vector<int> cand(256, 0);
      vector<bool> visited(256, false);
      for (char c : s)
        cand[c]++;
      // NOTE:
      // string res = "\0"; res.size() => 0 !
      string res = "0";
      for (char c : s) {
        cand[c]--;
        if (visited[c]) continue;
        while (c < res.back() && cand[res.back()]) {
          visited[res.back()] = false;
          res.pop_back();
        }
        res += c;
        visited[c] = true;
      }
      return res.substr(1);
    }
};


int main() {
  Solution s;
  // cout<<s.removeDuplicateLetters("ccacbaba")<<endl;
  // cout<<s.removeDuplicateLetters("bcbac")<<endl;
  // cout<<s.removeDuplicateLetters("orzornz")<<endl;
  cout<<s.removeDuplicateLetters_wrong_2("rusrbofeggbbkyuyjsrzornpdguwzizqszpbicdquakqws")<<endl;

  /* list<int> l = {1,2,3};  */
  // vector<list<int>::iterator *> vec(7);

  // // All the elements of vec if the same.
  // for(int i = 0; i < 7; i++) {
  // auto tmp = l.end();
  // vec[i] = &tmp;
  // cout<<vec[i]<<endl;
  // } 

  return 0;
}
