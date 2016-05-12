#include <iostream>
using namespace std;

class Solution {
  public:
    uint32_t reverseBits(uint32_t n) {
      uint32_t lmask = 1u;
      uint32_t hmask = ~(uint32_t(-1) >> 1);

      size_t len = sizeof(uint32_t) * 8;
      for( size_t i = 0; i < len/2; ++i ) {
        uint32_t l = n & (lmask << i);
        uint32_t h = n & (hmask >> i);

        if( l == 0 )
          n &= (l << (len-1-i*2)) | ~(hmask >> i);
        else
          n |= l << (len-1-i*2);

        if( h == 0 )
          n &= (h >> (len-1-i*2)) | ~(lmask << i);
        else
          n |= h >> (len-1-i*2);
      }

      return n;
    }

    // using xor
    uint32_t reverseBits_xor(uint32_t n) {
      const size_t len = sizeof(uint32_t) * 8;
      for( size_t i = 0; i < len/2; ++i )
        if( ( (n >> i) & 1u ) ^ ( ( n >> 32-i-1 ) & 1u ) == 1 ) {
          n ^= ( 1u << i );
          n ^= ( 1u << 32-i-1 );
        }
      return n;
    }
};


int main() {
  Solution s;

  cout<<s.reverseBits(43261596)<<endl;
  cout<<s.reverseBits_xor(43261596)<<endl;
  cout<<s.reverseBits(1)<<endl;
  cout<<s.reverseBits_xor(1)<<endl;
  cout<<s.reverseBits(2)<<endl;
  cout<<s.reverseBits_xor(2)<<endl;
  cout<<s.reverseBits(4)<<endl;
  cout<<s.reverseBits_xor(4)<<endl;
  return 0;
}
