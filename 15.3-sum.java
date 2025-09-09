/*
 * @lc app=leetcode id=15 lang=java
 *
 * [15] 3Sum
 */
import java.util.List;
import java.util.Map;
import java.util.Set;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.Comparator;
import java.util.HashMap;
import java.util.HashSet;

// @lc code=start
class Solution {
    // sort and two pointers
    // NOTE: this is a very talented method, which can have a formal proof
    public List<List<Integer>> threeSum(int[] nums) {
        // sorted from smaller to larger
        Arrays.sort(nums);
        if (nums[nums.length - 1] < 0) {
            return Collections.emptyList();
        }

        final List<List<Integer>> result = new ArrayList<>();
        for (int i = 0; i < nums.length - 2 && nums[i] <= 0;) {
            final int target = - nums[i];
            for (int j = i + 1, k = nums.length -1; j < k && nums[j] * 2 <= target && nums[k] * 2 >= target;) {
                final int sum = nums[j] + nums[k];
                if (sum == target) {
                    result.add(Arrays.asList(nums[i], nums[j], nums[k]));
                    for (int curr = nums[j++]; j < k && curr == nums[j]; ++j);
                    for (int curr = nums[k--]; j < k && curr == nums[k]; --k);
                } else if (sum > target) {
                    for (int curr = nums[k--]; j < k && curr == nums[k]; --k);
                } else {
                    for (int curr = nums[j++]; j < k && curr == nums[j]; ++j);
                }
            }
            // to next different i
            for (int curr = nums[i++]; i < nums.length - 2 && nums[i] <= 0 && curr == nums[i]; ++i);
        }

        return result;
    }

    // sort and binary search
    // the performance is 102ms, not good enough
    public List<List<Integer>> threeSumBinarySearch(int[] nums) {
        // sorted from smaller to larger
        Arrays.sort(nums);
        if (nums[nums.length - 1] < 0) {
            return Collections.emptyList();
        }

        final List<List<Integer>> result = new ArrayList<>();
        for (int i = 0; i < nums.length - 2 && nums[i] <= 0;) {
            for (int j = i + 1; j < nums.length - 1;) {
                final int wanted = - nums[i] - nums[j];
                if (wanted < 0) {
                    break;
                }
                if (Arrays.binarySearch(nums, j+1, nums.length, wanted) > 0) {
                    result.add(Arrays.asList(nums[i], nums[j], wanted));
                }

                for (int curr = nums[j++]; j < nums.length - 1 && curr == nums[j]; ++j);
            }
            // to next different num
            for (int curr = nums[i++]; i < nums.length - 2 && nums[i] <= 0 && curr == nums[i]; ++i);
        }

        return result;
    }

    // use hash map
    // bad performance: 2483ms
    public List<List<Integer>> threeSumHashMap(int[] nums) {
        final Map<Integer, Integer> counter = new HashMap<>();
        for (int num : nums) {
            counter.compute(num, (k, v) -> v == null ? 1 : v + 1);
        }

        // operation of this set is costly
        final Set<List<Integer>> result = new HashSet<>();
        for (int i = 0; i < nums.length - 2; ++i) {
            for (int j = i + 1; j < nums.length -1; ++j) {
                final int wanted = - nums[i] - nums[j];
                final Integer count = counter.get(wanted);
                if (count != null) {
                    if (nums[i] == nums[j]) {
                        if (wanted == nums[i]) {
                            if (count >= 3) {
                                addResult(result, nums[i], nums[j], wanted);
                            }
                        } else {
                            addResult(result, nums[i], nums[j], wanted);
                        }
                    } else {
                        if (nums[i] == wanted || nums[j] == wanted) {
                            if (count >= 2) {
                                addResult(result, nums[i], nums[j], wanted);
                            }
                        } else {
                            addResult(result, nums[i], nums[j], wanted);
                        }
                    }
                }
            }
        }

        return new ArrayList<>(result);
    }

    private static void addResult(Set<List<Integer>> result, int a, int b, int c) {
        final List<Integer> l = Arrays.asList(a, b, c);
        l.sort(Comparator.naturalOrder());
        result.add(l);
    }

    // brute force
    // note: Time Limit Exceeded
    public List<List<Integer>> threeSumBruteForce(int[] nums) {
        final Set<List<Integer>> result = new HashSet<>();
        for (int i = 0; i < nums.length - 2; ++i) {
            for (int j = i + 1; j < nums.length -1; ++j) {
                for (int k = j + 1; k < nums.length; ++k) {
                    if (nums[i] + nums[j] + nums[k] == 0) {
                        addResult(result, nums[i], nums[j], nums[k]);
                    }
                }
            }
        }

        return new ArrayList<>(result);
    }
}
// @lc code=end

