
struct Record {
    int num;
    int r;
    int c;
    
    Record(int num, int r, int c)
      : num(num),
        r(r),
        c(c)
    { }
};

struct RecordCompare {
    
    bool operator() (const Record& lhs, const Record& rhs) {
        return lhs.num > rhs.num;
    }  
};


class Solution {
public:
    /**
     * @param matrix: a matrix of integers
     * @param k: An integer
     * @return: the kth smallest number in the matrix
     */
    int kthSmallest(vector<vector<int>> &matrix, int k) {
        // write your code here

        int num_r = matrix.size();
        int num_c = matrix[0].size();
        
        std::priority_queue<Record, std::vector<Record>, RecordCompare> queue;
        queue.push(Record(matrix[0][0], 0, 0));

        std::vector<std::vector<bool>> 
            visit(num_r, std::vector<bool>(num_c, false));
        visit[0][0] = true;

        int kth;
        for (int i = 0 ; i < k ; ++i) {
            auto top = queue.top();
            queue.pop();
            
            kth = top.num;
            int r = top.r;
            int c = top.c;
            int new_r = r + 1;
            int new_c = c + 1;
            
            if (new_r < num_r && !visit[new_r][c]) {
                queue.push(Record(matrix[new_r][c], new_r, c));
                visit[new_r][c] = true;
            }
            if (new_c < num_c && !visit[r][new_c]) {
                queue.push(Record(matrix[r][new_c], r, new_c));
                visit[r][new_c] = true;
            }
        }

        return kth;
    }
};
