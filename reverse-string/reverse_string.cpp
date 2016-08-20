#include <iostream>
#include <utility>
#include <string>
using namespace std;

class Solution {
  public:
    string reverseString(string s) {
      size_t size = s.size();
      for(size_t i = 0; i < size / 2; ++i ) swap(s[i], s[size - 1 - i] );
      return s;
    }
};

int main() {
  string str = "hello";
  Solution s;
  cout<<s.reverseString(str)<<endl;
  return 0;
}
