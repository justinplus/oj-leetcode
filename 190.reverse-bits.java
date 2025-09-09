/*
 * @lc app=leetcode id=190 lang=java
 *
 * [190] Reverse Bits
 */

// @lc code=start
class Solution {
    private static final int MASK = 1;
    public int reverseBits(int n) {
        int result = 0;
        for (int i = 0; i < 32; ++i) {
            if ((n & (MASK << i)) != 0) {
                result |= MASK << (31 - i);
            }
        }
        return result;
    }
}
// @lc code=end

