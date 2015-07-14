class Solution {
public:
	// using bit operation
	bool isPowerOfTwo(int n){
		return n > 0 ? ( n & (n-1) ) == 0 : false;
	}

    bool isPowerOfTwo_math(int n) {
    	long long i = 1;
    	while( true ){
    		if( n == i ) 
    			return true;
    		else if(n > i) 
    			i <<= 1;
    		else
    			return false;
    	}
    }
};