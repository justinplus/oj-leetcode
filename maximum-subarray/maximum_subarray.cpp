#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// TODO: very inefficient
class Solution {
  public:
    int maxSubArray_ineff(vector<int>& nums) {
      int i = 0, j = 0;
      int sum = nums[i];
      int succ = 0;
      int prev = 0;

      for( int n = 1; n < (int)nums.size(); n++ ) {
        if( sum <= 0 ) {
          if( nums[n] >= sum ) {
            i = n;
            j = n;
            sum = nums[n];
          }
        } else {
          succ += nums[n];

          if( succ >= 0 ) {
            j = n;
            sum += succ;
            succ = 0;
            prev = 0;
            for( int m = i; m < j; m++ ) {
              prev += nums[m];
              if( prev <= 0 ) {
                sum -= prev;
                i = m+1;
                prev = 0;
              }
            }
          } else {
            int _sum = succ;
            int _i = j+1;
            int _prev = 0;
            for( int u = _i; u < n; u++) {
              _prev += nums[u];
              if(_prev <= 0) {
                _sum -= _prev;
                _i = u+1;
                _prev = 0;
              }
            }
            cout<<"_sum: "<<_sum<<endl;
            if( _sum > sum ) {
              sum = _sum;
              i = _i;
              j = n;
              cout<<"succ: "<<succ<<endl;
              succ = 0;
            }
          }
        }
        cout<<"i: "<<i<<"\tj: "<<j<<"\tsum: "<<sum<<endl;
      }

      return sum;
    }

    int maxSubArray(vector<int> &nums) {
      if(nums.empty()) return 0;

      vector<int> sums ( nums.size(), 0 );
      sums.front() = nums.front();

      for( size_t i = 1; i < nums.size(); ++i )
        sums[i] = max(nums[i], nums[i] + sums[i-1]);

      return *max_element(sums.begin(), sums.end());

    }
};

int main() {
  Solution s;
  vector<int> nums_0 = {-2,-3,-1};
  vector<int> nums_1 = {-2,1,-3,4,-1,2,1,-5,4};
  vector<int> nums_2 = {-2,3,-2,-2,-2,-2,8,9,-20,-2, 10, 8,-4,5};
  vector<int> nums_3 = {0, -3, 1, 1};
  cout<<s.maxSubArray(nums_2)<<endl;
  return 0;
} 
