#include <string>
#include <vector>
#include <iostream>
using namespace std;

class WordDictionary {
  public:

    // Adds a word into the data structure.
    void addWord(string word) {
      elems.push_back(word);

    }

    // Returns if the word is in the data structure. A word could
    // contain the dot character '.' to represent any one letter.
    bool search(string word) {
      unsigned len = word.size();
      for(unsigned i = 0; i < elems.size(); i++){
        if( len == elems[i].size() && like(word, elems[i]) ) return true;
      }
      return false;

    }
  
  // private:
    vector<string> elems;
    
    bool like(string &object, string &target){
      for(unsigned i = 0; i < target.size(); i++){
        if( object[i] == '.' ) continue;
        if( object[i] != target[i]) return false;
      }
      return true;
    }
};

// Your WordDictionary object will be instantiated and called as such:
// WordDictionary wordDictionary;
// wordDictionary.addWord("word");
// wordDictionary.search("pattern");

int main() {
  WordDictionary w;
  w.addWord("bad");
  w.addWord("dad");
  w.addWord("mad");

  cout<<w.elems.size()<<endl;
  for( unsigned i = 0; i < w.elems.size(); i++)
    cout<<w.elems[i]<<'\t';

  cout<<endl;
  cout<<w.search("pad")<<endl;
  cout<<w.search("bad")<<endl;
  cout<<w.search(".ad")<<endl;
  cout<<w.search("b..")<<endl;
  cout<<w.search("...")<<endl;
  cout<<w.search(".a.")<<endl;

  return 0;
}
