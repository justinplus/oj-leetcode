/*
 * @lc app=leetcode id=290 lang=java
 *
 * [290] Word Pattern
 */

import java.util.HashMap;
import java.util.HashSet;
import java.util.Map;
import java.util.Set;

// @lc code=start
class Solution {
    public boolean wordPattern(String pattern, String s) {
        final Set<String> set = new HashSet<>();
        final Map<Character, String> map = new HashMap<>();

        final String[] tokens = s.split(" ");
        if (tokens.length != pattern.length()) {
            return false;
        }

        for (int i = 0, len = pattern.length(); i < len; ++i) {
            final char k = pattern.charAt(i);
            final String v = tokens[i];
            final String vv = map.get(k);

            if (vv == null) {
                map.put(k, v);
                if (set.add(v) == false) {
                    return false;
                }
            } else if (!v.equals(vv)) {
                return false;
            }
        }

        return true;
    }
}
// @lc code=end

