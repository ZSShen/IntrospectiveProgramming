class Solution {
public:
    /**
     * @param nums: a list of integers.
     * @param k: length of window.
     * @return: the sum of the element inside the window at each moving.
     */
    vector<int> winSum(vector<int> &nums, int k) {
        // write your code here

        std::vector<int> ans;

        int size = nums.size();
        if (size == 0 || k == 0) {
            return ans;
        }

        int l = 0, r = k - 1;
        int sum = 0;
        for (int i = l ; i <= r ; ++i) {
            sum += nums[i];
        }
        ans.push_back(sum);

        while (r < size - 1) {
            sum -= nums[l++];
            sum += nums[++r];
            ans.push_back(sum);
        }

        return ans;
    }
};


class Solution {
public:
    /**
     * @param nums: a list of integers.
     * @param k: length of window.
     * @return: the sum of the element inside the window at each moving.
     */
    vector<int> winSum(vector<int> &nums, int k) {
        // write your code here

        int n = nums.size();
        if (n == 0 || k == 0) {
            return {};
        }

        std::vector<int> ans;

        int sum = 0;
        for (int i = 0 ; i < k ; ++i) {
            sum += nums[i];
        }
        ans.push_back(sum);

        int l = 0, r = k;
        while (r < n) {
            sum += nums[r];
            sum -= nums[l];

            ans.push_back(sum);

            ++l;
            ++r;
        }


        return ans;
    }
};