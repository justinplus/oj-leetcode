/*
 * @lc app=leetcode id=383 lang=java
 *
 * [383] Ransom Note
 */

import java.util.Arrays;
import java.util.HashMap;
import java.util.Map;

// @lc code=start
class Solution {
    // NOTE: use int array as hash map
    public boolean canConstruct(String ransomNote, String magazine) {
        final int[] counter = new int['z' - 'a' + 1];
        Arrays.fill(counter, 0);

        magazine.chars().forEach(c -> ++counter[c - 'a']);
        for (int i = 0, len = ransomNote.length(); i < len; ++i) {
            final char c = ransomNote.charAt(i);
            if (counter[c - 'a'] == 0) {
                return false;
            } else {
                --counter[c - 'a'];
            }
        }
        return true;
    }

    public boolean canConstructHashMap(String ransomNote, String magazine) {
        final Map<Character, MutableInt> counter = new HashMap<>();
        for (int i = 0; i < magazine.length(); ++i) {
            final char c = magazine.charAt(i);
            counter.compute(c, (k, v) -> v == null ? new MutableInt().inc() : v.inc());
        }

        for (int i = 0; i < ransomNote.length(); ++i) {
            final char c = ransomNote.charAt(i);
            MutableInt count = counter.get(c);
            if (null == count || count.get() == 0) {
                return false;
            } else {
                count.dec();
            }
        }

        return true;
    }

    private final class MutableInt {
        private int value = 0;

        private MutableInt inc() {
            ++value;
            return this;
        }

        private MutableInt dec() {
            --value;
            return this;
        }

        private int get() {
            return value;
        }
    }
}
// @lc code=end

