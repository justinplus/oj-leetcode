#include <string>
#include <vector>
#include <iostream>
#include <sstream>
using namespace std;

class Solution {
  public:
    int compareVersion(string version1, string version2) {
      int num;
      vector<int> ver1, ver2;
      stringstream ss;
      ss << version1;
      while( ss >> num ){
        ver1.push_back(num);
        ss.ignore();
      }

      ss.clear(); ss << version2;
      while( ss >> num ){
        ver2.push_back(num);
        ss.ignore();
      }

      size_t m1 = ver1.size(), m2 = ver2.size();
      size_t i = 0;
      for( ; i < m1 && i < m2; ++i )
        if( ver1[i] > ver2[i] ) return 1;
        else if( ver1[i] < ver2[i] ) return -1;

      int res = 1;
      if( m2 > m1 ) { ver1.swap(ver2); res = -1; }

      for( ; i < ver1.size(); ++i )
        if( ver1[i] != 0) return res;

      return 0;

    }
};

int main() {
  Solution s;
  cout<<s.compareVersion("1.1.0", "1.1.0.0.0.0.1");
  return 0;
}
