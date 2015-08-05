#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

class Solution {
  public:
    int findKthLargest(vector<int>& nums, int k) {
      make_heap( nums.begin(), nums.end() );
      for( int i=0; i<k-1; i++ ){
        pop_heap( nums.begin(), nums.end()-i );
        // nums.pop_back();
      }
      return nums.front();
    }
};

int main() {
  int test[] = {3, 2, 1, 5, 6, 4};
  vector<int> v(test, test+6);
  Solution solu;
  cout<< solu.findKthLargest(v, 3);
  cout<< "the array: \n";
  for(unsigned int i=0; i<v.size(); i++){
    cout<<v[i]<<'\t';
  }
  return 0;
}


