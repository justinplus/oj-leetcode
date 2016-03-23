#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
  using hash = unordered_map<int, int>;
  public:

    // TLE
    int nthSuperUglyNumber_TLE(int n, vector<int>& primes) {
      // vector<int> res {1}; NOTE: do not work
      vector<int> res(n);
      res[0] = 1;
      hash pos;
      for( int p : primes ) pos.insert( {p,0} );
      hash val { pos };

      int min_v;
      for( int i = 1; i < n; ++i ) {
        min_v = 0;
        for( auto &pair : pos ) {
          val[pair.first] = res[pair.second] * pair.first;
          if( min_v == 0 || val[pair.first] < min_v ) min_v = val[pair.first];
          
        }

        // res.push_back(min_v);
        res[i] = min_v;

        for(auto &pair : pos )
          if(val[pair.first] == min_v)
            ++pair.second;
        
      }

      return res.back();
    }

    // NOTE: the use of unordered_map reduces the performance
    int nthSuperUglyNumber(int n, vector<int>& primes) {
      vector<int> res(n);
      res[0] = 1;
      vector<int> pos(primes.size());
      vector<int> val(primes.size());

      int min_v;
      for( int i = 1; i < n; ++i ) {
        min_v = 0;
        for( unsigned j = 0; j < primes.size(); ++j ) {
          val[j] = res[pos[j]] * primes[j];
          if( min_v == 0 || val[j] < min_v ) min_v = val[j];
        }

        res[i] = min_v;

        for( unsigned j = 0; j < primes.size(); ++j )
          if(val[j] == min_v)
            ++pos[j];
      }

      return res.back();
    }
};

int main() {
  Solution s;
  vector<int> primes = {2,7,13,19};
  cout<<s.nthSuperUglyNumber(12, primes)<<endl;

  vector<int> primes_2 = {2,3,5,13,19,29,31,41,43,53,59,73,83,89,97,103,107,109,127,137,139,149,163,173,179,193,197,199,211,223,227,229,239,241,251,257,263,269,271,281,317,331,337,347,353,359,367,373,379,389,397,409,419,421,433,449,457,461,463,479,487,509,521,523,541,547,563,569,577,593,599,601,613,619,631,641,659,673,683,701,709,719,733,739,743,757,761,769,773,809,811,829,857,859,881,919,947,953,967,971};
  cout<<s.nthSuperUglyNumber(4000, primes_2)<<endl;

  return 0;
}
