#include <vector>
#include <iostream>
using namespace std;

class Iterator {
  const vector<int>& nums;
  size_t index;

  public:
  Iterator(const vector<int>& nums) : nums(nums), index(0) {
    // cout<<&nums<<endl;
    // cout<<&(this->nums)<<endl;
  };
  Iterator(const Iterator &iter) : nums(iter.nums), index(iter.index) {};
  virtual ~Iterator() {};
  int next() {
    int val = nums[index];
    ++index;
    return val;
  }
  bool hasNext() const {
    return index < nums.size();
  }
};


// always pre-fetch
class PeekingIterator : public Iterator {
  public:
    PeekingIterator(const vector<int>& nums) : Iterator(nums), next_p(nullptr) {
      if( Iterator::hasNext() ) next_p = new int(Iterator::next());
    }

    virtual ~PeekingIterator() { delete next_p; }

    int peek() { return *next_p; }

    int next() {
      int ret = *next_p;
      delete next_p;
      next_p = nullptr;
      if( Iterator::hasNext() ) next_p = new int(Iterator::next());
      return ret;
    }

    bool hasNext() const { return next_p; }

  private:
    const int *next_p;
};

// pre-fetch only when peek() is called
class PeekingIterator_wiser : public Iterator {
  public:
    // NOTE: the initialization of next_p
    PeekingIterator_wiser(const vector<int> & nums) : Iterator(nums), next_p(nullptr) {
    }

    int peek() {
      if( !next_p ) next_p = new int( Iterator::next() );
      return *next_p;
    }

    int next() {
      if( next_p ) {
        int ret = *next_p;
        delete next_p;
        next_p = nullptr;
        return ret;
      } else {
        return Iterator::next();
      }
    }

    bool hasNext() const {
      return next_p || Iterator::hasNext();
    }

  private:
    const int *next_p;
};

// copy the iterator
// TODO: Why much quicker?
class PeekingIterator_cp : public Iterator {
  public:
    PeekingIterator_cp(const vector<int>& nums) : Iterator(nums) {}
    int peek() {
      return Iterator(*this).next();
    }
};

int main() {
  vector<int> nums {1,2,3,4};
  // PeekingIterator pit(nums);

/*   while( pit.hasNext() ) { */
    // cout<<pit.peek()<<endl;
    // cout<<pit.next()<<endl;
  /* } */

  PeekingIterator_wiser pwit(nums);

  while( pwit.hasNext() ) {
    cout<<pwit.peek()<<endl;
    cout<<pwit.next()<<endl;
  }

  PeekingIterator_cp pcit(nums);

  while( pcit.hasNext() ) {
    cout<<pcit.peek()<<endl;
    cout<<pcit.next()<<endl;
  }

  return 0;
}
