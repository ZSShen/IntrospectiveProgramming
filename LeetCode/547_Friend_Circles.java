class Solution {
    public int findCircleNum(int[][] M) {

        int num = M.length;
        if (num == 0) {
            return 0;
        }

        boolean[] visit = new boolean[num];
        for (int i = 0 ; i < num ; ++i) {
            visit[i] = false;
        }

        int count = 0;
        for (int i = 0 ; i < num ; ++i) {
            if (!visit[i]) {
                ++count;
                traverse(M, num, i, visit);
            }
        }

        return count;
    }

    private void traverse(int[][] M, int num, int src, boolean[] visit) {

        visit[src] = true;
        for (int i = 0 ; i < num ; ++i) {
            if (M[src][i] == 1 && !visit[i]) {
                traverse(M, num, i, visit);
            }
        }
    }
}