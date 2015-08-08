#include <cstring>
#include <string>
#include <vector>
#include <iostream>
using namespace std;

class WordDictionary {
  class TrieNode {
    public:
    TrieNode ** childs;
    bool isWord; // Need initialization
    // char c; No char is needed, index implicates this info.
    TrieNode() : isWord(false) {
      childs = new TrieNode * [26];
      memset( childs, 0, sizeof(TrieNode *) * 26 );
    }
  };

  public:
  WordDictionary() : root(new TrieNode) {}

  // TODO: need destructor
  // ~WordDictionary() {}

  // Adds a word into the data structure.
  void addWord(string word) {
    TrieNode * cur = root;
    for(unsigned i = 0; i < word.size(); i++){
      int index = word[i] - 'a';
      if(!cur->childs[index]) cur->childs[index] = new TrieNode(); // Notice: if !cur->childs[index]
      cur = cur->childs[index];
    }
    cur->isWord = true;
  }

  // Returns if the word is in the data structure. A word could
  // contain the dot character '.' to represent any one letter.
  bool search(string word) {
    return search(word.c_str(), root);
  }

  bool search(const char * ch, const TrieNode * cur) {
    if(!cur) return false;
    if(*ch == '\0') return cur->isWord;
    if(*ch == '.'){
      for( int i = 0; i < 26; i++ ){
        if( search(ch+1, cur->childs[i]) ) return true;
      }      
      return false;
    } else {
      return search(ch+1, cur->childs[*ch - 'a']);
    }
  }

  // private:
  TrieNode * root;
};

// Your WordDictionary object will be instantiated and called as such:
// WordDictionary wordDictionary;
// wordDictionary.addWord("word");
// wordDictionary.search("pattern");

int main() {
  WordDictionary w;
  w.addWord("op"); 
  w.addWord("ad");
  w.addWord("ad");

  cout<<w.search("ap")<<endl;
  cout<<w.search(".")<<endl;
  cout<<w.search("o.")<<endl;
  cout<<w.search(".d")<<endl;
  // Output true, Expected: false !!!
  return 0;
}
