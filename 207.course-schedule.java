/*
 * @lc app=leetcode id=207 lang=java
 *
 * [207] Course Schedule
 */

import java.util.Arrays;
import java.util.function.Consumer;

// @lc code=start
// TODO: 23ms poor performance
class Solution {
    public boolean canFinish(int numCourses, int[][] prerequisites) {
        final Graph g = new Graph(numCourses);
        for (int[] prerequisity : prerequisites) {
            g.addEdge(prerequisity[0], prerequisity[1]);
        }
        return g.isDAG();
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

