#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

class Solution {
  public:
    // assume k is always valid
    vector<int> topKFrequent(vector<int>& nums, int k) {
      unordered_map<int,int> counter;
      for( int num : nums ) ++counter[num];

      vector<pair<int,int>> arr;
      for( pair<int,int> p : counter ) arr.push_back(p);

      sort(arr.begin(), arr.end(),
          [](const pair<int,int> &p1, const pair<int,int> &p2 ) {return p1.second > p2.second;} );

      vector<int> res;
      for( int i = 0; i < k && i < (int)arr.size(); ++i ) res.push_back(arr[i].first);

      return res;
    }
};

int main() {
  vector<int> nums {1,1,1,2,2,3,3,3,3,3,23,4,3,23,4,23,42,34,23,423,3,1};
  Solution s;
  for( int num : s.topKFrequent(nums, 3) )
    cout<<num<<endl;
  return 0;
}
