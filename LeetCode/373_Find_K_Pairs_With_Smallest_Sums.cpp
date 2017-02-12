
using IntPair = std::pair<int, int>;

class Solution {
public:
    vector<pair<int, int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        std::vector<IntPair> ans;

        if (nums1.empty() || nums2.empty()) {
            return ans;
        }

        auto compare = [] (const IntPair& lhs, const IntPair& rhs) -> bool {
            return (lhs.first + lhs.second) > (rhs.first + rhs.second);
        };
        std::priority_queue<IntPair, std::vector<IntPair>, decltype(compare)> heap(compare);    

        for (int num1 : nums1) {
            for (int num2 : nums2) {
                heap.push(std::make_pair(num1, num2));
            }
        }

        for (int i = 0, j = heap.size() ; j > 0 && i < k ; ++i, --j) {
            auto& pair = heap.top();
            ans.push_back(std::move(pair));
            heap.pop();
        }
        return ans;
    }
};