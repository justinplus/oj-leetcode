/*
 * @lc app=leetcode id=3 lang=java
 *
 * [3] Longest Substring Without Repeating Characters
 */

import java.util.HashSet;
import java.util.Set;
// @lc code=start
class Solution {
    public int lengthOfLongestSubstring(String s) {
        Set<Character> set = new HashSet<>();
        int maxLen = 0;

        for (int left = -1, right = 0, len = s.length(); right < len; ++right) {
            final char c = s.charAt(right);
            if (set.add(c)) {
                maxLen = Math.max(maxLen, right - left);
                if (maxLen == len) {
                    return len;
                }
            } else {
                char cc;
                while ((cc = s.charAt(++left)) != c) {
                    set.remove(cc);
                }
            }
        }

        return maxLen;
    }
}
// @lc code=end

