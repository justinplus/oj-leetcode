import java.util.*;

public class Solution {
  public int largestRectangleArea(int[] heights) {
    int[] h = Arrays.copyOf(heights, heights.length + 1);
    h[h.length-1] = 0;
    int[] stack = new int[heights.length+2];
    stack[0] = -1;
    // NOTE: the initial value of m
    int m = 1, max = 0;

    // NOTE: the initial value of i
    for( int i = 1; i < h.length; ++i) {
      while(m != 0 && h[stack[m]] > h[i]) {
        max = Math.max( max, h[stack[m]] * (i-stack[m-1]-1) );
        --m;
      }
      stack[++m] = i;
    }

    return max;
  }

  public static void main(String[] args) {
    Solution s = new Solution();
    // NOTE: Stack out of bound
    int [] heights = {0};
    System.out.println(s.largestRectangleArea(heights));
  }

}
