/*
 * @lc app=leetcode id=149 lang=java
 *
 * [149] Max Points on a Line
 */

import java.util.HashMap;
import java.util.HashSet;
import java.util.Map;
import java.util.Set;

// @lc code=start
// 13ms beats 88.39% 
class Solution {
    public int maxPoints(int[][] points) {
        final int len = points.length;
        final Map<Double, Integer> counter = new HashMap<>();
        int max = 1;
        for (int i = 0; i < len - 1; ++i) {
            final int x1 = points[i][0], y1 = points[i][1];
            for (int j = i + 1; j < len; ++j) {
                final int x2 = points[j][0], y2 = points[j][1];
                if (x1 == x2) {
                    max = Math.max(max,
                            counter.compute(Double.NaN, (k, v) -> v == null ? 2 : v + 1));
                } else if (y1 == y2) { 
                    // NOTE: corner case -0.0000, 0.0000
                    max = Math.max(max,
                            counter.compute(0d, (k, v) -> v == null ? 2 : v + 1));

                } else {
                    final double a = ((double) (y1 - y2)) / ((double) (x1 - x2));
                    max = Math.max(max,
                            counter.compute(a, (k, v) -> v == null ? 2 : v + 1));
                }
            }
            counter.clear();
        }
        return max;
    }

    // 43ms beats 12.61%
    private static int maxPointsBruteForce(int[][] points) {
        // NOTE: corner case
        final int len = points.length;
        if (len == 1) {
            return 1;
        }

        final Map<Line, Set<Point>> counter = new HashMap<>();
        int max = 0;
        for (int i = 0; i < len - 1; ++i) {
            final int x1 = points[i][0], y1 = points[i][1];
            for (int j = i + 1; j < len; ++j) {
                final int x2 = points[j][0], y2 = points[j][1];
                if (x1 == x2) {
                    final Line l = new Line(Double.NaN, x1);
                    max = Math.max(max, add(counter, l, x1, y1, x2, y2));
                } else {
                    final double a = ((double) (y1 - y2)) / ((double) (x1 - x2));
                    final Line l = new Line(a, y1 - a * x1);
                    max = Math.max(max, add(counter, l, x1, y1, x2, y2));
                }
            }
        }

        return max;
    }

    private static int add(Map<Line, Set<Point>> lines, Line l, int x1, int y1, int x2, int y2) {
        final Set<?> updated = lines.compute(l, (k, v) -> {
            final Set<Point> points = v == null ? new HashSet<>() : v;
            points.add(new Point(x1, y1));
            points.add(new Point(x2, y2));
            return points;
        });
        return updated.size();
    }

    private static record Line(double a, double b) {};
    private static record Point(int x, int y) {};
}
// @lc code=end

