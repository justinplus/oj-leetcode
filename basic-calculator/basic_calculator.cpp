#include <iostream>
#include <vector>
#include <stack>
#include <sstream>
#include <cctype>
#include <cassert>
#include <algorithm>
using namespace std;

class Solution {
  public:
    // TODO: improve & refactor
    // assume the string is valid
    int calculate(string s) {
      stack<char> ops;
      stack<int> vals;
      stringstream ss(s);
      cout<<s<<endl;
      ss>>ws;

      char c, op;
      int val;
      while( ( c = ss.peek() ) != EOF ) {
        if( isdigit(c) ) {
          ss>>val;
          if( !ops.empty() && (op = ops.top()) != '(' ) {
            ops.pop();
            val = calculate(op, vals.top(), val);
            vals.pop();
          }
          vals.push(val);
        } else {
          ss>>c;
          switch(c) {
            case '(':
            case '+':
            case '-':
              ops.push(c);
              break;
            case ')':
              assert(ops.top() == '(');
              ops.pop();

              if( !ops.empty() && (op = ops.top()) != ')' && op != '(' )  {
                ops.pop();
                int val1, val2;
                val2 = vals.top(); vals.pop();
                val1 = vals.top(); vals.pop();
                vals.push( calculate(op, val1, val2) );
              }
              break;
            default:
              assert(false);
          }
        }
        // TIP
        ss>>ws;
      }

      return vals.top();
    }

    int calculate( char op, int v1, int v2 ) {
      switch(op) {
        case '+':
          return v1+v2;
        case '-':
          return v1-v2;
        default:
          assert(false);
      }
    }
};

int main() {
  Solution s;
  // cout<<s.calculate("1 + 1")<<endl;
  // cout<<s.calculate(" 2-1 + 2")<<endl;
  cout<<s.calculate("(1+(4+5+2)-3)+(6+8)")<<endl;
  cout<<s.calculate(" 1 + (4 + 5 ) +  ( 2+1) -3 ")<<endl;
  return 0;
}
