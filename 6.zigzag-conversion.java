/*
 * @lc app=leetcode id=6 lang=java
 *
 * [6] Zigzag Conversion
 */

// @lc code=start
class Solution {
    public String convert(String s, int numRows) {
        final StringBuilder[] sbArr = new StringBuilder[numRows];
        for (int i = 0; i < numRows; ++i) {
            sbArr[i] = new StringBuilder();
        }

        for (int i = 0; i < s.length();) {
            for (int j = 0; j < numRows && i < s.length(); ++i, ++j) {
                sbArr[j].append(s.charAt(i));
            }
            
            for (int j = 0; j < numRows - 2 && i < s.length(); ++i, ++j) {
                sbArr[numRows - 2 - j].append(s.charAt(i));
            }
        }

        final StringBuilder result = new StringBuilder();
        for (StringBuilder sb : sbArr) {
            result.append(sb);
        }
        return result.toString();
    }
}
// @lc code=end