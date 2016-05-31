#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>
using namespace std;

class Solution {
  public:
    vector<string> findRepeatedDnaSequences(string s) {
      unordered_map<string,size_t> map;
      vector<string> res;
      for( size_t i = 0; i + 9 < s.size(); ++i ) {
        string sub = s.substr(i, 10);
        if( ++map[sub] == 2) res.push_back(sub);
      }

      return res;
    }

    // TODO: bit manipulation
};

int main() {
  return 0;
}
