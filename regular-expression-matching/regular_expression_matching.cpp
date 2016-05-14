#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
  public:
    // TODO: review & understand
    bool isMatch(string s, string p) {
      size_t s_l = s.size(), p_l = p.size();

      vector<vector<bool>> matched( s_l + 1, vector<bool>(p_l + 1) );
      matched[0][0] = true;

      for( size_t i = 0; i <= s_l; ++i ) {

        // j starts from 1, since matched[i][0] is false when i!=0;
        for( size_t j = 1; j <= p_l; ++j ) {
          char c = p[j-1];

          if( c != '*' ) {
            // The last character of s and p should match;
            // And, matched[i-1][j-1] is true;
            matched[i][j] = i > 0 && matched[i-1][j-1] && (c == '.' || c == s[i-1] );
          } else {
            // 2 situations
            // (1) matched[i][j-2] is true, and there is 0 preceding element of '*';
            // (2) The last character of s should match the preceding element of '*';
            //     And, matched[i-1][j] should be true;
            matched[i][j] = ( j > 1 && matched[i][j-2] ) ||
              ( i > 0 && matched[i-1][j] && (p[j-2] == '.' || p[j-2] == s[i-1] ) );
          }
        }
      }
      return matched[s_l][p_l];
    }

};
