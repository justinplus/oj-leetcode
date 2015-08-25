#include <iostream>
#include <vector>
using namespace std;

class Solution {
  public:
    int numTrees(int n) {
      long long ans = 1;
      for(int i = 1; i <= n; i++)
      {
        ans *= 2*n-i+1;
        ans /= i; // i numbers in a row exist at lest one number is a multiple of another
      }      
      return ans / (n+1);
    }
  
    int numTreesDP(int n) {
      vector<int> ans;
      ans.push_back(1);

      int sum = 0;
      for(int i = 1; i <= n; i++) {
        sum = 0;
        for(int j = 1; j <= i; j++) {
          sum += ans[j-1]*ans[i-j];
        }
        ans.push_back(sum);
      }

      return ans[n];
    }
};

int main() {
  Solution s;
  cout<< s.numTreesDP(19)<<endl;
  cout<< s.numTrees(19)<<endl;
  return 0;
}
