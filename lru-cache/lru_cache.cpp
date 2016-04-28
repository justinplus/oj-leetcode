#include <iostream>
#include <unordered_map>
#include <list>
#include <utility>
using namespace std;

class LRUCache{ // TODO: improve it
  using LRU_map = unordered_map<int, list<pair<int, int>>::iterator>;
  public:
    LRUCache(size_t capacity) : capacity(capacity) {
      map.reserve(capacity); // Attn: Do not actually improve performance
    }

    int get(int key) {
      auto it = map.find(key);
      if( it == map.end() ) return -1;

      prior.push_front(*(it->second));
      prior.erase(it->second);
      it->second = prior.begin();
      return it->second->second;
    }

    void set(int key, int value) {
      LRU_map::iterator it = map.find(key);
      prior.push_front({key, value});
      if( it != map.end() ) {
        prior.erase(it->second);
        it->second = prior.begin();
      } else {
        // TODO: test map.size() and list.size()
        if( map.size() > capacity ) {
          map.erase(prior.back().first);
          prior.pop_back();
        }
        map.insert( {key, prior.begin()} );
      }
    }

    void inspect() {
      for( auto &n : prior )
        cout<<"key: "<<n.first<<"; val: "<<n.second<<' ';
      cout<<"hash_size: "<<map.size()<<endl;
    }

  private:
    const size_t capacity;
    LRU_map map;
    list<pair<int, int>> prior;

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
  cout<<"-----------------"<<endl;
  test();
  return 0;
}
