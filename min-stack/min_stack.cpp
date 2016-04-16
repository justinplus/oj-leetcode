#include <iostream>
#include <stack>
#include <vector>
#include <list>
#include <algorithm>
using namespace std;

// TLE
class MinStack_TLE {
  stack<list<int>::iterator> stk;
  list<int> sorted;

  public:
    void push(int x) {
      auto pos = lower_bound( sorted.begin(), sorted.end(), x);
      stk.push(sorted.insert(pos, x));
    }

    void pop() {
      auto it = stk.top();
      stk.pop();
      sorted.erase(it);
    }

    int top() {
      return *stk.top();
    }

    int getMin() {
      return sorted.front();
    }
};

class MinStack {
  stack<pair<int, int>> stk;

  public:
    void push(int x) {
      if(stk.empty())
        stk.push({x, x});
      else
        stk.push({x, min(x, stk.top().second)});
    }

    void pop() {
      stk.pop();
    }

    int top() {
      return stk.top().first;
    }

    int getMin() {
      return stk.top().second;
    }
};


int main() {
  MinStack ms;
  ms.push(3);
  ms.push(4);
  ms.push(1);
  ms.push(2);
  cout<<ms.top()<<endl;
  cout<<ms.getMin()<<endl;

  ms.pop();
  cout<<ms.top()<<endl;
  cout<<ms.getMin()<<endl;

  ms.pop();
  cout<<ms.top()<<endl;
  cout<<ms.getMin()<<endl;

  return 0;
}
