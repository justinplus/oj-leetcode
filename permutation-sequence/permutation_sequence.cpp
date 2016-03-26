#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
  public:
    // TLE
    string getPermutation_TLE(int n, int k) {
      if( k < 1 || n < 1 || k > factorial(n) ) return {};
      vector<int> vec(n, -1);
      string str(n, '\0');
      int c = 0;

      getPermutation(str, vec, 0, c, k);

      return str;
    }

    bool getPermutation(string &str, vector<int> &vec, int d, int &c, int k) {
      if( d == (int)vec.size() ) {
        ++c;
        if( c == k ){
          for(unsigned i = 0; i < vec.size(); ++i ) {
            str[vec[i]] = '1' + i; // NOTE: the order
          }
          return true;
        }
        return false;
      }

      for( unsigned i = 0; i < vec.size(); ++i ) {
        if( vec[i] == -1 ) {
          vec[i] = d;
          if( getPermutation(str, vec, d+1, c, k) ) return true;
          vec[i] = -1;
        }
      }

      return false;
    }

    string getPermutation(int n, int k) {
      if( k < 1 || n < 1 || k > factorial(n) ) return {};

      vector<int> f {1};
      for( int i = 1; i < n; ++i ) f.push_back(f.back() * i);

      string str;
      vector<int> vec(n, 0);
      int q;
      --k;
      for( int i = 0; i < n; ++i ) {
        q = k / f[n-1-i];
        k %= f[n-1-i];
        // cout<<"q: "<<q<<"\tk: "<<k<<endl;

        int pos = -1;
        for( int j = 0; j <= q; ++j) {
          ++pos;
          while(vec[pos] != 0) ++pos;
        }

        // cout<<"pos: "<<pos<<endl;

        vec[pos] = 1;
        str += '1' + pos;
      }
      
      return str;
    }

    static int factorial(int num ) {
      int res = 1;
      for( int i = 2; i <= num; ++i ) res *= i;
      return res;
    }
};

int main() {
  Solution s;
  cout<<s.getPermutation(3,4)<<endl;

  return 0;
}
