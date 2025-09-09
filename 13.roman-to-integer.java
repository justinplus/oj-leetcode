/*
 * @lc app=leetcode id=13 lang=java
 *
 * [13] Roman to Integer
 */

import java.util.Map;

// @lc code=start
// TODO: use tire tree
class Solution {
    public int romanToInt(String s) {
        return romanToIntByPick2(s);
    }

    private static int romanToIntByPick2(String s) {
        Map<String, Integer> map = Map.ofEntries(
            // 1, 4, 5, 9
            Map.entry("I", 1), 
            Map.entry("IV", 4),
            Map.entry("V", 5),
            Map.entry("IX", 9),
            // 10, 40, 50, 90
            Map.entry("X", 10), 
            Map.entry("XL", 40),
            Map.entry("L", 50),
            Map.entry("XC", 90),
            // 100, 400, 500, 900
            Map.entry("C", 100), 
            Map.entry("CD", 400),
            Map.entry("D", 500),
            Map.entry("CM", 900),
            // 1000 
            Map.entry("M", 1000)
        );

        return romanToIntByMap0(s, map, 2);
    }

    private static int romanToIntByPick4(String s) {
        Map<String, Integer> map = Map.ofEntries(
            // 1 -> 9
            Map.entry("I", 1), 
            Map.entry("II", 2),
            Map.entry("III", 3),
            Map.entry("IV", 4),
            Map.entry("V", 5),
            Map.entry("VI", 6),
            Map.entry("VII", 7),
            Map.entry("VIII", 8),
            Map.entry("IX", 9),
            // 10 -> 90
            Map.entry("X", 10), 
            Map.entry("XX", 20),
            Map.entry("XXX", 30),
            Map.entry("XL", 40),
            Map.entry("L", 50),
            Map.entry("LX", 60),
            Map.entry("LXX", 70),
            Map.entry("LXXX", 80),
            Map.entry("XC", 90),
            // 100 -> 900
            Map.entry("C", 100), 
            Map.entry("CC", 200),
            Map.entry("CCC", 300),
            Map.entry("CD", 400),
            Map.entry("D", 500),
            Map.entry("DC", 600),
            Map.entry("DCC", 700),
            Map.entry("DCCC", 800),
            Map.entry("CM", 900),
            // 1000 -> 3000
            Map.entry("M", 1000),
            Map.entry("MM", 2000),
            Map.entry("MMM", 3000)
        );

        return romanToIntByMap0(s, map, 4);
    }

    private static int romanToIntByMap0(String s, Map<String, Integer> map, int maxLen) {
        int result = 0;
        for(int i = 0; i < s.length();) {;
            for (int len = Math.min(4, s.length() - i); len > 0; --len) {
                final Integer num = map.get(s.substring(i, i + len));
                if (num != null) {
                    result += num;
                    i += len;
                    break;
                }
            }
        }

        return result;
    }
}
// @lc code=end

