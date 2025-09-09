/*
 * @lc app=leetcode id=67 lang=java
 *
 * [67] Add Binary
 */

// @lc code=start
class Solution {
    public String addBinary(String a, String b) {
        final int minLen = Math.min(a.length(), b.length());
        final StringBuilder sb = new StringBuilder();
        final int mask = 1;

        int carry = 0;
        for (int i = 0, lenA = a.length() - 1, lenB = b.length() - 1; i < minLen; ++i) {
            final int bitA = a.charAt(lenA - i) - '0';
            final int bitB = b.charAt(lenB - i) - '0';

            int result = bitA + bitB + carry;
            sb.append(result & mask);
            carry = result >> 1;
        }

        final String remained = a.length() > minLen ? a : b;
        for (int j = remained.length() - minLen - 1; j >= 0; --j) {
            final int bit = remained.charAt(j) - '0';
            int result = bit + carry;
            sb.append(result & mask);
            carry = result >> 1;
        }

        if (carry == 1) {
            sb.append('1');
        }

        return sb.reverse().toString();
    }
}
// @lc code=end

