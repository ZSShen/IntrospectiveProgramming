class NumArray {
private:
    std::vector<int> prefix_;

public:
    NumArray(vector<int> nums) {
        int size = nums.size();
        prefix_.resize(size + 1);

        prefix_[0] = 0;
        for (int i = 0 ; i < size ; ++i) {
            prefix_[i + 1] = prefix_[i] + nums[i];
        }
    }

    int sumRange(int i, int j) {

        return prefix_[j + 1] - prefix_[i];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray obj = new NumArray(nums);
 * int param_1 = obj.sumRange(i,j);
 */