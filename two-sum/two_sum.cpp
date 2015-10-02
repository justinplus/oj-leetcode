#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
  public:
    vector<int> twoSum(vector<int>& nums, int target) {
      using hash = unordered_map<int, vector<int>>;
      hash h;
      hash::iterator it;
      int i, size = nums.size();
      for(i = 0; i < size; i++) {
        it = h.find(nums[i]);
        if(it == h.end())
          h.insert({nums[i], {i+1}});
        else
          it->second.push_back(i+1);
      }

      for(i = 0; i < size; i++) {
        it = h.find(target-nums[i]);  
        if(it != h.end()) {
          if(nums[i] * 2 != target) return {i+1, it->second.front()};
          else {
            if(it->second.size() < 2)
              continue;
            else
              return { it->second[0], it->second[1] };
          }
        }
      }

      return {};
    }
};

// Clearear solution, but more specific
vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int, int> hash;
    vector<int> res(2, 0);
    for (int i = 0; i < int(nums.size()); i++) {
        if (hash.find(target - nums[i]) != hash.end()) {
            res[0] = hash[target - nums[i]], res[1] = i + 1;
            return res;
        }
        hash[nums[i]] = i + 1;
    }
    return {};
}

void inspect( const vector<int> v ) {
  for(int n : v) cout<<n<<' ';
  cout<<endl;
}

int main() {
  Solution s;
  vector<int> v = {3,2,4,3};
  inspect(twoSum(v, 6));
  inspect(s.twoSum(v,6));
  return 0;
}
