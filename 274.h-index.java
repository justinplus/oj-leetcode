/*
 * @lc app=leetcode id=274 lang=java
 *
 * [274] H-Index
 */
import java.util.Arrays;

// @lc code=start
class Solution {
    public int hIndex(int[] citations) {
        Arrays.sort(citations);

        for (int hIndex = 1; hIndex <= citations.length; ++hIndex) {
            final int i = citations.length - hIndex;
            if (hIndex > citations[i]) {
                return hIndex - 1;
            }
        }

        return citations.length;
    }
}
// @lc code=end

