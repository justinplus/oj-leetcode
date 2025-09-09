/*
 * @lc app=leetcode id=189 lang=java
 *
 * [189] Rotate Array
 */

import java.util.Arrays;

// @lc code=start
class Solution {
    public void rotate(int[] nums, int k) {
        rotateByJump(nums, k);
    }
    
    // use a temp array
    private static void rotateByTmpArray(int[] nums, int k) {
        final int[] copy = Arrays.copyOf(nums, nums.length);
        for (int i = 0; i < copy.length; i++) {
            // TODO: able to enhance the calculation of target index
            int target = (i + k) % copy.length;
            nums[target] = copy[i];
        }
    }

    private static void rotateBySwap(int[] nums, int k) {
        final int kk = k % nums.length;
        if (kk == 0) {
            return;
        }
        
        swapArray(nums, 0, nums.length);
        swapArray(nums, 0, kk);
        swapArray(nums, kk, nums.length);
    }

    /**
     * Swap all elements in the input array. 
     * From inclusive and to exclusive.
     */
    private static void swapArray(int[] nums, int from, int to) {
        final int cnt = (to - from)/2;
        for (int i = 0; i < cnt; i++) {
            int tmp = nums[from + i];
            nums[from + i] = nums[to - i -1];
            nums[to - i - 1] = tmp;
        }
    }

    private static void rotateByJump(int[] nums, int k) {
        final int kk = k % nums.length;
        if (kk == 0) {
            return;
        }

        final int m = getGreatestCommonDividor(nums.length, kk);
        for (int i = 0; i < m; ++i) {
            // final int cnt = nums.length / m;
            for (int j = i + kk; j != i; j = (j + kk) % nums.length) {
                int tmp = nums[i];
                nums[i] = nums[j];
                nums[j] = tmp;
            }
        }
    }

    private static int getGreatestCommonDividor(int a, int b) {
        int t;
        do {
            t = a % b;
            a = b;
            b = t;
        } while (t != 0);

        return a;
    }
}
// @lc code=end
