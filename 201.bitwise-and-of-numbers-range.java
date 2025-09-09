/*
 * @lc app=leetcode id=201 lang=java
 *
 * [201] Bitwise AND of Numbers Range
 */

// @lc code=start
class Solution {
    public int rangeBitwiseAnd(int left, int right) {
        int result = 0;
        int mask = 1 << 31;
        for (int i = 0; i < 32; ++i, mask >>>= 1) {
            final boolean bitLeft = (left & mask) != 0;
            final boolean bitRight = (right & mask) != 0;
            if (bitRight) {
                if (bitLeft) {
                    result |= mask;
                } else {
                    break;
                }
            }
        }
        return result;
    }
}
// @lc code=end

