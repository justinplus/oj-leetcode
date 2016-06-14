#include <iostream>
#include <string>
#include <sstream>
#include <cctype>
#include <stack>
#include <array>
#include <cassert>
using namespace std;

class Solution {
  using Precedence = array<int,256>;
  public:
    // TODO: improve
    // assume `s` is not empty
    int calculate(string s) {
      stack<char> ops;
      stack<int> vals;
      Precedence prec = precedence();
      string str = s + "#";
      stringstream ss(str);
      ss>>ws;

      char ch;
      int val, val1, val2;
      while( ( ch = ss.peek() ) != EOF ) {
        if( isdigit(ch) ) {
          ss>>val;
          vals.push(val);
        } else {
          cout<<ch<<endl;
          ss.ignore();
          while( !ops.empty() && prec[ops.top()] >= prec[ch] ) {
            val2 = vals.top(); vals.pop();
            val1 = vals.top(); vals.pop();
            vals.push( calculate(ops.top(), val1, val2) );
            ops.pop();
          }
          ops.push(ch);
        }
        ss>>ws;
      }
      return vals.top();
    }

    int calculate(char op, int val1, int val2 ) {
      switch(op) {
        case '+':
          return val1 + val2;
        case '-':
          return val1 - val2;
        case '*':
          return val1 * val2;
        case '/':
          return val1 / val2;
        default:
          assert(false);
      }
    }

    Precedence precedence() {
      Precedence prec;
      prec['#'] = 0;
      prec['+'] = prec['-'] = 1;
      prec['*'] = prec['/'] = 2;
      return prec;
    }

};

int main() {
  Solution s;
  cout<<s.calculate("3+2*2")<<endl;
  cout<<s.calculate(" 3/2 ")<<endl;
  cout<<s.calculate(" 3+ 5 / 2 ")<<endl;
  return 0;
}
