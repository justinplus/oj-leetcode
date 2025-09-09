/*
 * @lc app=leetcode id=238 lang=java
 *
 * [238] Product of Array Except Self
 */

// @lc code=start
class Solution {
    public int[] productExceptSelf(int[] nums) {
        final int[] result = new int[nums.length];
        
        result[nums.length - 1] = 1;
        for (int i = nums.length - 1; i > 0; --i) {
            result[i - 1] = result[i] * nums[i];
        }

        int prefixProduct = 1;
        for (int i = 0; i < nums.length; ++i) {
            result[i] *= prefixProduct;
            prefixProduct *= nums[i];
        }

        return result;
    }
}
// @lc code=end

