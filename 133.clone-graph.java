/*
 * @lc app=leetcode id=133 lang=java
 *
 * [133] Clone Graph
 */

import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.Deque;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

// Definition for a Node.
class Node {
    public int val;
    public List<Node> neighbors;
    public Node() {
        val = 0;
        neighbors = new ArrayList<Node>();
    }
    public Node(int _val) {
        val = _val;
        neighbors = new ArrayList<Node>();
    }
    public Node(int _val, ArrayList<Node> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
}

// @lc code=start
class Solution {
    public Node cloneGraph(Node node) {
        if (node == null) {
            return null;
        }
        final Map<Integer, Node> nodes = new HashMap<>();
        final Node newGraph = new Node(node.val);
        final Deque<Node> q0 = new ArrayDeque<>(100);
        q0.addLast(newGraph);
        nodes.put(newGraph.val, newGraph);
        final Deque<Node> q1 = new ArrayDeque<>(100);
        q1.addLast(node);

        while (!q0.isEmpty()) {
            final Node n0 = q0.removeFirst();
            final Node n1 = q1.removeFirst();
            for (Node neighbor1 : n1.neighbors) {
                final Node neignbor0 = nodes.get(neighbor1.val);
                if (neignbor0 == null) {
                    Node neighbor00 = new Node(neighbor1.val);
                    nodes.put(neighbor00.val, neighbor00);
                    n0.neighbors.add(neighbor00);
                    q0.add(neighbor00);
                    q1.add(neighbor1);
                } else {
                    n0.neighbors.add(neignbor0);
                }
            }
        }
        return newGraph;
    }
}
// @lc code=end

