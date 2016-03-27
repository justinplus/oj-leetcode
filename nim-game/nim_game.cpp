#include <iostream>
#include <vector>
using namespace std;

class Solution {
  public:
    // MLE when using int
    bool canWinNim_MLE(int n) {
      vector<bool> res {1,1,1,0,1,1};
      if( n <= (int) res.size() ) return res[n-1];
      
      for(int i = 6; i < n; ++i) {
        if( res[i-1] == 0 || res[i-2] == 0 || res[i-3] == 0 )
          res.push_back(1);
        else
          res.push_back(0);
      }
      for(int n : res) cout<<n<<' ';
      cout<<endl;

      return res.back();
    }

    bool canWinNim(int n) {
      return !(n % 4 == 0);
    }
};

int main() {
  Solution s;
  cout<<s.canWinNim(100);
  return 0;
}
