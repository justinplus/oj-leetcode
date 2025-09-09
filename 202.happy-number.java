/*
 * @lc app=leetcode id=202 lang=java
 *
 * [202] Happy Number
 */

import java.util.HashSet;
import java.util.Set;

// @lc code=start
class Solution {
    public boolean isHappy(int n) {
        final Set<Integer> set = new HashSet<>();

        while(true) {
            set.add(n);
            final int next = digitSquareSum(n);
            if (next == 1) {
                return true;
            }

            if (set.contains(next)) {
                return false;
            }

            n = next;
        }
    }

    private static int digitSquareSum(int n) {
        int sum = 0;
        while (n != 0) {
            sum += (n % 10) * (n % 10);
            n /= 10;
        }
        return sum;
    }
}
// @lc code=end

