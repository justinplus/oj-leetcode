#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
  public:
    // 12ms TODO: any better?
    int maxProfit(vector<int>& prices) {
      if(prices.size() <= 1) return 0;

      int res_1 = 0;
      int res_2 = 0, res_2_ = 0;
      int _min = prices.front();

      for( unsigned i = 1; i < prices.size(); i++){

        res_2_ = max( res_2_ + prices[i] - prices[i-1], res_1);

        res_1 = max(prices[i] - _min, res_1);
        _min = min(_min, prices[i]);

        res_2 = max( res_1, max( res_2, res_2_));
      }
      return res_2;
    }
};

int main() {
  Solution s;
  vector<int> prices {1,2,3,4,5,3,3,1,2,3,4,2,1,2,3,3,9,2,2};
  // vector<int> prices {1,2,3};
  cout<<s.maxProfit(prices)<<endl;
  return 0;
}
