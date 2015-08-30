#include <iostream>
#include <vector>
using namespace std;

class Solution {
  public:
    vector<int> singleNumber(vector<int>& nums) {
      vector<int> ans;

      int _xor = 0; // Attention: xor is a operator
      for(int &n : nums) _xor ^= n;

      int lowestBit = _xor & (~(_xor-1)); // the same as _xor & -_xor
      int x = 0;
      for(int &n : nums) 
        if( n & lowestBit ) x ^= n;

      ans.push_back(x);
      ans.push_back(_xor ^ x);
      
      return ans;
    }
}; // TODO: Review and understand

void inspect(const vector<int>& v) {
  for(const int& n : v) cout<<n<<' ';
  cout<<endl;
}

int main() {
  vector<int> v{1, 2, 1, 3, 2, 5};
  Solution s;
  inspect(s.singleNumber(v));
  return 0;
}
