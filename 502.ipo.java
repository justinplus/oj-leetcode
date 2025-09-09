/*
 * @lc app=leetcode id=502 lang=java
 *
 * [502] IPO
 */

import java.util.Arrays;
import java.util.Comparator;
import java.util.PriorityQueue;

// @lc code=start
// TODO: review
//  127ms beats 39.74s - improve performance
class Solution {
    public int findMaximizedCapital(int k, int w, int[] profits, int[] capital) {
        final int len = profits.length;
        final Pair[] pairs = new Pair[len];
        for (int i = 0; i < len; ++i) {
            pairs[i] = new Pair(profits[i], capital[i]);
        }
    
        Arrays.sort(pairs, Comparator.comparingInt(p -> p.capital));
        final PriorityQueue<Pair> maxHeap = new PriorityQueue<>(256,
                Comparator.<Pair>comparingInt(p -> p.profit).reversed());

        int i = 0;
        do {
            // NOTE: i is not updated after j = len
            for (int j = i; j < len; ++j, ++i) {
                final Pair p = pairs[j];
                if (w >= p.capital) {
                    maxHeap.add(p);
                } else {
                    break;
                }
            }
            if (!maxHeap.isEmpty()) {
                final Pair p = maxHeap.poll();
                w += p.profit;
            } else {
                break;
            }
        } while (--k > 0);

        return w;
    }

    private static record Pair(int profit, int capital) {}
}
// @lc code=end

