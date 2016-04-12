#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
  public:
    int lengthOfLongestSubstring(string s) {
      vector<int> hsh(128, -1);
      int begin = 0, end = 0, len = 0;
      bool valid = true;

      for(; end < (int)s.size(); ++end ) {
        if( ++hsh[s[end]] > 0) valid = false;
        while( !valid ) if( --hsh[s[begin++]] == 0 ) valid = true;
        len = max(len, end-begin+1);

      }

      return len;
    }


    // tempalte for substring problem
    int findSubstring(string s){
      vector<int> map(128,0);
      int counter; // check whether the substring is valid
      int begin=0, end=0; //two pointers, one point to tail and one  head
      int d; //the length of substring

      for() { /* initialize the hash map here */ }

      while(end<s.size()){

        if(map[s[end++]]-- ?){  /* modify counter here */ }

        while(/* counter condition */){

          /* update d here if finding minimum*/

          //increase begin to make it invalid/valid again

          if(map[s[begin++]]++ ?){ /*modify counter here*/ }
        }

        /* update d here if finding maximum*/
      }
      return d;
    }
};

int main() {
  string str = "abcabccdbb";
  Solution s;
  cout<<s.lengthOfLongestSubstring(str);


  return 0;
}
