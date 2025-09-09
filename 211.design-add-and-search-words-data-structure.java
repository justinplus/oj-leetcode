/*
 * @lc app=leetcode id=211 lang=java
 *
 * [211] Design Add and Search Words Data Structure
 */

import java.util.ArrayList;
import java.util.List;
import java.util.stream.IntStream;

// @lc code=start
// TODO: 194ms beats 47.35% improve performance
class WordDictionary {
    private static final char LOWERCASE_A = 'a';
    private static final char LOWERCASE_Z = 'z';
    private static final int EDGE_CNT_PER_NODE = LOWERCASE_Z - LOWERCASE_A + 1;

    private final List<Node> tree;

    private static class Node {
        boolean isWord = false;
        int[] edges = new int[EDGE_CNT_PER_NODE];
    }

    public WordDictionary() {
       this.tree = new ArrayList<>(100);
       tree.add(new Node());
    }
    
    public void addWord(String word) {
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
        return search(tree.get(0), 0, word);
    }

    public boolean search(Node node, int index, String word) {
        final char ch = word.charAt(index);
        if (ch == '.') {
            if (index == word.length() - 1) {
                return IntStream.of(node.edges)
                        .anyMatch(n -> n != 0 && tree.get(n).isWord);
            }
            for (int next : node.edges) {
                if (next != 0 && search(tree.get(next), index + 1, word)) {
                    return true;
                }
            }
            return false;
        } else {
            final int next = node.edges[ch - LOWERCASE_A];
            if (next == 0) {
                return false;
            }
            final Node nextNode = tree.get(next);
            if (index == word.length() - 1) {
                return nextNode.isWord;
            }
            return search(nextNode, index + 1, word);
        }
    }
}

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary obj = new WordDictionary();
 * obj.addWord(word);
 * boolean param_2 = obj.search(word);
 */
// @lc code=end

