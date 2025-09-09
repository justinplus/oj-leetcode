/*
 * @lc app=leetcode id=295 lang=java
 *
 * [295] Find Median from Data Stream
 */

import java.util.Comparator;
import java.util.PriorityQueue;

// @lc code=start
class MedianFinder {
    private final PriorityQueue<Integer> left;
    private final PriorityQueue<Integer> right;

    public MedianFinder() {
        this.left = new PriorityQueue<>(256, Comparator.reverseOrder());
        this.right = new PriorityQueue<>(256);
    }
    
    public void addNum(int num) {
        Integer leftMax = left.peek();
        if (leftMax != null && leftMax < num) {
            right.add(num);
        } else {
            left.add(num);
        }

        final int leftSize = left.size(), rightSize = right.size();
        if (leftSize > rightSize + 1) {
            right.add(left.poll());
        } else if (rightSize > leftSize + 1) {
            left.add(right.poll());
        }
    }
    
    public double findMedian() {
        final int leftSize = left.size(), rightSize = right.size();
        if (leftSize == rightSize) {
            return ((double) (left.peek() + right.peek())) / 2;
        } else if (leftSize > rightSize) {
            return left.peek();
        } else {
            return right.peek();
        }
    }
}

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder obj = new MedianFinder();
 * obj.addNum(num);
 * double param_2 = obj.findMedian();
 */
// @lc code=end

