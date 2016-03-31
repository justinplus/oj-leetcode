#include <iostream>
#include <string>
#include <vector>
#include <cassert>
#include <cctype>
using namespace std;

class Solution {

  public:
  static int str2int(const string &input, int l, int r) {
    int res = 0;
    for( int i = l; i <= r; ++i) {
      res *= 10;
      res += input[i] - '0';
    }
    return res;
  }

  static int compute(const int a, const int b, const char op) {
    int res;
    switch(op){
      case '+':
        res = a + b;
        break;
      case '-':
        res = a - b;
        break;
      case '*':
        res = a * b;
        break;
      default:
        assert(false);
    }
    return res;
  }

  // TODO: improve
  vector<int> diffWaysToCompute(string input) {
    return diffWaysToCompute(input, 0, input.size()-1 );
  }

  vector<int> diffWaysToCompute(const string &input, int l, int r) {
    vector<int> res;
    for(int i = l; i <= r; ++i) {
      if( !isdigit(input[i]) ) {
        for( auto a : diffWaysToCompute( input, l, i-1) )
          for(auto b : diffWaysToCompute( input, i+1, r) )
            res.push_back(compute(a, b, input[i]));
      }
    }
    if(res.empty()) res.push_back(str2int(input, l, r));
    return res;
  }
};

int main() {
  Solution s;
  auto res = s.diffWaysToCompute("2/3-4*5");
  for(auto n : res ) cout<<n<<' ';
  return 0;
}

