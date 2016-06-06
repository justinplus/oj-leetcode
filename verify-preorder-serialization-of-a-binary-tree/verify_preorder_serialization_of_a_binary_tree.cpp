#include <iostream>
#include <sstream>
#include <stack>
#include <vector>
#include <cstdio>
using namespace std;

class Solution {
  public:
    static const char null_node = '#';
    bool isValidSerialization(string preorder) {
      if(preorder.size() == 0 ) return false;

      vector<int> stk;
      stringstream ss(preorder);

      int node;
      while( (node = next(ss)) != -1 ) {
        // for( int i : stk) cout<<i<<' ';
        // cout<<endl;
        if( node == 1 ) {
          stk.push_back(0);
        } else {
          while( !stk.empty() && ++stk.back() == 2 )
            stk.pop_back();
        }
        if(stk.empty()) break;
      }

      return stk.empty() && next(ss) == -1;
    }

    // `1` for non-null, `0` for null, `-1` for EOF
    int next(stringstream &ss) {
      if( ss.peek() == char_traits<char>::eof() ) {
        return -1;
      } else if( ss.peek() == null_node ) {
        ss.ignore(2);
        return 0;
      } else {
        int num;
        ss>>num;
        ss.ignore();
        return 1;
      }
    }
};

int main() {
  string str1 = "9,3,4,#,#,1,#,#,2,#,6,#,#";
  string str2 = "9,#,#";
  string str3 = "#,";
  string str4 = "#,#";
  Solution s;

  cout<<s.isValidSerialization(str3);

  return 0;
}
