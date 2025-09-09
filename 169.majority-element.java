/*
 * @lc app=leetcode id=169 lang=java
 *
 * [169] Majority Element
 */

import java.util.Arrays;
import java.util.Comparator;
import java.util.HashMap;
import java.util.Map;
import java.util.Random;

// @lc code=start
class Solution {
    private static Random random = new Random();

    public int majorityElement(int[] nums) {
        return majorityElementByMooreVoting(nums);
    }

    public static int majorityElementByHashTable(int[] nums) {
        final Map<Integer, Integer> counter = new HashMap<>();
        for (int num : nums) {
            counter.compute(num, (k, v) -> v == null? 1 : v + 1);
        }
        return counter.entrySet().stream()
                .max(Comparator.comparingInt(Map.Entry::getValue))
                .map(Map.Entry::getKey).get();
    }

    public static int majorityElementBySorting(int[] nums) {
        Arrays.sort(nums);
        return nums[nums.length / 2];
    }

    public static int majorityElementByDivideConquer(int[] nums) {
        final int targetIndex = nums.length / 2;
        int from = 0, to = nums.length;

        while (true) {
            final int pivot = placePivot(nums, from, to);
            if (pivot > targetIndex) {
                to = pivot;
            } else if (pivot < targetIndex) {
                from = pivot + 1;
            } else {
                break;
            }
        } 

        return nums[targetIndex];
    }

    public static int placePivot(int[] nums, int from, int to) {
        swap(nums, from, random.nextInt(from, to));
        int f = from + 1, t = to - 1;
        while (f <= t) {
            if (nums[f - 1] >= nums[f]) {
                swap(nums, f - 1, f);
                f++;
            } else {
                swap(nums, f, t);
                t--;
            }
        }

        return f - 1;
    }

    public static void swap(int[] nums, int source, int target) {
        final int tmp = nums[source];
        nums[source] = nums[target];
        nums[target] = tmp;
    }

    public static int majorityElementByMooreVoting(int[] nums) {
        int count = 0;
        int candidate = Integer.MAX_VALUE;

        for (int num : nums) {
            if (count == 0) {
                candidate = num;
                count++;
            } else {
                if (candidate == num) {
                    count++;
                } else {
                    count--;
                }
            }
        }

        return candidate;
    }
}
// @lc code=end
