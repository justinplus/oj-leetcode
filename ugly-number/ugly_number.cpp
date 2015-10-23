#include <iostream>
using namespace std;

class Solution {
  public:
    bool isUgly(int num) {
      if( num <= 0 ) return false;

      while( num % 2 == 0 ) num/=2;
      while( num % 3 == 0 ) num/=3;
      while( num % 5 == 0 ) num/=5;

      return num == 1;
        
    }
};

int main() {
  Solution s;
  cout<<s.isUgly(0)<<endl; // Attn
  cout<<s.isUgly(1)<<endl;
  cout<<s.isUgly(2)<<endl;
  cout<<s.isUgly(3)<<endl;
  cout<<s.isUgly(5)<<endl;
  cout<<s.isUgly(14)<<endl;
  cout<<s.isUgly(100)<<endl;
  return 0;
}
