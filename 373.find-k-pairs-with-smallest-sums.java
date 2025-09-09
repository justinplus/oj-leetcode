/*
 * @lc app=leetcode id=373 lang=java
 *
 * [373] Find K Pairs with Smallest Sums
 */

import java.util.ArrayList;
import java.util.Comparator;
import java.util.List;
import java.util.PriorityQueue;

// @lc code=start
// TODO: review
class Solution {
    public List<List<Integer>> kSmallestPairs(int[] nums1, int[] nums2, int k) {
        final int len1 = nums1.length, len2 = nums2.length;
        final PriorityQueue<Pair> heap = new PriorityQueue<>(Math.max(len1, len2),
                Comparator.comparingInt(p -> p.left + p.right));
        
        final boolean[] iOccupied = new boolean[len1];
        final boolean[] jOccupied = new boolean[len2];
        iOccupied[0] = jOccupied[0] = true;

        heap.add(new Pair(nums1[0], nums2[0], 0, 0));

        final List<List<Integer>> result = new ArrayList<>();
        for (; k != 0; k--) {
            final Pair min = heap.poll();
            result.add(List.of(min.left, min.right));
            iOccupied[min.i] = jOccupied[min.j] = false;
            final int nextI = min.i + 1, nextJ = min.j + 1;
            if (nextI < len1 && !iOccupied[nextI]) {
                heap.add(new Pair(nums1[nextI], nums2[min.j], nextI, min.j));
                iOccupied[nextI] = jOccupied[min.j] = true;
            }
            if (nextJ < len2 && !jOccupied[nextJ]) {
                heap.add(new Pair(nums1[min.i], nums2[nextJ], min.i, nextJ));
                iOccupied[min.i] = jOccupied[nextJ] = true;
            }
        }

        return result;
    }

    private static record Pair(int left, int right, int i, int j) {};
}
// @lc code=end

