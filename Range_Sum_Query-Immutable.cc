class NumArray {
public:
    NumArray(vector<int> &nums)
     : size_(nums.size()),
       nums_(nums),
       sum_((size_ > 0)? (new int[size_]) : nullptr)
    {
        if (sum_.get()) {
            sum_[0] = nums[0];
            for (int i = 1 ; i < size_ ; ++i)
                sum_[i] = sum_[i - 1] + nums[i];
        }
    }

    int sumRange(int i, int j)
    {
        return (sum_.get() != nullptr)? (sum_[j] - sum_[i] + nums_[i]) : UNDEF;
    }

private:
    static const int UNDEF = 0;

    int size_;
    vector<int> nums_;
    unique_ptr<int[]> sum_;
};

// Your NumArray object will be instantiated and called as such:
// NumArray numArray(nums);
// numArray.sumRange(0, 1);
// numArray.sumRange(1, 2);