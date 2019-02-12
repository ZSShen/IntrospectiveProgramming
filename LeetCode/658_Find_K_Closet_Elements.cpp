class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {

        int size = arr.size();
        int left = 0, right = size - 1;
        while (left + 1 < right) {
            int mid = left + (right - left) / 2;
            if (arr[mid] > x) {
                right = mid;
            } else {
                left = mid;
            }
        }

        if (abs(x - arr[left]) > abs(x - arr[right])) {
            ++left;
        }

        if (left == 0) {
            std::vector<int> ans;
            for (int i = 0 ; i < k ; ++i) {
                ans.push_back(arr[left + i]);
            }
            return ans;
        }

        if (left == size - 1) {
            std::vector<int> ans;
            for (int i = k - 1 ; i >= 0 ; --i) {
                ans.push_back(arr[left - i]);
            }
            return ans;
        }

        --left;
        right = left + 2;
        for (int i = 1 ; i < k ; ++i) {
            int left_diff = (left >= 0) ? abs(x - arr[left]) : INT_MAX;
            int right_diff = (right < size) ? abs(x - arr[right]) : INT_MAX;
            if (left_diff <= right_diff) {
                --left;
            } else {
                ++right;
            }
        }

        std::vector<int> ans;
        for (int i = left + 1 ; i < right ; ++i) {
            ans.push_back(arr[i]);
        }
        return ans;
    }
};