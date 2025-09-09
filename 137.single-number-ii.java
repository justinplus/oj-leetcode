/*
 * @lc app=leetcode id=137 lang=java
 *
 * [137] Single Number II
 */

// @lc code=start
// TODO: review
class Solution {
    public int singleNumber(int[] nums) {
        int ones = 0, twos = 0;
        for (int num : nums) {
            ones = (ones ^ num) & ~twos;
            twos = (twos ^ num) & ~ones;
        }
        return ones;
    }

    public int singleNumberBitCount(int[] nums) {
        int result = 0;
        for (int i = 31, mask = 1; i >= 0; --i, mask <<= 1) {
            int count = 0;
            for (int num : nums) {
                if ((num & mask) != 0) {
                    ++count;
                }
            }
            if (count % 3 != 0) {
                result |= mask;
            }
        }
        return result;
    }
}
// @lc code=end
