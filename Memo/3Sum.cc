class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums)
    {
        vector<vector<int>> ans;
        size_t size = nums.size();
        if (size < 3)
            return ans;

        sort(nums.begin(), nums.end());
        unordered_set<string> set;

        int sum;
        size_t rear = 0, mid, front;
        while (rear < size - 2) {
            if (nums[rear] > 0)
                break;

            mid = rear + 1;
            front = size - 1;
            while (mid < front) {
                sum = nums[front] + nums[mid] + nums[rear];
                if (sum == 0) {
                    char c_key[256];
                    snprintf(c_key, 256, "%d%d%d", nums[front],
                             nums[mid], nums[rear]);
                    string key(c_key);
                    if (set.find(key) == set.end()) {
                        vector<int> tripple;
                        tripple.push_back(nums[rear]);
                        tripple.push_back(nums[mid]);
                        tripple.push_back(nums[front]);
                        ans.push_back(tripple);
                        set.insert(key);
                    }
                    --front;
                    ++mid;
                }
                if (sum > 0)
                    --front;
                if (sum < 0)
                    ++mid;
            }

            ++rear;
        }

        return ans;
    }

};
