class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        std::unordered_map<int, int> map;
        for (int num : nums) {
            ++map[num];
        }

        auto compare = [] (const IntPair& lhs, const IntPair& rhs) {
                return lhs.second > rhs.second;
            };
        std::priority_queue<
            IntPair, std::vector<IntPair>, decltype(compare)> queue(compare);

        for (auto& pair : map) {
            queue.push(std::move(pair));
            if (queue.size() > k) {
                queue.pop();
            }
        }

        std::vector<int> ans;
        while (!queue.empty()) {
            const auto& pair = queue.top();
            ans.push_back(pair.first);
            queue.pop();
        }

        return std::move(ans);
    }

private:
    using IntPair = std::pair<int, int>;
};