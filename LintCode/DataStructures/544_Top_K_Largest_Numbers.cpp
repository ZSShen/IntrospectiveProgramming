class Solution {
public:
    /**
     * @param nums: an integer array
     * @param k: An integer
     * @return: the top k largest numbers in array
     */
    vector<int> topk(vector<int> &nums, int k) {
        // write your code here

        std::priority_queue<int, std::vector<int>, std::greater<int>> queue;

        int size = nums.size();
        for (int i = 0 ; i < k ; ++i) {
            queue.push(nums[i]);
        }

        for (int i = k ; i < size ; ++i) {
            if (nums[i] >= queue.top()) {
                queue.push(nums[i]);
                queue.pop();
            }
        }

        std::vector<int> ans;
        while (!queue.empty()) {
            ans.push_back(queue.top());
            queue.pop();
        }

        std::reverse(ans.begin(), ans.end());
        return ans;
    }
};