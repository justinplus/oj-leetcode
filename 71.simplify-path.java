/*
 * @lc app=leetcode id=71 lang=java
 *
 * [71] Simplify Path
 */

import java.util.Deque;
import java.util.LinkedList;
import java.util.stream.Collectors;

// @lc code=start
class Solution {
    private static final char SLASH = '/';
    private static String CURR_DIR = ".";
    private static String PRE_DIR = "..";

    public String simplifyPath(String path) {
        final Deque<String> queue = new LinkedList<>();
        final Tokenier tokenier = new Tokenier(path);

        while(tokenier.hasNextToken()) {
            final String token = tokenier.nextToken();
            if (token.equals(PRE_DIR)) {
                if (!queue.isEmpty()) {
                    queue.removeLast();
                }
            } else if (!token.equals(CURR_DIR)) {
                queue.add(token);
            }
        }

        final String slash = Character.toString(SLASH);
        return queue.stream().collect(Collectors.joining(slash, slash, ""));
    }

    private static class Tokenier {
        private final String str;
        private int index;

        public Tokenier(String str) {
            this.str = str;

            for (index = 0; index < str.length() && str.charAt(index) == SLASH; ++index);
        }

        public boolean hasNextToken() {
            return index < str.length();

        }

        public String nextToken() {
            if (!hasNextToken()) {
                return null;
            }

            int next = index + 1;
            for (; next < str.length(); ++next) {
                if (str.charAt(next) == SLASH) {
                    break;
                }
            }

            String token = str.substring(index, next);

            for (index = next; index < str.length() && str.charAt(index) == SLASH; ++index);

            return token;
        }
    }
}
// @lc code=end

