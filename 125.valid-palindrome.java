/*
 * @lc app=leetcode id=125 lang=java
 *
 * [125] Valid Palindrome
 */

// @lc code=start
class Solution {
    public boolean isPalindrome(String s) {
        final StringBuilder sb = new StringBuilder();
        for (int i = 0; i < s.length(); ++i) {
            final char c = s.charAt(i);
            if (Character.isLetterOrDigit(c)) {
                sb.append(Character.toLowerCase(c));
            }
        }

        final String converted = sb.toString();
        for (int i = 0, j = converted.length() - 1; i < converted.length(); ++i, --j) {
            if (converted.charAt(i) != converted.charAt(j)) {
                return false;
            }
        }

        return true;
    }
}
// @lc code=end

