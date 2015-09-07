#include <cstring>
#include <string>
#include <vector>
#include <utility>
#include <iostream>
using namespace std;

class WordDictionary {
  class TrieNode {
    public:
    TrieNode() : isWord(false), childs(new TrieNode * [26]) { // Attn: the order 
      memset( childs, 0, sizeof(TrieNode *) * 26 );
    }

    ~TrieNode() {
      delete [] childs;
    }

    bool isWord; // Need initialization
    TrieNode ** childs;
    // char c; Attn: No char is needed, index implicates this info.
  };

  public:
  WordDictionary() : root(new TrieNode) {}

  ~WordDictionary() {
    destroy(root);
    root = nullptr;
  }

  void destroy( TrieNode * nd ) {
    if(nd) {
      for( int i = 0; i < 26; i++ )
        destroy(nd->childs[i]);
      delete nd;
    }
  }

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
  
  // TODO: Iterative, why is slower !!??
  bool searchIt(string word) {
    const char *ch = word.c_str();
    vector<pair<TrieNode *, int>> path{{root, 0}};
    // path.reserve(128);
    TrieNode *cur;
    while( path.size() ) {
      cur = path.back().first;
      if(!cur || *ch == '\0') {
        if(cur){ 
          if(cur->isWord) return true;
        }
        path.pop_back();
        --ch;
        for(int i = path.size()-1; i >= 0; i--) {
          if( path[i].second < 25 ) {
            path.push_back({path[i].first->childs[++(path[i].second)], 0});
            ++ch;
            break;
          }  
          path.pop_back();
          --ch;
        }
      } else {
        if(*ch == '.') {
          path.push_back({cur->childs[0], 0});
        } else {
          path.back().second = 26;
          path.push_back({cur->childs[(*ch)-'a'], 0});
        }
        ++ch;
      }
    }
    return false;
  }

  // Returns if the word is in the data structure. A word could
  // contain the dot character '.' to represent any one letter.
  bool search(string word) {
    return search(word.c_str(), root);
  }

  // recursive
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

int wrongAnswer() {
  WordDictionary w;
  w.addWord("ran");w.addWord("rune");w.addWord("runner");w.addWord("runs");w.addWord("add");w.addWord("adds");w.addWord("adder");w.addWord("addee");
  cout<<w.search("r.n")<<' '<<w.searchIt("r.n")<<endl;cout<<w.search("ru.n.e")<<' '<<w.searchIt("ru.n.e")<<endl;cout<<w.search("add")<<' '<<w.searchIt("add")<<endl;cout<<w.search("add.")<<' '<<w.searchIt("add.")<<endl;cout<<w.search("adde.")<<' '<<w.searchIt("adde.")<<endl;cout<<w.search(".an.")<<' '<<w.searchIt(".an.")<<endl;cout<<w.search("...s")<<' '<<w.searchIt("...s")<<endl;cout<<w.search("....e.")<<' '<<w.searchIt("....e.")<<endl;cout<<w.search(".......")<<' '<<w.searchIt(".......")<<endl;cout<<w.search("..n.r")<<' '<<w.searchIt("..n.r")<<endl;
  cout<<"------"<<endl;
  return 0;
}

int test(){
  WordDictionary w;
  w.addWord("ab");

  cout<<w.search("a")<<' '<<w.searchIt("a")<<endl;
  cout<<"------"<<endl;
  return 0;
}

int runtimeError() {
  WordDictionary w;
  w.addWord("at");w.addWord("and");w.addWord("an");w.addWord("add");cout<<w.search("a")<<' '<<w.searchIt("a")<<endl;cout<<w.search(".at")<<' '<<w.searchIt(".at")<<endl;w.addWord("bat");cout<<w.search(".at")<<' '<<w.searchIt(".at")<<endl;cout<<w.search("an.")<<' '<<w.searchIt("an.")<<endl;cout<<w.search("a.d.")<<' '<<w.searchIt("a.d.")<<endl;cout<<w.search("b.")<<' '<<w.searchIt("b.")<<endl;cout<<w.search("a.d")<<' '<<w.searchIt("a.d")<<endl;cout<<w.search(".")<<' '<<w.searchIt(".")<<endl; 
  cout<<"------"<<endl;
  return 0;
}

int main() {
  wrongAnswer();
  runtimeError();
  test();
  WordDictionary w;
  w.addWord("op"); 
  w.addWord("ad");
  w.addWord("ad");
  w.addWord("azc");

  cout<<w.search("ap")<<' '<<w.searchIt("ap")<<endl;
  cout<<w.search(".")<<' '<<w.searchIt(".")<<endl;
  cout<<w.search("o.")<<' '<<w.searchIt("o.")<<endl;
  cout<<w.search(".d")<<' '<<w.searchIt(".d")<<endl;
  cout<<w.search("a.c")<<' '<<w.searchIt("a.c")<<endl;
  // Output true, Expected: false !!!
  return 0;
}
