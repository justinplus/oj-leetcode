/*
 * @lc app=leetcode id=135 lang=java
 *
 * [135] Candy
 */

// @lc code=start
class Solution {
    public int candy(int[] ratings) {
        int prevPeakIndex = -1;
        int sum = 1;
        for (int i = 1, prevCandy = 1, len = ratings.length; i < len; ++i) {
            final int prev = ratings[i - 1], curr = ratings[i];
            if (prev > curr) {
                if (prevPeakIndex == -1) {
                    prevPeakIndex = i - 1;
                }
                sum += --prevCandy;
            } else {
                if (prevPeakIndex != -1) {
                    if (prevCandy <= 0) {
                        sum += (i - prevPeakIndex) * (1 - prevCandy);
                    } else {
                        sum -= (i - prevPeakIndex - 1) * (prevCandy - 1);
                    }
                }
                prevPeakIndex = -1;
                prevCandy = 1;
                if (prev == curr) {
                    sum += prevCandy;
                } else {
                    sum += ++prevCandy;
                }
            }
        }
        return sum;
    }
}
// @lc code=end
