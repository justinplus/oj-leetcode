/*
 * @lc app=leetcode id=138 lang=java
 *
 * [138] Copy List with Random Pointer
 */

import java.util.IdentityHashMap;
// @lc code=start
// Definition for a Node.
class Node {
    int val;
    Node next;
    Node random;

    public Node(int val) {
        this.val = val;
        this.next = null;
        this.random = null;
    }
}

// TODO: inter weaving. Old List: A --> B --> C --> D 
//  InterWeaved List: A --> A' --> B --> B' --> C --> C' --> D --> D'
class Solution {
    public Node copyRandomList(Node head) {
        final Node dummy = new Node(0);
        
        final IdentityHashMap<Node, Node> map = new IdentityHashMap<>();
        Node node = dummy;
        Node h = head;
        while (h != null) {
            node.next = new Node(h.val);
            map.put(h, node.next);
            h = h.next;
            node = node.next;
        }

        h = head;
        node = dummy.next;
        while (h != null) {
            if (h.random != null) {
                node.random = map.get(h.random);
            }
            h = h.next;
            node = node.next;
        }

        return dummy.next;
    }
}
// @lc code=end

