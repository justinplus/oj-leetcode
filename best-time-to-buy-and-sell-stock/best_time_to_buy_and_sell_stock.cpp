#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
  public:
    // 12ms
    int maxProfit_slow(vector<int>& prices) {
      vector<int> res = {0, 0};
      int mini;
      if(!prices.empty()) mini = prices.front();

      for( unsigned i = 2; i <= prices.size(); i++) {
        res.push_back(max(prices[i-1] - mini, res.back()));
        mini = min(mini, prices[i-1]);
      }
      return res[prices.size()];
    }

    // 8ms
    int maxProfit(vector<int>& prices) {
      if(prices.size() <= 1) return 0;

      int res = 0;
      int mini = prices.front();

      for( unsigned i = 2; i <= prices.size(); i++) {
        res = max(prices[i-1] - mini, res);
        mini = min(mini, prices[i-1]);
      }
      return res;
    }
};

int main() {
  Solution s;
  vector<int> prices = {1,2,3,0,2,5,2,1};
  cout<<s.maxProfit(prices)<<endl;
  return 0;
}
