/*
 * @lc app=leetcode id=427 lang=java
 *
 * [427] Construct Quad Tree
 */

// Definition for a QuadTree node.
class Node {
    public boolean val;
    public boolean isLeaf;
    public Node topLeft;
    public Node topRight;
    public Node bottomLeft;
    public Node bottomRight;

    public Node() {
        this.val = false;
        this.isLeaf = false;
        this.topLeft = null;
        this.topRight = null;
        this.bottomLeft = null;
        this.bottomRight = null;
    }

    public Node(boolean val, boolean isLeaf) {
        this.val = val;
        this.isLeaf = isLeaf;
        this.topLeft = null;
        this.topRight = null;
        this.bottomLeft = null;
        this.bottomRight = null;
    }

    public Node(boolean val, boolean isLeaf, Node topLeft, Node topRight, Node bottomLeft, Node bottomRight) {
        this.val = val;
        this.isLeaf = isLeaf;
        this.topLeft = topLeft;
        this.topRight = topRight;
        this.bottomLeft = bottomLeft;
        this.bottomRight = bottomRight;
    }
}

// @lc code=start
class Solution {
    // NOTE: corner case [[0]]
    public Node construct(int[][] grid) {
        if (grid.length == 1) {
            return new Node(grid[0][0] == 1, true);
        }
        return construct(grid, 0, 0, grid.length);
    }

    private static Node construct(int[][] grid, int x, int y, int len) {
        final int half = len / 2;
        if (half == 1) {
            if (grid[x][y] == grid[x + 1][y]
                    && grid[x][y] == grid[x][y + 1]
                    && grid[x][y] == grid[x + 1][y + 1]) {
                return new Node(grid[x][y] == 1, true);
            }
            return new Node(false, false,
                    new Node(grid[x][y] == 1, true),
                    new Node(grid[x][y + 1] == 1, true),
                    new Node(grid[x + 1][y] == 1, true),
                    new Node(grid[x + 1][y + 1] == 1, true));
        }

        final Node topLeft = construct(grid, x, y, half);
        final Node topRight = construct(grid, x, y + half, half);
        final Node bottomLeft = construct(grid, x + half, y, half);
        final Node bottomRight = construct(grid, x + half, y + half, half);

        if (topLeft.isLeaf && topRight.isLeaf && bottomLeft.isLeaf && bottomRight.isLeaf
                && topLeft.val == topRight.val && topLeft.val == bottomLeft.val && topLeft.val == bottomRight.val) {
            return new Node(topLeft.val, true);
        }

        return new Node(false, false, topLeft, topRight, bottomLeft, bottomRight);
    }
}
// @lc code=end
