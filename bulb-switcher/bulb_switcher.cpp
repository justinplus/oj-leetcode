#include <iostream>
#include <cmath>
using namespace std;

class Solution {
  public:
    int bulbSwitch(int n) {
      int sum = 0;

      for(int i = 1; i <= n; i++) {
        int cnt = 1;
        for(int j = 2; j <= i; j++) {
          if( i % j == 0 ) cnt ++;
        }
        sum += cnt % 2;
      }

      return sum;
    }

    int bulbSwitch_law(int n) {
      if( n == 0 ) return 0;

      int sum = 0;
      for(int i = 1; i <= n; i++) {
        sum += i*2 + 1;
        if( sum >= n ) return i;
      }  
    }
};

int main(){
  Solution s;
  for(int i = 1; i< 1000; i++)
    cout<<"i: "<<i<<"\ts: "<<s.bulbSwitch(i)<<"\t_s: "<<s.bulbSwitch_law(i)<<endl;
  return 0;
}
