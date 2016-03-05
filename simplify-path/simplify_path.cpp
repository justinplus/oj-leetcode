#include <vector>
#include <string>
#include <iostream>
using namespace std;

class Solution { // TODO: make code conciser
  public:
    string simplifyPath(string path) {

      const char delimiter = '/';
      const string cur_dir = ".";
      const string par_dir = "..";
      
      if( path.back()!= delimiter ) path.append(1, delimiter);

      vector<string> segs;
      string seg;

      unsigned pre = 0, cur = 0;
      while( path[cur] == delimiter ) cur++;
      pre = cur;

      while( cur < path.size() ) {
        while( path[cur] != delimiter ) cur++; 
        seg = path.substr(pre, cur - pre);
        if( seg == par_dir) {
          if( segs.size() != 0 ) segs.pop_back();
        }
        else if(seg != cur_dir) segs.push_back(seg);
        while( path[cur] == delimiter ) cur++;
        // Attn: multiple "/" should be considered
        // TODO: may cause bug here, string always append a '\0' to the end??
        pre = cur;
      }

      string res;
      for( auto &seg : segs ) {
        res.append(1, delimiter);
        res.append(seg);
      }
      return res.size() == 0 ? string(1, delimiter) : res;
    }
};

int main() {
  Solution s;
  cout<<s.simplifyPath("/..")<<endl;
  cout<<s.simplifyPath("/a/./b/../../c/")<<endl;
  cout<<s.simplifyPath("///TJbrd/owxdG//")<<endl; // Attn
  
  return 0;
}
