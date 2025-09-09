/*
 * @lc app=leetcode id=433 lang=java
 *
 * [433] Minimum Genetic Mutation
 */

import java.util.ArrayDeque;
import java.util.Deque;
import java.util.HashSet;
import java.util.Set;

// @lc code=start
class Solution {
    public int minMutation(String startGene, String endGene, String[] bank) {
        final Set<String> toVisit = new HashSet<>();
        for (String gene : bank) {
            toVisit.add(gene);
        }

        int mutationCount = 0;
        Deque<String> q1 = new ArrayDeque<>();
        q1.addLast(startGene);
        Deque<String> q2 = new ArrayDeque<>();

        while (!q1.isEmpty()) {
            ++mutationCount;
            do {
                String g = q1.removeFirst();
                if (enqueueValidNeighbors(g, endGene, toVisit, q2)) {
                    return mutationCount;
                }
            } while (!q1.isEmpty());

            final Deque<String> q = q1;
            q1 = q2;
            q2 = q;
        }
        return -1;
    }

    private static boolean enqueueValidNeighbors(String startGene, String endGene,
            Set<String> toVisit, Deque<String> queue) {
        final char[] baseArr = startGene.toCharArray();
        for (int i = 0, len = baseArr.length; i < len; ++i) {
            for (int j = 0; j < 3; ++j) {
                baseArr[i] = getNextBase(baseArr[i]);
                final String neighboar = String.copyValueOf(baseArr);
                // NOTE: corner case, bank is empty
                // if (neighboar.equals(endGene)) {
                    // return true;
                // }
                if (toVisit.remove(neighboar)) {
                    if (neighboar.equals(endGene)) {
                        return true;
                    }
                    queue.addLast(neighboar);
                }
            }
            // back to original base
            baseArr[i] = getNextBase(baseArr[i]);
        }
        return false;
    }

    // A -> C -> G -> T
    private static char getNextBase(char gene) {
        return switch (gene) {
            case 'A' -> 'C';
            case 'C' -> 'G';
            case 'G' -> 'T';
            case 'T' -> 'A';
            default -> throw new AssertionError();
        };
    }
}
// @lc code=end

