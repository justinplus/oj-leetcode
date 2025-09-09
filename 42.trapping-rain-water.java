/*
 * @lc app=leetcode id=42 lang=java
 *
 * [42] Trapping Rain Water
 */

import java.util.ArrayDeque;
import java.util.Deque;

// @lc code=start
// TODO: 4ms beats 6.16% - improve performance
class Solution {
    public int trap(int[] height) {
        final int len = height.length;
        final Deque<State> stack = new ArrayDeque<>(256);
        int i = 0;
        for (; i < len; ++i) {
            if (height[i] != 0) {
                stack.addLast(new State(i, height[i]));
                break;
            }
        }

        int water = 0;
        for (++i; i < len; ++i) {
            final int h = height[i];
            if (h != 0) {
                int prevHeight = 0;
                while (!stack.isEmpty()) {
                    final State last = stack.peekLast();
                    water += (i - last.index - 1) * (Math.min(h, last.height) - prevHeight);
                    prevHeight = last.height;

                    if (h > last.height) {
                        stack.removeLast();
                        if (stack.isEmpty()) {
                            stack.add(new State(i, h));
                            break;
                        }
                    } else if (h == last.height) {
                        stack.removeLast();
                        stack.addLast(new State(i, h));
                        break;
                    } else {
                        stack.addLast(new State(i, h));
                        break;
                    }
                }
            }
        }
        return water;
    }

    private static record State(int index, int height) {
    }
}
// @lc code=end
