/*
 * @lc app=leetcode id=127 lang=java
 *
 * [127] Word Ladder
 */

import java.util.ArrayDeque;
import java.util.Deque;
import java.util.HashSet;
import java.util.List;
import java.util.Set;

// @lc code=start
// TODO: 70ms beats 75.7%, enhance lockup table to improve performance
class Solution {
    private static char[] CHAR_LOCKUP = new char[] {
        'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 
        'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 
        'v', 'w', 'x', 'y', 'z', 'a'
    };
    public int ladderLength(String beginWord, String endWord, List<String> wordList) {
        final Set<String> toVisit = new HashSet<>(wordList);

        Deque<String> q1 = new ArrayDeque<>();
        Deque<String> q2 = new ArrayDeque<>();
        q1.addLast(beginWord);
        toVisit.remove(beginWord);

        int cnt = 1;
        while(!q1.isEmpty()) {
            ++cnt;
            do {
                final String w = q1.removeFirst();
                if (enqueueValidNeighbors(w, endWord, q2, toVisit)) {
                    return cnt;
                }
            } while (!q1.isEmpty());

            final Deque<String> q = q1;
            q1 = q2;
            q2 = q;
        }

        return 0;
    }

    private static boolean enqueueValidNeighbors(String beginWord, String endWord, Deque<String> queue, Set<String> toVisit) {
        final int len = beginWord.length();
        final char[] charArr = beginWord.toCharArray();
        for (int i = 0; i < len; ++i) {
            for (int j = 0, charLookupLen = CHAR_LOCKUP.length; j < charLookupLen - 1; ++j) {
                charArr[i] = CHAR_LOCKUP[charArr[i] - 'a'];
                final String word = String.copyValueOf(charArr);
                if (toVisit.remove(word)) {
                    if (word.equals(endWord)) {
                        return true;
                    }
                    queue.addLast(word);
                }
            }
            // revert char to original
            charArr[i] = CHAR_LOCKUP[charArr[i] - 'a'];
        }

        return false;
    }
}
// @lc code=end

