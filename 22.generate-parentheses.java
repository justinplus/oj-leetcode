/*
 * @lc app=leetcode id=22 lang=java
 *
 * [22] Generate Parentheses
 */

import java.util.ArrayList;
import java.util.List;

// @lc code=start
class Solution {
    public List<String> generateParenthesis(int n) {
        final char[] chars = new char[2 * n];
        final List<String> result = new ArrayList<>();
        generate(0, 0, 0, chars, result);

        return result;
    }

    private static void generate(int leftCnt, int rightCnt, int index, char[] chars, List<String> result) {
        if (leftCnt + rightCnt == chars.length) {
            result.add(String.valueOf(chars));
        } else {
            if (leftCnt < chars.length / 2) {
                leftCnt++;
                chars[index] = '(';
                generate(leftCnt, rightCnt, index + 1, chars, result);
                leftCnt--;
            }
            if (leftCnt > rightCnt) {
                rightCnt++;
                chars[index] = ')';
                generate(leftCnt, rightCnt, index + 1, chars, result);
                rightCnt--;
            }
        }
    }
}
// @lc code=end
