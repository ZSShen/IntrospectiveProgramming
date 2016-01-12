class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target)
    {
        if (nums.size() < 3)
            return 0;
        int sum = 0, step = 0, pos = 0, dist = INT_MAX;
        int ans = nums[0] + nums[1] + nums[2];

        sort(nums.begin(), nums.end(), CompareNumber);
        PruneAndSearch(nums, target, sum, step, pos, dist, ans);
        return ans;
    }

private:
    static bool CompareNumber(int src, int tge)
    {
        return (src < tge);
    }

    void PruneAndSearch(vector<int>& nums, int target, int& sum,
                        int step, int pos, int& dist, int& ans)
    {
        if (step == 3) {
            if (sum > target) {
                if ((sum - target) < dist) {
                    dist = sum - target;
                    ans = sum;
                }
            } else {
                if ((target - sum) < dist) {
                    dist = target - sum;
                    ans = sum;
                }
            }
            return;
        }

        int bound = nums.size();
        for (int i = pos ; i < bound ; ++i) {
            // Prune the useless search spaces.
            int temp;
            if (step == 2) {
                temp = sum + nums[i];
                if (temp >= target) {
                    if ((temp - target) < dist) {
                        dist = temp - target;
                        ans = temp;
                    }
                    return;
                }
                temp = sum + nums[bound - 1];
                if (temp <= target) {
                    if ((target - temp) < dist) {
                        dist = target - temp;
                        ans = temp;
                    }
                    return;
                }
            }

            if (step == 1 && i < (bound - 1)) {
                temp = sum + nums[i] + nums[i + 1];
                if (temp >= target) {
                    if ((temp - target) < dist) {
                        dist = temp - target;
                        ans = temp;
                    }
                    return;
                }
                temp = sum + nums[bound - 1] + nums[bound - 2];
                if (temp <= target) {
                    if ((target - temp) < dist) {
                        dist = target - temp;
                        ans = temp;
                    }
                    return;
                }
            }

            if (step == 0 && i < (bound - 2)) {
                temp = nums[i] + nums[i + 1] + nums[i + 2];
                if (temp >= target) {
                    if ((temp - target) < dist) {
                        dist = temp - target;
                        ans = temp;
                    }
                    return;
                }
                temp = nums[bound - 1] + nums[bound - 2] + nums[bound - 3];
                if (temp <= target) {
                    if ((target - temp) < dist) {
                        dist = target - temp;
                        ans = temp;
                    }
                    return;
                }
            }

            sum += nums[i];
            ++step;
            PruneAndSearch(nums, target, sum, step, i + 1, dist, ans);
            --step;
            sum -= nums[i];
        }
    }
};