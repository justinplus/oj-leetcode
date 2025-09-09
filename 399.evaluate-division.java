/*
 * @lc app=leetcode id=399 lang=java
 *
 * [399] Evaluate Division
 */

import java.util.HashMap;
import java.util.HashSet;
import java.util.List;
import java.util.Map;
import java.util.Set;

// @lc code=start
// TODO: 5ms - performance is not good enough
class Solution {
    public double[] calcEquation(List<List<String>> equations, double[] values, List<List<String>> queries) {
        final Map<String, Map<String, Double>> graph = new HashMap<>();
        final int len = equations.size();
        for (int i = 0; i < len; ++i) {
            final String var0 = equations.get(i).get(0),
                    var1 = equations.get(i).get(1);
            final double value = values[i];

            graph.compute(var0, (k, v) -> {
                Map<String, Double> edges = v == null ? new HashMap<>() : v;
                edges.put(var1, value);
                return edges;
            });

            graph.compute(var1, (k, v) -> {
                Map<String, Double> edges = v == null ? new HashMap<>() : v;
                edges.put(var0, 1 / value);
                return edges;
            });
        }

        return queries.stream()
                .map(query -> calculate(graph, query.get(0), query.get(1)))
                .mapToDouble(Double::doubleValue)
                .toArray();
    }

    private static double calculate(Map<String, Map<String, Double>> graph, String var0, String var1) {
        if (!graph.containsKey(var1)) {
            return -1;
        }
        return calculate(new HashSet<>(), graph, var0, var1);
    }

    private static double calculate(Set<String> visited, Map<String, Map<String, Double>> graph, String var0, String var1) {
        visited.add(var0);
        final Map<String, Double> edges = graph.get(var0);
        if (null == edges) {
            return -1;
        }
        final Double valVar0Var1 = edges.get(var1);
        if (valVar0Var1 != null) {
            return valVar0Var1;
        }
        for (Map.Entry<String, Double> entry : edges.entrySet()) {
            final String var = entry.getKey();
            if (!visited.contains(var)) {
                final double result = calculate(visited, graph, var, var1);
                if (result != -1) {
                    return result * entry.getValue();
                }
            }
        }
        return -1;
    }
}
// @lc code=end

