/*
 * @lc app=leetcode id=17 lang=java
 *
 * [17] Letter Combinations of a Phone Number
 */

import java.util.ArrayList;
import java.util.List;

// @lc code=start
class Solution {
    private static final char[][] MAPPING = new char[][] {
            {}, // 0
            {}, // 1
            { 'a', 'b', 'c' }, // 2
            { 'd', 'e', 'f' }, // 3
            { 'g', 'h', 'i' }, // 4
            { 'j', 'k', 'l' }, // 5
            { 'm', 'n', 'o' }, // 6
            { 'p', 'q', 'r', 's' }, // 7
            { 't', 'u', 'v' }, // 8
            { 'w', 'x', 'y', 'z' }, // 9
    };

    // 0ms
    public List<String> letterCombinations(String digits) {
        if (digits.isEmpty()) {
            return List.of();
        }
        final List<String> result = new ArrayList<>();
        final char[] charArr = new char[digits.length()];
        fillChar(digits, charArr, 0, result);
        return result;
    }

    private static void fillChar(String digits, char[] charArr, int index, List<String> result) {
        if (index == digits.length()) {
            result.add(String.valueOf(charArr));
        } else {
            for (char ch : MAPPING[digits.charAt(index) - '0']) {
                charArr[index] = ch;
                fillChar(digits, charArr, index + 1, result);
            }
        }
    }

    // NOTE: bad performance 5ms
    public List<String> letterCombinations2(String digits) {
        return letterCombinations(digits, 0);
    }

    private static List<String> letterCombinations(String digits, int index) {
        final List<String> result = new ArrayList<>();
        if (index == digits.length() - 1) {
            for (char ch : MAPPING[digits.charAt(index) - '0']) {
                result.add(String.valueOf(ch));
            }
        } else if (index < digits.length() - 1) {
            for (char ch : MAPPING[digits.charAt(index) - '0']) {
                for (String str : letterCombinations(digits, index + 1)) {
                    result.add(ch + str);
                }
            }
        }

        return result;
    }
}
// @lc code=end
