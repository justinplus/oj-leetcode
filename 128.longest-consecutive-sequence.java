/*
 * @lc app=leetcode id=128 lang=java
 *
 * [128] Longest Consecutive Sequence
 */
import java.util.HashMap;
import java.util.HashSet;
import java.util.Map;
import java.util.Set;
// @lc code=start
class Solution {
    // use set
    public int longestConsecutive(int[] nums) {
        final Set<Integer> set = new HashSet<>(nums.length);
        for (int num : nums) {
            set.add(num);
        }

        int max = 0;
        for (int i = 0, len = nums.length; i < len && !set.isEmpty(); ++i) {
            final int num = nums[i];
            if (set.remove(num)) {
                int count = 1;
                for (int n = num + 1; set.remove(n); ++n, ++count);
                for (int n = num - 1; set.remove(n); --n, ++count);

                max = Math.max(max, count);
            }
        }

        /* NOTE: time limit exceeds
        int max = 0;
        while (!set.isEmpty()) {
            int count = 1;
            // NOTE: seems this is a costly operation
            final Integer num = set.iterator().next();
            set.remove(num);

            for (int n = num + 1; set.remove(n); ++n, ++count);
            for (int n = num - 1; set.remove(n); --n, ++count);

            max = Math.max(max, count);
        }*/
        return max;
    }

    // use disjoint set
    public int longestConsecutiveDisjointSet(int[] nums) {
        final DisjointSet disjointSet = new DisjointSet();
        int longestAmount = 0;
        for (int num : nums) {
            disjointSet.union(num, num - 1);
            int size = disjointSet.union(num, num + 1);
            longestAmount = Math.max(longestAmount, size);
        }

        return longestAmount;
    }

    private static class DisjointSet {
        private final Map<Integer, Node> map = new HashMap<>();

        public int union(int num, int target) {
            map.computeIfAbsent(num, k -> new Node(num, 1));

            final Node rootNode = findRoot(num);
            final Node targetRootNode = findRoot(target);
            if (targetRootNode == null || rootNode == targetRootNode) {
                return rootNode.size;
            }

            if (rootNode.size < targetRootNode.size) {
                rootNode.parent = targetRootNode.parent;
                targetRootNode.size += rootNode.size;
                return targetRootNode.size;
            } else {
                targetRootNode.parent = rootNode.parent;
                rootNode.size += targetRootNode.size;
                return rootNode.size;
            }
        }

        private Node findRoot(int num) {
            final Node root = findRoot0(num);
            if (root != null) {
                while (true) {
                    final Node node = map.get(num);
                    if (node.parent != root.parent) {
                        final Node parent = map.get(node.parent);
                        node.parent = root.parent;
                        parent.size -= node.size;
                        num = node.parent;
                    } else {
                        break;
                    }
                }
            }
            return root;
        }

        private Node findRoot0(int num) {
            final Node root;
            while (true) {
                final Node node = map.get(num);
                if (node == null) {
                    root = null;
                    break;
                }
                if (node.parent == num) {
                    root = node;
                    break;
                }
                num = node.parent;
            }
            return root;
        }

        private static class Node {
            int parent;
            int size;

            public Node (int parent, int size) {
                this.parent = parent;
                this.size = size;
            }
        }
    }
}
// @lc code=end

