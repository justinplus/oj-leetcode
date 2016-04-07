#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
using namespace std;

class Solution {
  public:
    int longestConsecutive(vector<int>& nums) {
      if(nums.empty()) return 0;

      unordered_map<int,int> mapping;
      vector<int> ids( nums.size() );

      // TODO: refactor
      for(int i = 0; i < (int)nums.size(); ++i)
        if(mapping.find(nums[i]) == mapping.end()){
          mapping[nums[i]] = i;
          ids[i] = -1;

          if( mapping.find(nums[i]-1) != mapping.end()){
            // find the root
            int r = mapping[nums[i]-1];
            while( ids[r] >= 0 ) r = ids[r];

            // path compression
            int t = mapping[nums[i]-1];
            while( ids[t] >= 0 ) {
              int tmp = ids[t];
              ids[t] = r;
              t = tmp;
            }

            // union
            ids[r] += ids[i];
            ids[i] = r;
          }

          if( mapping.find(nums[i]+1) != mapping.end()) {
            // find the root
            int r = mapping[nums[i]+1];
            while( ids[r] >= 0 ) r = ids[r];

            // path compression
            int t = mapping[nums[i]+1];
            while( ids[t] >= 0 ) {
              int tmp = ids[t];
              ids[t] = r;
              t = tmp;
            }

            int r2 = i;
            while( ids[r2] >= 0 ) r2 = ids[r2];
            ids[r] += ids[r2];
            ids[r2] = r;
          }


        }

      return - *min_element(ids.begin(), ids.end());
    }

    // using set
    int longestConsecutive_set(vector<int>& nums) {
      unordered_set<int> set;
      for(int n : nums) set.insert(n);

      int maxi = 1;
      // NOTE: !! wrong
      // for(int n : set) {
      while(!set.empty()){
        int n = *set.begin();
        if(set.erase(n)) {
          int cnt = 1;
          int m = n-1;
          while( set.erase(m) ) --m;
          cnt += n-m-1;

          m = n+1;
          while( set.erase(m) ) ++m;
          cnt += m-n-1;

          maxi = max(maxi, cnt);
        }
      }
      return maxi;
    }
};

int main() {
  vector<int> nums {3,1,2,4,7,8,9,121,22,5,0,6};
  // wrong answer
  vector<int> nums_2 {1,-8,7,-2,-4,-4,6,3,-4,0,-7,-1,5,1,-9,-3};
  Solution s;
  cout<<s.longestConsecutive(nums_2)<<endl;
  cout<<s.longestConsecutive_set(nums_2)<<endl;
  return 0;
}
