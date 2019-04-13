class Solution {
public:
    /**
     * @param nums: an array of Integer
     * @param target: an integer
     * @return: [index1 + 1, index2 + 1] (index1 < index2)
     */
    vector<int> twoSum7(vector<int> &nums, int target) {
        // write your code here

        int size = nums.size();
        if (size < 2) {
            return {};
        }

        std::unordered_multimap<int, int> map;
        for (int i = 0 ; i < size ; ++i) {
            map.insert(std::make_pair(nums[i], i));
        }
        
        for (int i = 0 ; i < size ; ++i) {
            int cand = nums[i] + target;
            auto range = map.equal_range(cand);
            for (auto it = range.first ; it != range.second ; ++it) {
                if (it->second > i) {
                    return {i + 1, it->second + 1};
                }
            }
            
            cand = nums[i] - target;
            range = map.equal_range(cand);
            for (auto it = range.first ; it != range.second ; ++it) {
                if (it->second > i) {
                    return {i + 1, it->second + 1};
                }
            }            
        }
        
        return {};
    }
};