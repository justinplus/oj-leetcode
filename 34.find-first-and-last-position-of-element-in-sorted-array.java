/*
 * @lc app=leetcode id=34 lang=java
 *
 * [34] Find First and Last Position of Element in Sorted Array
 */

// @lc code=start
class Solution {
    public int[] searchRange(int[] nums, int target) {
        final int pivot = searchAny(nums, target);
        if (pivot == -1) {
            return new int[] { -1, -1 };
        }

        return new int[] { searchLeftmost(nums, pivot), searchRightmost(nums, pivot) };
    }

    private static int searchAny(int[] nums, int target) {
        int left = 0, right = nums.length - 1;
        while (left <= right) {
            final int med = (left + right) / 2;
            final int val = nums[med];

            if (target == val) {
                return med;
            } else if (target > val) {
                left = med + 1;
            } else {
                right = med - 1;
            }
        }
        return -1;
    }

    private static int searchLeftmost(int[] nums, int pivot) {
        int left = 0, right = pivot;
        while (left < right) {
            final int med = (left + right) / 2;
            final int val = nums[med];

            if (nums[right] > val) {
                left = med + 1;
            } else {
                right = med;
            }
        }
        return right;
    }

    public static int searchRightmost(int[] nums, int pivot) {
        int left = pivot, right = nums.length - 1;
        while (left < right) {
            final int med = (left + right) % 2 == 0 ? (left + right) / 2 : (left + right) / 2 + 1;
            final int val = nums[med];

            if (nums[left] < val) {
                right = med - 1;
            } else {
                left = med;
            }
        }
        return left;
    }
}
// @lc code=end
