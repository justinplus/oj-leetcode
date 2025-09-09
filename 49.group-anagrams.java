/*
 * @lc app=leetcode id=49 lang=java
 *
 * [49] Group Anagrams
 */

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.Map;
import java.util.stream.Collectors;
import java.util.stream.Stream;

// @lc code=start
class Solution {
    public List<List<String>> groupAnagrams(String[] strs) {
        final Map<AnagramSignature, List<String>> groups = Stream.of(strs)
                .collect(Collectors.groupingBy(s -> new AnagramSignature(s)));

        return new ArrayList<>(groups.values());
    }

    private static class AnagramSignature {
        private final int[] counts = new int['z' - 'a' + 1];

        public AnagramSignature(String s) {
            for (int i = 0, len = s.length(); i < len; ++i) {
                ++counts[s.charAt(i) - 'a'];
            }
        }

        @Override
        public int hashCode() {
            return Arrays.hashCode(counts);
        }

        @Override
        public boolean equals(Object o) {
            if (o == null) {
                return false;
            }

            if (this.getClass() != o.getClass()) {
                return false;
            }

            return Arrays.equals(this.counts, ((AnagramSignature) o).counts);
        }
    }
}
// @lc code=end

