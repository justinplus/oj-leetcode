#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
  public:
    // Using Hash
    using hash = unordered_map<int, int>;

    int majorityElement(vector<int>& nums) {
      hash h;
      for( int n : nums ) {
        if( ++h[n] > int(nums.size()/2) ) return n;
      }
      return 0;
    }
};

int main() {
  vector<int> v = { 1, 1, 2 };
  Solution s;
  cout<<s.majorityElement(v)<<endl;
  return 0;
}
