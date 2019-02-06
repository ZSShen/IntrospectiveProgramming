class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target)
    {
        vector<vector<int>> ans;
        if (nums.size() == 0)
            return ans;

        sort(nums.begin(), nums.end(), Solution::Compare);
        vector<int> path;
        int sum = 0;
        PruneAndSearch(nums, target, ans, 0, sum, path);
        return ans;
    }

private:

    static bool Compare(int src, int tge)
    {
        return src < tge;
    }

    void PruneAndSearch(vector<int>& nums, int target, vector<vector<int>>& ans,
                       int pos, int& sum, vector<int>& path)
    {
        if (path.size() == 4) {
            if (sum != target)
                return;

            // Simple check for duplicated records.
            int count = ans.size();
            bool ac = true;
            for (int i = 0 ; i < count ; ++i) {
                vector<int>& temp = ans[i];
                if (path[0] == temp[0] &&
                    path[1] == temp[1] &&
                    path[2] == temp[2] &&
                    path[3] == temp[3]) {
                    ac = false;
                    break;
                }
            }
            if (ac)
                ans.push_back(path);
            return;
        }

        int bound = nums.size();
        if (pos == bound)
            return;

        for (int i = pos ; i < bound ; ++i) {
            // Prune the useless search space.
            int len = path.size();
            if (len == 3 && i < bound && (sum + nums[i]) > target)
                return;
            if (len == 2 && i < (bound - 1) &&
                (sum + nums[i] + nums[i + 1]) > target)
                return;
            if (len == 1 && i < (bound - 2) &&
                (sum + nums[i] + nums[i + 1] + nums[i + 2]) > target)
                return;

            if (len == 3 && i < bound && (sum + nums[bound - 1]) < target)
                return;
            if (len == 2 && i < (bound - 1) &&
                (sum + nums[bound - 1] + nums[bound - 2]) < target)
                return;
            if (len == 1 && i < (bound - 2) &&
                (sum + nums[bound - 1] + nums[bound - 2] + nums[bound - 3]) < target)
                return;

            int num = nums[i];
            path.push_back(num);
            sum += num;
            PruneAndSearch(nums, target, ans, i + 1, sum, path);
            sum -= num;
            path.pop_back();
        }
    }
};