/*
 * @lc app=leetcode id=242 lang=java
 *
 * [242] Valid Anagram
 */

import java.util.stream.IntStream;
// @lc code=start
class Solution {
    public boolean isAnagram(String s, String t) {
        final LetterCounter letterCounter = new LetterCounter();

        for (int i = 0, len = s.length(); i < len; ++i) {
            final char c = s.charAt(i);
            letterCounter.incAndGet(c);
        }

        for (int i = 0, len = t.length(); i < len; ++i) {
            final char c = t.charAt(i);
            if (letterCounter.decAndGet(c) == -1) {
                return false;
            }
        }

        return letterCounter.countAll() == 0;
    }

    private static final class LetterCounter {
        private final int[] counter = new int['z' - 'a' +1];

        private int incAndGet(char key) {
            return ++counter[key - 'a'];
        }

        private int decAndGet(char key) {
            return --counter[key - 'a'];
        }

        private int countAll() {
            return IntStream.of(counter).sum();
        }
    }
}
// @lc code=end

