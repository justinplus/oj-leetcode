/*
 * @lc app=leetcode id=68 lang=java
 *
 * [68] Text Justification
 */
import java.util.ArrayList;
import java.util.List;

// @lc code=start
class Solution {
    private static final String SPACE = " ";
    // TODO: the performance is not good
    public List<String> fullJustify(String[] words, int maxWidth) {
        final List<List<String>> wordLists = new ArrayList<>();
        wordLists.add(new ArrayList<>());

        int width = 0;
        for (String w : words) {
            List<String> curr = wordLists.getLast();
            width += curr.isEmpty() ? w.length() : w.length() + 1;

            if (width > maxWidth) {
                final List<String> next = new ArrayList<>();
                next.add(w);
                wordLists.add(next);
                width = w.length();
            } else {
                curr.add(w);
            }
        }

        final List<String> result = new ArrayList<>();
        for(int i = 0; i < wordLists.size() - 1; ++i) {
            final List<String> curr = wordLists.get(i);
            if (curr.size() == 0) {
                // should never happen based on input constraints
                assert false;
            } else if (curr.size() == 1) {
                result.add(curr.getFirst() + SPACE.repeat(maxWidth - curr.getFirst().length()));
            } else {
                final int totalWordLength = curr.stream().mapToInt(String::length).sum();
                final int totalSpaceWidth = maxWidth - totalWordLength;
                final int baseSpaceCount = totalSpaceWidth / (curr.size() - 1);
                final int extraSpaceWordCount = totalSpaceWidth % (curr.size() - 1) + 1;

                result.add(String.join(SPACE.repeat(baseSpaceCount + 1), curr.subList(0, extraSpaceWordCount))
                        + SPACE.repeat(baseSpaceCount)
                        + String.join(SPACE.repeat(baseSpaceCount), curr.subList(extraSpaceWordCount, curr.size())));
            }
        }

        // for the last line
        final String joinedWords = String.join(SPACE, wordLists.getLast());
        result.add(joinedWords + SPACE.repeat(maxWidth - joinedWords.length()));

        return result;
    }
}
// @lc code=end

