#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
  public:
    int maxProfit(vector<int>& prices) {
      if(prices.size() <= 1) return 0;

      int res = 0, res_p = 0;
      int res_ = 0;

      for( unsigned i = 1; i < prices.size(); i++){
        res_ = max(res_p, prices[i] - prices[i-1] + res_);
        res_p = res; // NOTE: transfer the value !!
        res = max(res, res_);
      }
      return res;
    }
};

int main() {
  Solution s;
  vector<int> prices {1,2,4,3,2,12};
  // vector<int> prices {1,2,3};
  cout<<s.maxProfit(prices)<<endl;
  return 0;
}
