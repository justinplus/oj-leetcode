#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
  public:
    int singleNumber(vector<int>& nums) {
      unordered_map<int, int> map;
      for( unsigned i = 0; i < nums.size(); i++ ){
        unordered_map<int, int>::iterator it = map.find(nums[i]);
        if ( it == map.end() ){
          map[nums[i]] = 1;
        }else if( it->second == 1 ){
          it->second ++;
        }else{
          map.erase(it);
        }
      }
      return map.begin()->first;
    }
};

// TODO: implement without using extra memory

int main(){
  int vec[] = { 5, 2, 9, 11, 2, 2, 9, 5, 5, 9 };
  vector<int> v(vec, vec+10);
  Solution solu;
  cout<<solu.singleNumber(v)<<endl;
  return 0;
}

