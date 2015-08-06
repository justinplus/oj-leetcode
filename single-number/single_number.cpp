#include <unordered_set>
#include <vector>
#include <iostream>
using namespace std;

class Solution {
  public:
    int singleNumber(vector<int>& nums) {
      unordered_set<int> set;
      for( unsigned i = 0; i < nums.size(); i++ ){
        if( set.find( nums[i] ) != set.end() ){
          set.erase( nums[i] );
        }else{
          set.insert( nums[i] );
        }
      }
      return * set.begin();
    }
};

// TODO: implement without using extra memory

int main(){
  int vec[] = {5, 2, 9, 11, 5, 9, 2};
  vector<int> v(vec, vec+7);
  Solution solu;
  cout<<solu.singleNumber(v)<<endl;
  return 0;
}

