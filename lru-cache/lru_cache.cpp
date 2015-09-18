#include <iostream>
#include <unordered_map>
#include <list>
#include <utility>
using namespace std;

class LRUCache{
  public:
    LRUCache(unsigned capacity) : capacity(capacity) {
      // elems.reserve(capacity); // ??
    }

    int get(int key) {
      auto it = elems.find(key);
      if( it == elems.end() ) return -1;
      prior.remove(key);
      prior.push_front(key);
      return it->second;
    }

    void set(int key, int value) {
      unordered_map<int, int>::iterator it;
      it = elems.find(key);
      if( it != elems.end() ) {
        it->second = value;
        prior.remove(key);
        prior.push_front(key);
      } else {
        if( prior.size() >= capacity ) { // Attn: Forget to erase from hash, last version wrong actually 
          elems.erase(prior.back()); 
          prior.pop_back();
        }
        elems.insert( {key, value} );
        prior.push_front(key);
      }
    }

    void inspect() {
      for( auto n : prior )
        cout<<n<<' ';
      cout<<elems.size()<<endl;
    }

  private:
    unsigned capacity;
    unordered_map<int, int> elems;
    list<int> prior;

};

int case_runtime_error(){
  LRUCache lru(1);
  lru.set(2, 1); lru.inspect();
  cout<<"get 2: "<<lru.get(2)<<"; "; lru.inspect();
  lru.set(3, 2); lru.inspect();
  cout<<"get 2: "<<lru.get(2)<<"; "; lru.inspect();
  cout<<"get 3: "<<lru.get(3)<<"; "; lru.inspect();
  return 0;
}

int test() {
  LRUCache lru(4);
  lru.set(3, 4); lru.inspect();
  lru.set(4, 5); lru.inspect();
  cout<<"get 3: "<<lru.get(3)<<"; "; lru.inspect();
  lru.set(1, 100); lru.inspect();
  lru.set(2, 9); lru.inspect();
  cout<<"get 1: "<<lru.get(1)<<"; "; lru.inspect();
  lru.set(2, 50); lru.inspect();
  cout<<"get 2: "<<lru.get(2)<<"; "; lru.inspect();
  lru.set(7, 777); lru.inspect();
  cout<<"get 9: "<<lru.get(9)<<"; "; lru.inspect();
  return 0;
}

int main() {
  case_runtime_error();
  return 0;
}
