class Solution {
    public int search(int[] nums, int target) {
        final int len = nums.length;
        final int pivot = getPivotIndex(nums);

        int left = 0, right = nums.length - 1;
        while (left <= right) {
            final int med = (left + right) / 2;
            final int shiftedMed = (med + pivot + 1) % len;
            final int val = nums[shiftedMed];

            if (target == val) {
                return shiftedMed;
            } else if (target > val) {
                left = med + 1;
            } else {
                right = med - 1;
            }
        }
        return -1;
    }

    private static int getPivotIndex(int[] nums) {
        int left = 0, right = nums.length - 1;
        while (left < right) {
            if (nums[left] < nums[right]) {
                return right;
            }

            final int med = (left + right) / 2;
            final int val = nums[med];
            // NOTE: cornor case [3, 1]
            if (nums[left] == val) {
                right = med;
            } else if (nums[left] > val) {
                right = med - 1;
            } else {
                left = med;
            }
        }
        return right;
    }
}