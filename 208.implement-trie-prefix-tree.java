/*
 * @lc app=leetcode id=208 lang=java
 *
 * [208] Implement Trie (Prefix Tree)
 */

import java.util.ArrayList;
import java.util.List;

// @lc code=start
class Trie {
    private static final char LOWERCASE_A = 'a';
    private static final char LOWERCASE_Z = 'z';
    private static final int EDGE_CNT_PER_NODE = LOWERCASE_Z - LOWERCASE_A + 1;

    private final List<Node> tree;

    private static class Node {
        boolean isWord = false;
        int[] edges = new int[EDGE_CNT_PER_NODE];
    }

    public Trie() {
        this.tree = new ArrayList<>(1000);
        tree.add(new Node());
    }
    
    public void insert(String word) {
        int node = 0;
        for (char ch : word.toCharArray()) {
            final int edge = ch - LOWERCASE_A;
            final int next = tree.get(node).edges[edge];
            if (next == 0) {
                tree.get(node).edges[edge] = tree.size();
                node = tree.size();
                tree.add(new Node());
            } else {
                node = next;
            }
        }
        tree.get(node).isWord = true;
    }
    
    public boolean search(String word) {
        final Node last = getTheLastNode(word);
        return last != null && last.isWord;
    }
    
    public boolean startsWith(String prefix) {
        return getTheLastNode(prefix) != null;
    }
    
    private Node getTheLastNode(String str) {
        int node = 0;
        for (char ch : str.toCharArray()) {
            final int edge = ch - LOWERCASE_A;
            final int next = tree.get(node).edges[edge];
            if (next == 0) {
                return null;
            } 
            node = next;
        }
        return tree.get(node);
    }
}

/**
 * Your Trie object will be instantiated and called as such:
 * Trie obj = new Trie();
 * obj.insert(word);
 * boolean param_2 = obj.search(word);
 * boolean param_3 = obj.startsWith(prefix);
 */
// @lc code=end

