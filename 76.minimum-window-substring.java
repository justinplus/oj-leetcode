/*
 * @lc app=leetcode id=76 lang=java
 *
 * [76] Minimum Window Substring
 */

import java.util.HashMap;
import java.util.Map;

// @lc code=start
class Solution {
    public String minWindow(String s, String t) {
        if (t.length() > s.length()) {
            return "";
        }

        // TODO: could improve using int[] to map
        final Map<Character, Integer> charCounter = new HashMap<>();
        for (int i = 0; i < t.length(); ++i) {
            charCounter.compute(t.charAt(i), (k, v) -> v == null ? 1 : v + 1);
        }

        int count = t.length();

        String minSubStr = null;
        for (int left = 0, right = 0; right < s.length(); ++right) {
            final Integer cnt0 = charCounter.computeIfPresent(s.charAt(right), (k, v) -> v - 1);
            if (cnt0 != null && cnt0 >= 0) {
                --count;
            }
            while (count == 0) {
                String candidate = s.substring(left, right + 1);
                if (minSubStr == null || candidate.length() < minSubStr.length()) {
                    minSubStr = candidate;
                }
                final char c = s.charAt(left++);
                final Integer cnt1 = charCounter.computeIfPresent(c, (k, v) -> v + 1);
                if (cnt1 != null && cnt1 > 0) {
                    ++count;
                }
            }
        }

        return minSubStr == null ? "" : minSubStr;
    }
}
// @lc code=end

