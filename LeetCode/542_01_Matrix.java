class Solution {
    public int[][] updateMatrix(int[][] matrix) {

        int numRow = matrix.length;
        int numCol = matrix[0].length;

        int[][] ans = new int[numRow][numCol];
        Queue<Pair> queue = new LinkedList<Pair>();

        for (int i = 0 ; i < numRow ; ++i) {
            for (int j = 0 ; j < numCol ; ++j) {
                if (matrix[i][j] == 0) {
                    ans[i][j] = 0;
                } else {
                    queue.add(new Pair(i, j));
                }
            }
        }

        while (!queue.isEmpty()) {
            Pair pair = queue.poll();
            int distance = calculateMinDistance(matrix, numRow, numCol, pair);
            ans[pair.row][pair.col] = distance;
        }

        return ans;
    }

    private int calculateMinDistance(int[][] matrix, int numRow, int numCol, Pair root) {

        int distance = 1;
        Queue<Tuple> queue = new LinkedList<Tuple>();
        queue.add(new Tuple(root.row, root.col, 1));

        while (!queue.isEmpty()) {
            Tuple tuple = queue.poll();
            int row = tuple.row;
            int col = tuple.col;
            distance = tuple.distance;

            if (row > 0) {
                if (matrix[row - 1][col] == 0) {
                    break;
                }
                queue.add(new Tuple(row - 1, col, distance + 1));
            }
            if (row < numRow - 1) {
                if (matrix[row + 1][col] == 0) {
                    break;
                }
                queue.add(new Tuple(row + 1, col, distance + 1));
            }
            if (col > 0) {
                if (matrix[row][col - 1] == 0) {
                    break;
                }
                queue.add(new Tuple(row, col - 1, distance + 1));
            }
            if (col < numCol - 1) {
                if (matrix[row][col + 1] == 0) {
                    break;
                }
                queue.add(new Tuple(row, col + 1, distance + 1));
            }
        }

        return distance;
    }

    private class Pair {
        public int row;
        public int col;

        public Pair(int row, int col) {
            this.row = row;
            this.col = col;
        }
    }

    private class Tuple {
        public int row;
        public int col;
        public int distance;

        public Tuple(int row, int col, int distance) {
            this.row = row;
            this.col = col;
            this.distance = distance;
        }
    }
}