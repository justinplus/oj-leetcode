#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
  public:
    // TODO: review
    string multiply(string num1, string num2) {
      int l1 = num1.size(), l2 = num2.size();
      vector<int> res(l1 + l2, 0);

      for(int i = l1 - 1; i >= 0; --i)
        for(int j = l2 - 1; j >= 0; --j) {
          int mul = (num1[i] - '0') * (num2[j] - '0');
          int sum = res[i+j+1] + mul;

          res[i+j] += sum / 10;
          res[i+j+1] = sum % 10;
        }
      
      auto it = find_if(res.begin(), res.end(), [](const int n){return n != 0;});
      string str;
      for(; it != res.end(); ++it) str += '0' + *it;

      return str.empty() ? "0" : str;
    }
};

int main() {
  Solution s;
  cout<<s.multiply("99999999999999999", "99999999999999999999");
  return 0;
}
