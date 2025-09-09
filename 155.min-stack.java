/*
 * @lc app=leetcode id=155 lang=java
 *
 * [155] Min Stack
 */

import java.util.ArrayDeque;
import java.util.Deque;

// @lc code=start
// TODO: review
class MinStack {
    private final Deque<ValWithMin> stack;

    public MinStack() {
        this.stack = new ArrayDeque<>(1024);
    }
    
    public void push(int val) {
        final ValWithMin valWithMin = stack.peekLast();
        if (null == valWithMin) {
            stack.addLast(new ValWithMin(val, val));
        } else {
            stack.addLast(new ValWithMin(val, Math.min(val, valWithMin.min())));
        }
    }
    
    public void pop() {
        stack.removeLast();
    }
    
    public int top() {
        return stack.peekLast().val();
        
    }
    
    public int getMin() {
        return stack.peekLast().min();
    }

    private static record ValWithMin(int val, int min){}
}

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(val);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */
// @lc code=end

