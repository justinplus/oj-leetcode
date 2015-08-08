#include <cstring>
#include <string>
#include <vector>
#include <iostream>
using namespace std;

class WordDictionary {
  public:
    static const int LEN = 'z' - 'a' + 1;

    ~WordDictionary(){
      for(unsigned i = 0; i < elems.size(); i++) {
        delete [] elems[i];
      }
    }

    // Adds a word into the data structure.
    void addWord(string word) {
      for( unsigned i = elems.size(); i < word.size(); i++){
        elems.push_back(NULL);
      }
      int pos = word.size() - 1;
      if( elems[pos] == NULL ){
        elems[pos] = new int[ LEN * word.size() ];
        memset(elems[pos], 0, sizeof(int) * LEN * word.size());
      }
      for( unsigned i = 0; i < word.size(); i++){
        elems[pos][ i*LEN + word[i] - 'a' ] = 1;
      }

    }

    // Returns if the word is in the data structure. A word could
    // contain the dot character '.' to represent any one letter.
    bool search(string word) {
      unsigned len = word.size();
      if( elems.size() < len || elems[len-1] == NULL ) return false;
      int * hash = elems[len-1];
      for(unsigned i = 0; i < len; i++){
        if( word[i] == '.' ) continue;
        if( hash[i*LEN + word[i] - 'a'] == 0 ) return false;
      } 
      return true;

    }
  
  // private:
    vector<int *> elems;
};

// Your WordDictionary object will be instantiated and called as such:
// WordDictionary wordDictionary;
// wordDictionary.addWord("word");
// wordDictionary.search("pattern");

int main() {
  WordDictionary w;
  w.addWord("pop"); 
  w.addWord("dad");
  w.addWord("mad");

  cout<<w.search("pap")<<endl;
  // Output true, Expected: false !!!
  return 0;
}
