#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
  public:
    // TLE
    int maxProfit_TLE(vector<int>& prices) {
      vector<int> res = {0,0};
      int max;
      int tmp;

      for(unsigned i = 2; i <= prices.size(); ++i) {
        max = 0;
        for(unsigned j = 0; j < i; ++j) {
          tmp = prices[i-1] - prices[j] + res[j];
          if( tmp > max ) max = tmp;
        }
        res.push_back(max);
      }
      return res.back();
    }

    int maxProfit(vector<int>& prices) {
      if(prices.size() <= 1) return 0;

      int res = 0;

      for( unsigned i = 1; i < prices.size(); i++)
        if( prices[i] - prices[i-1] > 0 ) 
          res += prices[i] - prices[i-1];
      
      return res;
    }

};

int main() {
  Solution s;
  vector<int> prices {1,2,3,4,3,2,12};
  cout<<s.maxProfit(prices)<<endl;
  return 0;
}
