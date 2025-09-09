/*
 * @lc app=leetcode id=212 lang=java
 *
 * [212] Word Search II
 */
import java.util.ArrayList;
import java.util.List;

// @lc code=start
class Solution {
    public List<String> findWords(char[][] board, String[] words) {
        final int m = board.length, n = board[0].length;
        final Trie trie = new Trie();
        for (String word : words) {
            trie.addWord(word);
        }

        // NOTE: Removeing set for deduplication improves performance from 210ms to 155ms
        final List<String> results = new ArrayList<>();
        final boolean[][] visted = new boolean[m][n];
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                findWords(results, board, visted, i, j, m, n, trie.newMatcher());
            }
            // early stop
            if (results.size() == words.length) {
                return results;
            }
        }

        return results;
    }

    public void findWords(List<String> results, char[][] board, boolean[][] visited,
            int i, int j, int m, int n, Trie.Matcher matcher) {
        visited[i][j] = true;
        if (matcher.matchNext(board[i][j])) {
            if (!matcher.isWordRead() && matcher.getWord() != null) {
                results.add(matcher.getWord());
            }

            if (i > 0 && !visited[i - 1][j]) {
                findWords(results, board, visited, i - 1, j, m, n, matcher.copy());
            }
            if (i + 1 < m && !visited[i + 1][j]) {
                findWords(results, board, visited, i + 1, j, m, n, matcher.copy());
            }
            if (j > 0 && !visited[i][j - 1]) {
                findWords(results, board, visited, i, j - 1, m, n, matcher.copy());
            }
            if (j + 1 < n && !visited[i][j + 1]) {
                findWords(results, board, visited, i, j + 1, m, n, matcher.copy());
            }
        }
        // NOTE: need to reset
        visited[i][j] = false;
    }

    private static class Trie {
        private static final char LOWERCASE_A = 'a';
        private static final char LOWERCASE_Z = 'z';

        // using linked node other than array improves from 245ms to 210ms
        private final Node root;

        private static class Node {
            // NOTE: removing string builder and store word in node improves from 1094ms to 245ms
            String word = null;
            boolean isWordRead = false;
            // int[] edges = new int[LOWERCASE_Z - LOWERCASE_A + 1];
            Node[] next = new Node[LOWERCASE_Z - LOWERCASE_A + 1];
        }

        public class Matcher {
            private Node node;

            private Matcher() {
                this.node = root;
            }

            private Matcher(Node node) {
                this.node = node;
            }

            public boolean matchNext(char ch) {
                node = node.next[ch - LOWERCASE_A];
                return node != null;
            }

            public String getWord() {
                node.isWordRead = true;
                return node.word;
            }

            public boolean isWordRead() {
                return node.isWordRead;
            }

            public Matcher copy() {
                return new Matcher(this.node);
            }
        }

        public Trie() {
            this.root = new Node();
        }

        public void addWord(String word) {
            Node n = root;
            for (char ch : word.toCharArray()) {
                final int index = ch - LOWERCASE_A;
                final Node next = n.next[index];

                if (next == null) {
                    final Node newNode = new Node();
                    n.next[index] = newNode;
                    n = newNode;
                } else {
                    n = next;
                }
            }
            n.word = word;
        }

        public Matcher newMatcher() {
            return new Matcher();
        }
    }
}
// @lc code=end
