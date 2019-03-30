class NumArray {

public:
    NumArray(vector<int> nums)
        : size(nums.size()),
          C(size + 1, 0) {

        A.resize(size + 1);
        for (int i = 1 ; i <= size ; ++i) {
            A[i] = nums[i - 1];
            add(i, A[i]);
        }
    }

    void update(int i, int val) {
        ++i;
        add(i, val - A[i]);
        A[i] = val;
    }

    int sumRange(int i, int j) {
        ++i;
        ++j;
        return sum(j) - sum(i - 1);
    }

private:
    int lowBit(int index) {
        return index & -index;
    }

    void add(int index, int value) {
        for (int i = index ; i <= size ; i += lowBit(i)) {
            C[i] += value;
        }
    }

    int sum(int index) {
        int sum = 0;
        for (int i = index ; i > 0 ; i -= lowBit(i)) {
            sum += C[i];
        }
        return sum;
    }

private:
    int size;
    std::vector<int> A;
    std::vector<int> C;
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray obj = new NumArray(nums);
 * obj.update(i,val);
 * int param_2 = obj.sumRange(i,j);
 */