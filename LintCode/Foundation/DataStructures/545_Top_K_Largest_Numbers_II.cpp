class Solution {
private:
    int cap_;
    std::priority_queue<int, std::vector<int>, std::greater<int>> queue_;

public:
    /*
    * @param k: An integer
    */
    Solution(int k)
        : cap_(k) {
        // do intialization if necessary
    }

    /*
     * @param num: Number to be added
     * @return: nothing
     */
    void add(int num) {
        // write your code here

        if (queue_.size() < cap_) {
            queue_.push(num);
            return;
        }

        if (num >= queue_.top()) {
            queue_.push(num);
            queue_.pop();
        }
    }

    /*
     * @return: Top k element
     */
    vector<int> topk() {
        // write your code here

        std::vector<int> ans;
        while (!queue_.empty()) {
            ans.push_back(queue_.top());
            queue_.pop();
        }

        for (int num : ans) {
            queue_.push(num);
        }

        std::reverse(ans.begin(), ans.end());
        return ans;
    }
};