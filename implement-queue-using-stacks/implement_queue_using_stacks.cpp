#include <iostream>
#include <stack>
#include <vector>
using namespace std;

class Queue {
  stack<int> in;
  stack<int> out;

  public:
  // Push element x to the back of queue.
  void push(int x) {
    in.push(x);
  }

  // Removes the element from in front of queue.
  void pop(void) {
    if(out.empty()) transfer();
    out.pop();
  }

  // Get the front element.
  int peek(void) {
    if(out.empty()) transfer();
    return out.top();
  }

  // Return whether the queue is empty.
  bool empty(void) {
    return in.empty() && out.empty();
  }

  void transfer(void) {
    while(!in.empty()){
      out.push(in.top());
      in.pop();
    }
  }
};

int main() {
  vector<int> nums {1,2,3,4,5,6};
  Queue q;

  q.push(1);
  q.push(2);
  cout<<q.peek()<<endl;
  q.pop();
  q.push(3);
  q.push(4);
  cout<<q.peek()<<endl;
  q.pop();
  cout<<q.peek()<<endl;
  q.pop();
  cout<<q.peek()<<endl;
  q.pop();

  while( !q.empty() ) {
    cout<<q.peek()<<endl;
    q.pop();
  }
}
