/*
 * @lc app=leetcode id=139 lang=java
 *
 * [139] Word Break
 */

import java.util.List;

// @lc code=start
class Solution {
    public boolean wordBreak(String s, List<String> wordDict) {
        final TrieNode root = new TrieNode();
        for (String w : wordDict) {
            addWord(root, w);
        }
        final Boolean[] computed = new Boolean[s.length()];
        return canBreak(0, s, root, computed);
    }

    private static boolean canBreak(int startIndex, String s, TrieNode root, Boolean[] computed) {
        if (computed[startIndex] != null) {
            return computed[startIndex];
        }
        TrieNode node = root;
        for (int i = startIndex, len = s.length(); i < len; ++i) {
            final char ch = s.charAt(i);
            node = node.children[ch - 'a'];
            if (node == null) {
                computed[startIndex] = false;
                return false;
            }
            if (node.isWord) {
                if (i == len - 1) {
                    computed[startIndex] = true;
                    return true;
                }
                if (i < len - 1 && canBreak(i + 1, s, root, computed)) {
                    computed[startIndex] = true;
                    return true;
                }
            }
        }
        computed[startIndex] = false;
        return false;
    }

    private static class TrieNode {
        private TrieNode[] children = new TrieNode['z' - 'a'];
        private boolean isWord = false;
    }

    private static void addWord(TrieNode root, String word) {
        TrieNode n = root;
        for (char ch : word.toCharArray()) {
            final TrieNode child = n.children[ch - 'a'];
            if (child == null) {
                final TrieNode newNode = new TrieNode();
                n.children[ch - 'a'] = newNode;
                n = newNode;
            } else {
                n = child;
            }
        }
        n.isWord = true;
    }
}
// @lc code=end
