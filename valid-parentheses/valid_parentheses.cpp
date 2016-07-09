#include <iostream>
#include <stack>
#include <string>
using namespace std;

class Solution {
  public:
    bool isValid(string s) {
      char map[256];
      map[')'] = '(';
      map[']'] = '[';
      map['}'] = '{';

      stack<char> stk;

      for( char ch : s ) {
        if( (ch == ')' || ch == ']' || ch == '}' ) && !stk.empty() && stk.top() == map[(size_t)ch] )
          stk.pop();
        else
          stk.push(ch);
      }

      return stk.empty();
    }
};

int main() {
  return 0;
}
