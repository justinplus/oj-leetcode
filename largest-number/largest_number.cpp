#include<string>
#include<iostream>
#include<vector>
#include<cstdio>
#include<algorithm>
using namespace std;

class Solution {
  public:
    // TODO: compare directly
    static bool cmp( const string & a, const string & b) {
      unsigned i = 0;
      for( i = 0; i < a.size() && i < b.size(); i++ )
        if( a[i] != b[i] ) 
          return a[i] > b[i];

      if( a.size() == b.size() )
        return false; // NOTE !
      else if( a.size() > b.size() )
        return a[i] > b[0];
      else
        return a[0] >= b[i];  // NOTE ">="
    }

    static bool cmp_naive( const string & a, const string & b ) {
      string ab = a + b, ba = b + a;
      return ab > ba;
    }

    string largestNumber(vector<int>& nums) {
      char buffer[256];
      vector<string> strs;

      for( int n : nums ) {
        sprintf(buffer, "%d", n);
        strs.push_back(buffer);
      }

      sort(strs.begin(), strs.end(), cmp_naive);

      if( strs.front() == "0" ) 
        return "0";

      string res;
      
      for( string & str : strs )
        res += str;

      return res;

    }
};

int main() {
  Solution s;

  vector<int> nums = {3, 30, 34, 5, 9};
  // runtime error
  vector<int> nums_1= {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
  // wrong answer
  vector<int> nums_2 = {121,12};
  vector<int> nums_3 = {2, 2281};

  /* string a = "222"; */
  // string b = "111";
  // string &rb = b;
  // string &ra = a;
  // rb = ra;
  // cout<<"b: "<<&b<<endl;
  // cout<<"rb: "<<&rb<<endl;
  // cout<<"a: "<<&a<<endl;
  /* cout<<"ra: "<<&ra<<endl; */
  

  // cout<<Solution::cmp("121","12")<<endl;
  cout<<s.largestNumber(nums_3)<<endl;

  return 0;
}
