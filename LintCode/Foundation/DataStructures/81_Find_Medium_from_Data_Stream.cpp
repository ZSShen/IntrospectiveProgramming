class Solution {
public:
    /**
     * @param nums: A list of integers
     * @return: the median of numbers
     */
    vector<int> medianII(vector<int> &nums) {
        // write your code here

        std::priority_queue<int> max_q;
        std::priority_queue<int, std::vector<int>, std::greater<int>> min_q;

        std::vector<int> ans;
        ans.push_back(nums[0]);
        max_q.push(nums[0]);

        int size = nums.size();
        for (int i = 1 ; i < size ; ++i) {

            // Data insertion.
            if (nums[i] > max_q.top()) {
                min_q.push(nums[i]);
            } else {
                max_q.push(nums[i]);
            }

            // Queue redistribution.
            int max_size = max_q.size();
            int min_size = min_q.size();

            if (max_size - min_size == 2) {
                int elem = max_q.top();
                max_q.pop();
                min_q.push(elem);
            } else if (min_size - max_size == 2) {
                int elem = min_q.top();
                min_q.pop();
                max_q.push(elem);
            }

            // Find the medium.
            if ((max_size + min_size) % 2 == 0) {
                ans.push_back(max_q.top());
            } else {
                if (max_q.size() > min_q.size()) {
                    ans.push_back(max_q.top());
                } else {
                    ans.push_back(min_q.top());
                }
            }
        }

        return ans;
    }
};