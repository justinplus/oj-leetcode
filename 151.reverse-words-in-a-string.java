/*
 * @lc app=leetcode id=151 lang=java
 *
 * [151] Reverse Words in a String
 */

// @lc code=start
class Solution {
    final static char SPACE = ' ';
    public String reverseWords(String s) {
        return reverseWordsByReverseTwice(s);
    }

    public String reverseWordsBySplit(String s) {
        final String[] tokens = s.split(" +");
        final int startIndex = tokens[0].equals("") ? 1 : 0;
        final StringBuffer sb = new StringBuffer();
        for (int i = tokens.length - 1; i >= startIndex + 1; --i) {
            sb.append(tokens[i]).append(" ");
        }

        sb.append(tokens[startIndex]);
        return sb.toString();
    }

    public String reverseWordsByReverseTwice(String s) {
        final char[] chars = s.toCharArray();
        reverse(chars, 0, chars.length);

        for (int i = 0; i < chars.length; ++i) {
            for (; i < chars.length; ++i) {
                if (chars[i] != SPACE) {
                    break;
                }
            }
            for (int j = i + 1; j < chars.length; ++j) {
                if (chars[j] == SPACE) {
                    reverse(chars, i, j);
                    i = j;
                    break;
                }
                if (j == chars.length - 1) {
                    reverse(chars, i, chars.length);
                    i = j;
                    break;
                }
            }
        }

        StringBuilder sb = new StringBuilder();
        int endIndex = lastIndexOfNonSpace(chars);
        for (int i = 0; i <= endIndex; ++i) {
            final char c = chars[i];
            if (c != SPACE ||
                    sb.length() != 0 && sb.charAt(sb.length() - 1) != SPACE) {
                sb.append(c);
            }
        }

        return sb.toString();
    }

    // reserve a partition from begin inclusive to end exclusive
    public static void reverse(char[] s, int begin, int end) {
        final int count = (end - begin) / 2;
        for (int i = 0; i < count; ++i) {
            char tmp = s[begin + i];
            s[begin + i] = s[end - i - 1];
            s[end - i - 1] = tmp;
        }
    }

    public static int lastIndexOfNonSpace(char[] chars) {
        for (int i = chars.length - 1; i >= 0; --i) {
            if (chars[i] != SPACE) {
                return i;
            }
        }
        
        return -1;
    }
}
// @lc code=end

