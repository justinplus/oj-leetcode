#include <iostream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;

class Solution {
  public:
    string countAndSay(int n) {
      string pre("1");
      stringstream ss;

      for( int k = 0; k < n - 1; ++k ) {
        int i = 0, j = 0;
        while( i < (int) pre.size() ) {
          int cnt = 0;
          for( ; j < (int) pre.size() && pre[i] == pre[j]; ++j ) { ++cnt;}
          ss<<cnt<<pre[i];
          i = j;
          // cout<<i<<endl;
        }
        ss>>pre;
        ss.clear();
      }

      return pre;
    }
};

int main() {
  Solution s;
  cout<<s.countAndSay(1)<<endl;
  cout<<s.countAndSay(2)<<endl;
  cout<<s.countAndSay(3)<<endl;
  cout<<s.countAndSay(4)<<endl;
  cout<<s.countAndSay(5)<<endl;
  cout<<s.countAndSay(6)<<endl;
  cout<<s.countAndSay(7)<<endl;
  cout<<s.countAndSay(17)<<endl;
  return 0;
}
