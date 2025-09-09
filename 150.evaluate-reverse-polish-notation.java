/*
 * @lc app=leetcode id=150 lang=java
 *
 * [150] Evaluate Reverse Polish Notation
 */

import java.util.ArrayDeque;
import java.util.Deque;
import java.util.Map;
import java.util.function.BiFunction;

// @lc code=start
class Solution {
    private static final Map<Object, BiFunction<Integer, Integer, Integer>> OPERATIONS = Map.of(
        "+", Integer::sum,
        "-", (a, b) -> b - a,
        "/", (a, b) -> b / a,
        "*", (a, b) -> a * b
    );

    public int evalRPN(String[] tokens) {
        final Deque<Object> stack = new ArrayDeque<>(256);

        for (String token : tokens) {
            final BiFunction<Integer, Integer, Integer> func = OPERATIONS.get(token);
            if (func == null) {
                stack.addLast(Integer.parseInt(token));
            } else {
                int op1 = (int) stack.removeLast();
                int op2 = (int) stack.removeLast();
                stack.addLast(func.apply(op1, op2));
            }
        }

        return (int) stack.removeLast();
    }
}
// @lc code=end
