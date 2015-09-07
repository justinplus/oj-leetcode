#include <iostream>
#include <cstring>
#include <array>
using namespace std;

class TrieNode {
  public:
    // Initialize your data structure here.
    TrieNode() : isWord{false}, childs(new TrieNode *[26]) {
      memset(childs, 0, 26*sizeof(TrieNode *));
    }

    ~TrieNode() {
      delete [] childs;
    }

    bool isWord;
    TrieNode **childs;
};

class Trie {
  public:
    Trie() {
      root = new TrieNode();
    }

    ~Trie() {
      destroy(root);
      root = nullptr;
    }

    void destroy( TrieNode * nd ) {
      if( nd ) {
        for(int i = 0; i < 26; i++)
          destroy( nd->childs[i] );
        delete nd;
      }
    }

    // Inserts a word into the trie.
    void insert(string word) {
      TrieNode *cur = root;
      int index;
      for(char ch : word) {
        index = ch-'a';
        if(!cur->childs[index]) cur->childs[index] = new TrieNode();
        cur = cur->childs[index];
      }
      cur->isWord = true;
    }

    // Returns if the word is in the trie.
    bool search(string word) {
      const char *ch = word.c_str();
      TrieNode *cur = root;
      while(*ch) {
        cur = cur->childs[*ch-'a'];
        ++ch;
        if(!cur) return false;
      }
      return cur->isWord;
    }

    // Returns if there is any word in the trie
    // that starts with the given prefix.
    bool startsWith(string prefix) {
      const char *ch = prefix.c_str();
      TrieNode *cur = root;
      while(*ch) {
        cur = cur->childs[*ch-'a'];
        ++ch;
        if(!cur) return false;
      }
      return true;
    }

  private:
    TrieNode* root;
};

int main() {
  Trie t;
  t.insert("abc");
  t.insert("ass");

  cout<< t.search("abc")<<endl;
  cout<< t.search("ass")<<endl;
  cout<< t.search("abb")<<endl;
  cout<< t.startsWith("abccc")<<endl;

  return 0;
}
// Your Trie object will be instantiated and called as such:
// Trie trie;
// trie.insert("somestring");
// trie.search("key");
