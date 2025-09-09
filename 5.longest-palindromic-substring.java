/*
 * @lc app=leetcode id=5 lang=java
 *
 * [5] Longest Palindromic Substring
 */

import java.util.Arrays;

// @lc code=start
// TODO: 44ms beats 38.62% - improve performance
// TODO: write 0(n) solution
class Solution {
    public static String longestPalindrome(String s) {
        final char[] charArr = s.toCharArray();
        final int len = charArr.length;
        boolean[] prev2 = new boolean[charArr.length];
        boolean[] prev1 = new boolean[charArr.length];
        boolean[] curr = new boolean[charArr.length];

        int begin = 0, subStrlen = 1;
        Arrays.fill(prev2, true);
        for (int i = 0; i <= len - 2; ++i) {
            if (charArr[i] == charArr[i + 1]) {
                prev1[i] = true;
                begin = i;
                subStrlen = 2;
            }
        }

        for (int step = 3; step <= len; ++step) {
            for (int i = 0; i <= len - step; ++i) {
                if (prev2[i + 1] && charArr[i] == charArr[i + step - 1]) {
                    curr[i] = true;
                    begin = i;
                    subStrlen = step;
                } else {
                    curr[i] = false;
                }
            }
            final boolean[] tmp = prev2;
            prev2 = prev1;
            prev1 = curr;
            curr = tmp;
        }

        return s.substring(begin, begin + subStrlen);
    }
}
// @lc code=end

