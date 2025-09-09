/*
 * @lc app=leetcode id=12 lang=java
 *
 * [12] Integer to Roman
 */
import java.util.List;

// @lc code=start
class Solution {
    public String intToRoman(int num) {
        List<List<String>> mappings = List.of(
                List.of("", "I", "II", "III", "IV",
                        "V", "VI", "VII", "VIII", "IX"),
                List.of("", "X", "XX", "XXX", "XL",
                        "L", "LX", "LXX", "LXXX", "XC"),
                List.of("", "C", "CC", "CCC", "CD",
                        "D", "DC", "DCC", "DCCC", "CM"),
                List.of("", "M", "MM", "MMM"));
                
        String s = "";
        int pos = 0;
        do {
            int digit = num % 10;
            s = mappings.get(pos).get(digit) + s;
            pos++;
            num /= 10;
        } while (num != 0);

        return s;
    }
}
// @lc code=end
