#include <queue>
#include <iostream>
using namespace std;

class Stack {
  queue<int> q;

  public:
    // Push element x onto stack.
    void push(int x) {
      size_t size = q.size();
      q.push(x);
      for( ; size > 0; --size ) {
        int tmp = q.front();
        q.pop();
        q.push(tmp);
      }
    }

    // Removes the element on front of the stack.
    void pop() {
      q.pop();
    }

    // Get the front element.
    int top() {
      return q.front();
    }

    // Return whether the stack is empty.
    bool empty() {
      return q.empty();
    }
};

int main() {
  Stack stack;
  stack.push(1);
  stack.push(2);
  cout<<stack.top()<<endl;
  stack.pop();
  cout<<stack.top()<<endl;
  stack.push(3);
  stack.push(4);
  cout<<stack.top()<<endl;
  return 0;
}
