/*
 * @lc app=leetcode id=28 lang=java
 *
 * [28] Find the Index of the First Occurrence in a String
 */

// @lc code=start
class Solution {
    // TODO: use KMP algorithm
    public int strStr(String haystack, String needle) {
        if (needle.length() > haystack.length()) {
            return -1;
        }
        int i = 0;

        for (; i <= haystack.length() - needle.length(); ++i) {
            int j = 0;
            for (; j < needle.length(); ++j) {
                if (haystack.charAt(i+j) != needle.charAt(j)) {
                    break;
                }
            }
            if (j == needle.length()) {
                return i;
            }
        }

        return -1;
    }
}
// @lc code=end

