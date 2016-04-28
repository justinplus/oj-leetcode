#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
  public:
    // MLE: full DFA
    int strStr_DFA(string text, string pattern) {
      auto DFA = buildDFA(pattern);

      int m = text.size(), n = pattern.size();
      int i = 0, j = 0;

      for( ; i < m && j < n; ++i ) j = DFA[j][text[i]];

      if( j == n ) return i - n;
      else return -1;
    }

    vector<vector<int>> buildDFA( string pattern ) {
      vector<vector<int>> DFA (1, vector<int>(256) );
      DFA[0][pattern[0]] = 1;
      for( int status = 0, j = 1; j < (int) pattern.size(); ++j) {
        DFA.push_back( DFA[status] );
        DFA[j][pattern[j]] = j+1;
        status = DFA[status][pattern[j]];
      }
      return DFA;
    }

    // TODO: review & understand
    int strStr_Next( string text, string pattern ) {
      int m = text.size(), n = pattern.size();
      if( n == 0 ) return 0;
      auto next = buildNext( pattern );

      int i = 0, j = 0;
      while(  i < m ) {
        if( j == -1 || text[i] == pattern[j] ) {
          ++i;
          ++j;
        } else {
          j = next[j];
        }

        if( j == n ) return i - n;
      }

      return -1;
    }

    vector<int> buildNext( string pattern ) {
      if(pattern.size() == 0) return {};
      vector<int> next(pattern.size());
      next[0] = -1;

      int j = 0, k = -1;
      while( j < (int) pattern.size()-1 ) {
        if( k == -1 || pattern[j] == pattern[k] ) {
          ++j;
          ++k;
          next[j] = k;
        } else {
          k = next[k];
        }
      }
      return next;
    }

};

int main() {
  Solution s;
  string text = "CABABAC";
  string pattern = "ABABAC";
  for( auto n : s.buildNext("ABABBAA") )
    cout<<n<<' ';
  cout<<endl;
  cout<<s.strStr_Next(text, pattern);
  return 0;
}

