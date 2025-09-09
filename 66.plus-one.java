/*
 * @lc app=leetcode id=66 lang=java
 *
 * [66] Plus One
 */

// @lc code=start
class Solution {
    public int[] plusOne(int[] digits) {
        final int len = digits.length;

        int carry = 1;
        for (int i = len -1 ; i >= 0; --i) {
            final int digit = digits[i];
            if (digit + carry == 10) {
                digits[i] = 0;
                carry = 1;
            } else {
                digits[i] = digit + carry;
                carry = 0;
            }
        }
        if (carry == 0) {
            return digits;
        } else {
            final int[] nums = new int[len + 1];
            nums[0] = 1;
            System.arraycopy(digits, 0, nums, 1, len);
            return nums;
        }
    }
}
// @lc code=end

