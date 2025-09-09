/*
 * @lc app=leetcode id=205 lang=java
 *
 * [205] Isomorphic Strings
 */

// @lc code=start
class Solution {
    private static final char NULL_CHAR = '\u0000';

    // TODO: try to give a formal proof
    public boolean isIsomorphic(String s, String t) {
        return isIsomorphicHalf(s, t) && isIsomorphicHalf(t, s);
    }

    public boolean isIsomorphicHalf(String s, String t) {
        assert s.length() == t.length();

        final AsciiMap charMap = new AsciiMap();
        for (int i = 0, len = s.length(); i < len; ++i) {
            final char k = s.charAt(i), v = t.charAt(i);
            final char vv = charMap.get(k);
            if (vv ==  NULL_CHAR) {
                charMap.set(k, v);
            } else if (vv != v ){
                return false;
            }
        }

        return true;
    }

    private static class AsciiMap {
        final char[] map = new char[256];

        public char get(char c) {
            return map[c - NULL_CHAR];
        }

        public void set(char key, char val) {
            map[key - NULL_CHAR] = val;
        }
    }
}
// @lc code=end

