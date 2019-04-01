/**
 * Definition of Interval:
 * classs Interval {
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */


class BinaryIndexTree {
public:
    BinaryIndexTree(const std::vector<int>& nums)
        : size(nums.size()),
          A(size + 1, 0),
          C(size + 1, 0) {

        for (int i = 1 ; i <= size ; ++i) {
            A[i] = nums[i - 1];
            add(i, A[i]);
        }
    }

    void update(int index, long long value) {
        ++index;
        add(index, value - A[index]);
        A[index] = value;
    }

    long long query(int bgn, int end) {
        ++bgn;
        ++end;
        return sum(end) - sum(bgn - 1);
    }

private:
    int lowBit(int n) {
        return n & -n;
    }

    void add(int index, long long value) {
        for (int i = index ; i <= size ; i += lowBit(i)) {
            C[i] += value;
        }
    }

    long long sum(int index) {
        long long sum = 0;
        for (int i = index ; i > 0 ; i -= lowBit(i)) {
            sum += C[i];
        }
        return sum;
    }

private:
    int size;
    std::vector<int> A;
    std::vector<long long> C;
};


class Solution {
public:
    /**
     * @param A: An integer list
     * @param queries: An query list
     * @return: The result list
     */
    vector<long long> intervalSum(vector<int> &A, vector<Interval> &queries) {
        // write your code here

        BinaryIndexTree tree(A);

        std::vector<long long> ans;
        for (const auto& interval : queries) {
            ans.push_back(tree.query(interval.start, interval.end));
        }

        return ans;
    }
};