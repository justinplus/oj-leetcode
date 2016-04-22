#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <utility>
using namespace std;

/**
 * Definition for singly-linked list.
 */
struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(nullptr) {}
};

class myCompare {
  public:
    // NOTE: operation larger is min heap
    bool operator()( const pair<int,int> &a, const pair<int,int> &b) {
      return a.first > b.first;
    }
};

class Solution {
  public:
    // TODO: improve
    ListNode* mergeKLists(vector<ListNode*>& lists) {
      priority_queue<std::pair<int,int>, std::vector<pair<int,int>>, myCompare> heap;

      for(size_t i = 0; i < lists.size(); ++i)
        if(lists[i]) {
          heap.push( {lists[i]->val, i } );
          lists[i] = lists[i]->next;
        }

      ListNode fake(0), *cur = &fake;
      while( !heap.empty() ) {
        pair<int, int> p = heap.top();
        heap.pop();

        cur->next = new ListNode(p.first);
        cur = cur->next;
        if( lists[p.second] ) {
          heap.push( {lists[p.second]->val, p.second} );
          lists[p.second] = lists[p.second]->next;
        }
      }
      return fake.next;
    }

};

int main() {
  return 0;
}
