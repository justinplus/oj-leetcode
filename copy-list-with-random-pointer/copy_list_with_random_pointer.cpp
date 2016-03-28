#include <iostream>
#include <unordered_map>
using namespace std;
/**
 * Definition for singly-linked list with a random pointer.
 */
struct RandomListNode {
  int label;
  RandomListNode *next, *random;
  RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
};

class Solution {
  using Hash = unordered_map<RandomListNode*, RandomListNode*>;
  public:
    RandomListNode *copyRandomList(RandomListNode *head) {
      Hash hsh;
      RandomListNode dummy(0);
      RandomListNode *l = &dummy, *nd = l, *h = head;

      while( h ) { 
        nd->next = new RandomListNode(h->label);
        nd = nd->next;
        hsh.insert({h, nd});
        h = h->next;
      }

      nd = l->next; h = head;
      while( h ) {
        nd->random = head->random ? hsh[h->random] : nullptr;
        nd = nd->next;
        h = h->next;
      }

      return l->next;
    }
};

int main() {
  RandomListNode *l = new RandomListNode(0);
  l->next = new RandomListNode(1);
  l->next->next = new RandomListNode(2);
  l->next->next->next = new RandomListNode(3);

  l->random = l->next->next; // 2
  l->next->random = l->next; // 1
  l->next->next->next->random = l; // 0

  Solution s;
  auto nl = s.copyRandomList(l);
  for(auto nd = nl; nd; nd = nd->next ) cout<<nd->label<<' ';
  cout<<endl;
  for(auto nd = nl; nd; nd = nd->next ) 
    if( nd->random )
      cout<<nd->random->label<<' ';
    else
      cout<<'-'<<' ';

  
  return 0;
}
