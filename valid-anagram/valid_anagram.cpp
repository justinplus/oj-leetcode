#include <string>
using namespace std;

class Solution {
  public:
    bool isAnagram(string s, string t) {
      int letters[26] = {};
      for( char ch : s ) letters[ch - 'a']++;
      for( char ch : t ) letters[ch - 'a']--;
      for( auto letter : letters ) if( letter != 0 ) return false;
      return true;
    }
};
