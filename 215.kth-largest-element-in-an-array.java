/*
 * @lc app=leetcode id=215 lang=java
 *
 * [215] Kth Largest Element in an Array
 */

// @lc code=start
// TODO: 33ms beats 74.61% - improve performance
// TODO: use the idea of quick sort
class Solution {
    public int findKthLargest(int[] nums, int k) {
        final int half = (nums.length + 1) / 2;
        final Heap heap;
        final int kk;
        if (half >= k) {
            heap = new Heap(nums, (a, b) -> b - a);
            kk = k;
        } else {
            heap = new Heap(nums, (a, b) -> a - b);
            kk = nums.length - k + 1;
        }

        for (int i = 0; i < kk - 1; ++i) {
            heap.removeFirst();
        }
        return heap.removeFirst();
    }

    @FunctionalInterface
    private static interface IntComparator {
        int compare(int a, int b);
    }

    private static class Heap {
        private int[] arr;
        private int len;
        private final IntComparator cmp;

        public Heap(int[] arr, IntComparator cmp) {
            this.arr = arr;
            this.len = arr.length;
            this.cmp = cmp;

            for (int i = 1; i < len; ++i) {
                siftUp(arr, cmp, i);
            }
        }

        public boolean isEmpty() {
            return len == 0;
        }

        public int removeFirst() {
            final int first = arr[0];
            arr[0] = arr[--len];

            siftDown(arr, len, cmp, 0);
            return first;
        }
    }

    private static void siftUp(int[] arr, IntComparator cmp, int i) {
        final int val = arr[i];
        // (0 - 1) / 2 = 0, cannot use parent >= 0
        // for (int parent = (i - 1) / 2; parent >= 0; i = parent, parent = (parent - 1)
        // / 2) {
        for (int parent = (i - 1) / 2; i > 0; i = parent, parent = (parent - 1) / 2) {
            if (cmp.compare(val, arr[parent]) < 0) {
                arr[i] = arr[parent];
            } else {
                break;
            }
        }
        arr[i] = val;
    }

    private static void siftDown(int[] arr, int len, IntComparator cmp, int i) {
        final int val = arr[i];
        for (int child = i * 2 + 1; child < len; i = child, child = child * 2 + 1) {
            final int right = child + 1;
            final int childVal = right < len && cmp.compare(arr[right], arr[child]) < 0 ? arr[child = right]
                    : arr[child];
            if (cmp.compare(childVal, val) < 0) {
                arr[i] = childVal;
            } else {
                break;
            }
        }
        arr[i] = val;
    }
}
// @lc code=end
