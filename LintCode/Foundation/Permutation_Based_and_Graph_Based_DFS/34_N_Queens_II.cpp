class Solution {
public:
    /**
     * @param n: The number of queens.
     * @return: The total number of distinct solutions.
     */
    int totalNQueens(int n) {
        // write your code here
        
        std::vector<int> queens;
        int ans = 0;

        runBacktracking(0, n, queens, ans);
        return ans;
    }
    
private:
    void runBacktracking(
            int c,
            int n,
            std::vector<int>& queens,
            int& ans) {
        
        if (c == n) {
            ++ans;
            return;
        }
        
        for (int r = 0 ; r < n ; ++r) {
            bool legal = true;
            
            for (int i = 0 ; i < c ; ++i) {

                // Check for row conflict.
                if (r == queens[i]) {
                    legal = false;
                    break;
                }    
                
                // Check for diagonal conflict.
                if (r - c == queens[i] - i) {
                    legal = false;
                    break;
                }
                
                // Check for anti-diagonal conflict.
                if (r + c == queens[i] + i) {
                    legal = false;
                    break;
                }
            }
            
            if (legal) {
                queens.push_back(r);
                runBacktracking(c + 1, n, queens, ans);
                queens.pop_back();
            }
        }
    }
};