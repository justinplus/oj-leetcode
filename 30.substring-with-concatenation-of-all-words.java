/*
 * @lc app=leetcode id=30 lang=java
 *
 * [30] Substring with Concatenation of All Words
 */

import java.util.ArrayList;
import java.util.HashMap;
import java.util.HashSet;
import java.util.List;
import java.util.Map;
import java.util.Set;
import java.util.function.BiFunction;
import java.util.function.Function;

// @lc code=start
class Solution {
    // accepted 14ms
    public List<Integer> findSubstring(String s, String[] words) {
        assert words.length > 0;

        final int wordLen = words[0].length();
        final int subStrLen = wordLen * words.length;
        final int strLen = s.length();
        if (subStrLen > strLen) {
            return List.of();
        }

        final Map<String, Integer> wordCounter = new HashMap<>(words.length);
        final List<Integer> result = new ArrayList<>();
        for (int i = 0; i < wordLen && i + subStrLen <= strLen; ++i) {
            int wordCount = words.length;
            wordCounter.clear();
            for (String w : words) {
                wordCounter.compute(w, (k, v) -> v == null ? 1 : v + 1);
            }
            for (int j = i; j <= i + subStrLen - wordLen; j += wordLen) {
                if (wordCounter.compute(s.substring(j, j + wordLen), (k, v) -> v == null ? -1 : v - 1) >= 0) {
                    --wordCount;
                }
            }
            if (wordCount == 0) {
                result.add(i);
            }
            for (int j = i + subStrLen; j + wordLen <= strLen; j += wordLen) {
                if (wordCounter.compute(s.substring(j - subStrLen, j - subStrLen + wordLen),
                        (k, v) -> v == null ? 1 : v + 1) > 0) {
                    ++wordCount;
                }
                if (wordCounter.compute(s.substring(j, j + wordLen),
                        (k, v) -> v == null ? -1 : v - 1) >= 0) {
                    --wordCount;
                }
                if (wordCount == 0) {
                    result.add(j + wordLen - subStrLen);
                }
            }
        }
        return result;
    }

    // NOTE: accepted 256ms, but not the best solution
    public List<Integer> findSubstringInefficient(String s, String[] words) {
        assert words.length > 0;

        final int wordLen = words[0].length();
        final int subStrLen = wordLen * words.length;
        if (subStrLen > s.length()) {
            return List.of();
        }

        final Map<String, Integer> wordCounter = new HashMap<>(words.length);
        final List<Integer> result = new ArrayList<>();
        final Set<String> validSubStrings = new HashSet<>();

        // NOTE: note the furthermost index
        for (int i = 0, len = s.length(); i < len - subStrLen + 1; ++i) {
            final String subStr = s.substring(i, i + subStrLen);
            if (validSubStrings.contains(subStr)) {
                result.add(i);
            } else {
                wordCounter.clear();
                for (String w : words) {
                    wordCounter.compute(w, (k, v) -> v == null ? 1 : v + 1);
                }
                if (isPremutation(s.substring(i, i + subStrLen), wordLen, wordCounter)) {
                    result.add(i);
                    validSubStrings.add(subStr);
                }
            }
        }
        return result;
    }

    private static boolean isPremutation(String s, int wordLen, Map<String, Integer> wordCounter) {
        final ExecutionAware<Integer> executionAware = new ExecutionAware<>();
        final BiFunction<String, Integer, Integer> remappingFunc = ((BiFunction<String, Integer, Integer>) (k,
                v) -> v - 1 == 0 ? null : v - 1).andThen(executionAware);

        // NOTE: note the furthermost index
        for (int i = 0, len = s.length(); i < len - wordLen + 1; i += wordLen) {
            final String word = s.substring(i, i + wordLen);
            executionAware.reset();

            wordCounter.computeIfPresent(word, remappingFunc);
            if (!executionAware.isExecuted()) {
                return false;
            }
        }

        return true;
    }

    private static class ExecutionAware<T> implements Function<T, T> {
        private boolean isExecuted = false;

        @Override
        public T apply(T t) {
            isExecuted = true;
            return t;
        }

        public boolean isExecuted() {
            return isExecuted;
        }

        public void reset() {
            isExecuted = false;
        }
    }
}
// @lc code=end
