/*
 * @lc app=leetcode id=210 lang=java
 *
 * [210] Course Schedule II
 */

import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Deque;
import java.util.List;
import java.util.function.Consumer;

// @lc code=start
// TODO: performance is bad, should use adjacent list?
class Solution {
    public int[] findOrder(int numCourses, int[][] prerequisites) {
        final Graph g = new Graph(numCourses);
        for (int[] prerequisity : prerequisites) {
            g.addEdge(prerequisity[1], prerequisity[0]);
        }
        // 15ms poor performance
        return g.topoSort();
        // 15ms poor performance
        // return g.topoSortDfs();
    }

    private static class Graph {
        private enum VisitState {
            TO_VISIT,
            VISITING,
            VISITED
        }

        private final boolean[][] adjMatrix;

        public Graph(int nodeCount) {
            this.adjMatrix = new boolean[nodeCount][nodeCount];
        }

        public void addEdge(int from, int to) {
            adjMatrix[from][to] = true;
        }

        public boolean isDAG() {
            return dfsDag(null);
        }

        public int[] getInDegree() {
            final int vertextCnt = adjMatrix.length;
            final int[] in = new int[vertextCnt];

            for (int j = 0; j < vertextCnt; ++j) {
                for (int i = 0; i < vertextCnt; ++i) {
                    if (adjMatrix[i][j]) {
                        ++in[j];
                    }
                }
            }

            return in;
        }

        public int[] topoSort() {
            final int[] in = getInDegree();
            final int vertextCnt = in.length;
            final Deque<Integer> q = new ArrayDeque<>();
            final List<Integer> result = new ArrayList<>(in.length);
            for (int i = 0; i < vertextCnt; ++i) {
                if (in[i] == 0) {
                    q.addLast(i);
                }
            }

            while (!q.isEmpty()) {
                Integer vertex = q.removeLast();
                result.add(vertex);
                boolean[] edges = adjMatrix[vertex];
                for (int j = 0; j < vertextCnt; ++j) {
                    if (edges[j]) {
                        if (--in[j] == 0) {
                            q.addLast(j);
                        }
                    }
                }
            }

            if (result.size() != vertextCnt) {
                return new int[0];
            }

            return result.stream().mapToInt(Integer::intValue).toArray();
        }

        public int[] topoSortDfs() {
            final Deque<Integer> stack = new ArrayDeque<>(2000);
            if (dfsDag(n -> stack.addLast(n))) {
                final int[] result = new int[stack.size()];
                for (int i = 0; i < result.length; ++i) {
                    result[i] = stack.removeLast();
                }
                return result;
            } else {
                return new int[0];
            }
        }

        public boolean dfsDag(Consumer<Integer> consumer) {
            final int nodeCnt = adjMatrix.length;
            final VisitState[] visitStates = new VisitState[nodeCnt];
            Arrays.fill(visitStates, VisitState.TO_VISIT);
            for (int i = 0; i < nodeCnt; ++i) {
                if (visitStates[i] == VisitState.TO_VISIT && !dfsDag(i, visitStates, consumer)) {
                    return false;
                }
            }
            return true;
        }
        
        private boolean dfsDag(int i , VisitState[] visitStates, Consumer<Integer> consumer) {
            visitStates[i] = VisitState.VISITING;

            final int nodeCnt = adjMatrix.length;
            final boolean[] edges = adjMatrix[i];
            for (int j = 0; j < nodeCnt; ++j) {
                if (edges[j]) {
                    if (visitStates[j] == VisitState.VISITING) return false;
                    if (visitStates[j] == VisitState.TO_VISIT && !dfsDag(j, visitStates, consumer)) return false;
                }
            }

            if (consumer != null) {
                consumer.accept(i);
            }
            visitStates[i] = VisitState.VISITED;
            return true;
        }
    }
}
// @lc code=end

