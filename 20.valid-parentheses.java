/*
 * @lc app=leetcode id=20 lang=java
 *
 * [20] Valid Parentheses
 */

import java.util.Deque;
import java.util.LinkedList;

// @lc code=start
class Solution {
    public boolean isValid(String s) {
        final Deque<Character> stack = new LinkedList<>();

        for (int i = 0; i < s.length(); ++i) {
            final char c = s.charAt(i);

            if (c == '(' || c == '[' || c == '{') {
                stack.addLast(c);
            } else {
                Character last = stack.peekLast();
                if (last == null) {
                    return false;
                }
                if (c == ')' && last != '(' || c == ']' && last != '['
                        || c == '}' && last != '{') {
                    return false;
                }
                stack.removeLast();
            }
        }

        return stack.isEmpty();
    }
}
// @lc code=end

