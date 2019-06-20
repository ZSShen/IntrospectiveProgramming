class Solution {
public:
    /**
     * @param nums: A list of integers.
     * @param k: An integer
     * @return: The maximum number inside the window at each moving.
     */
    vector<int> maxSlidingWindow(vector<int> &nums, int k) {
        // write your code here

        int n = nums.size();
        if (n == 0 || k == 0) {
            return {};
        }

        std::vector<int> ans;
        std::deque<int> deque;

        for (int i = 0 ; i < k - 1 ; ++i) {
            enQueue(deque, nums, i);
        }

        for (int i = k - 1 ; i < n ; ++i) {
            enQueue(deque, nums, i);
            ans.push_back(nums[deque.front()]);
            deQueue(deque, i - k + 1);
        }

        return ans;
    }

private:
    void enQueue(std::deque<int>& deque, std::vector<int>& nums, int pos) {

        while (!deque.empty() && nums[deque.back()] < nums[pos]) {
            deque.pop_back();
        }
        deque.push_back(pos);
    }

    void deQueue(std::deque<int>& deque, int pos) {

        if (deque.front() == pos) {
            deque.pop_front();
        }
    }
};