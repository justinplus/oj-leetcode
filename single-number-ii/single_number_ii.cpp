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

    // bit manipulation
    int singleNumber_bit(vector<int>& nums) {
      int single = 0;
      for(int &n : nums) single ^= n;
      single ^= single;
      return single;
    }
};


int main(){
  vector<int> v{ 5, 2, 9, 11, 2, 2, 9, 5, 5, 9 };
  Solution solu;
  cout<<solu.singleNumberBM(v)<<endl;
  return 0;
}

