/*
 * @lc app=leetcode id=191 lang=java
 *
 * [191] Number of 1 Bits
 */

// @lc code=start
class Solution {
    public int hammingWeight(int n) {
        final int mask = 1;
        int cnt = 0;
        for (int i = 0; i < 32; ++i) {
            if ((n & (mask << i)) != 0) {
                ++cnt;
            }
        }
        return cnt;
    }
}
// @lc code=end

