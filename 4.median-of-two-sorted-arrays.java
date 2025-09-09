/*
 * @lc app=leetcode id=4 lang=java
 *
 * [4] Median of Two Sorted Arrays
 */

// @lc code=start
// TODO: review
class Solution {
    public double findMedianSortedArrays(int[] nums1, int[] nums2) {
        final int len1 = nums1.length, len2 = nums2.length;

        int left1 = Math.max(-1, (len1 + len2 - 1) / 2 - len2);
        int right1 = Math.min(nums1.length - 1, (len1 + len2 - 1) / 2);
        while (left1 <= right1) {
            final int partition1 = (left1 + right1) / 2;
            final int partition2 = (len1 + len2 - 1) / 2 - partition1 - 1;

            final int maxLeft1, minRight1;
            if (partition1 == -1) {
                maxLeft1 = Integer.MIN_VALUE;
                minRight1 = len1 == 0 ? Integer.MAX_VALUE : nums1[0];
            } else if (partition1 == nums1.length - 1) {
                maxLeft1 = nums1[partition1];
                minRight1 = Integer.MAX_VALUE;
            } else {
                maxLeft1 = nums1[partition1];
                minRight1 = nums1[partition1 + 1];
            }

            final int maxLeft2, minRight2;
            if (partition2 == -1) {
                maxLeft2 = Integer.MIN_VALUE;
                minRight2 = len2 == 0 ? Integer.MAX_VALUE : nums2[0];
            } else if (partition2 == nums2.length - 1) {
                maxLeft2 = nums2[partition2];
                minRight2 = Integer.MAX_VALUE;
            } else {
                maxLeft2 = nums2[partition2];
                minRight2 = nums2[partition2 + 1];
            }

            if (maxLeft1 > minRight2) {
                right1 = partition1 - 1;
            } else if (maxLeft2 > minRight1) {
                left1 = partition1 + 1;
            } else {
                if ((len1 + len2) % 2 == 0) {
                    return ((double) (Math.max(maxLeft1, maxLeft2) + Math.min(minRight1, minRight2))) / 2;
                } else {
                    return Math.max(maxLeft1, maxLeft2);
                }
            }
        }
        throw new AssertionError("Should never arrive here");
    }
}
// @lc code=end
