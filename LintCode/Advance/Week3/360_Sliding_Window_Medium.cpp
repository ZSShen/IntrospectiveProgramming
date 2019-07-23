class Solution {
public:
    /**
     * @param nums: A list of integers
     * @param k: An integer
     * @return: The median of the element inside the window at each moving
     */
    vector<double> medianSlidingWindow(vector<int> &nums, int k) {
        // write your code here

        std::multiset<int, std::less<int>> min;
        std::multiset<int, std::greater<int>> max;

        int size = nums.size();
        for (int i = 0 ; i < k ; ++i) {
            insert(min, max, nums[i]);
            rebalance(min, max);
        }

        std::vector<double> ans;
        for (int i = k ; i < size ; ++i) {
            ans.emplace_back(getMedian(min, max, k));

            insert(min, max, nums[i]);;
            remove(min, max, nums[i - k]);
            rebalance(min, max);
        }
        ans.emplace_back(getMedian(min, max, k));

        return ans;
    }

private:
    void insert(auto& min, auto& max, int num) {

        if (max.empty()) {
            max.emplace(num);
            return;
        }

        if (num > *max.begin()) {
            min.emplace(num);
        } else {
            max.emplace(num);
        }
    }

    void remove(auto& min, auto& max, int num) {

        auto it = max.find(num);
        if (it != max.end()) {
            max.erase(it);
            return;
        }

        min.erase(min.find(num));
    }

    void rebalance(auto& min, auto& max) {

        int max_size = max.size();
        int min_size = min.size();

        if (max_size - min_size > 1) {
            int top = *max.begin();
            min.emplace(top);
            max.erase(max.begin());
            return;
        }

        if (min_size - max_size > 1) {
            int top = *min.begin();
            max.emplace(top);
            min.erase(min.begin());
        }
    }

    double getMedian(auto& min, auto& max, int k) {

        if (k % 2 == 1) {
            return (max.size() > min.size()) ? *max.begin() : *min.begin();
        }

        return (static_cast<double>(*max.begin()) + *min.begin()) / 2;
    }
};


class Solution {
public:
    /**
     * @param nums: A list of integers
     * @param k: An integer
     * @return: The median of the element inside the window at each moving
     */
    vector<int> medianSlidingWindow(vector<int> &nums, int k) {
        // write your code here

        int n = nums.size();
        if (n == 0 || k == 0) {
            return {};
        }

        std::multiset<int, std::less<int>> min;
        std::multiset<int, std::greater<int>> max;

        for (int i = 0 ; i < k ; ++i) {
            int num = nums[i];
            enQueue(min, max, num);
            reBalance(min, max);
        }

        std::vector<int> ans;
        ans.push_back(getMedian(min, max));

        for (int i = k ; i < n ; ++i) {
            enQueue(min, max, nums[i]);
            reBalance(min, max);

            deQueue(min, max, nums[i - k]);
            reBalance(min, max);

            ans.push_back(getMedian(min, max));
        }

        return ans;
    }


private:
    void enQueue(auto& min, auto& max, int num) {

        if (max.empty()) {
            max.insert(num);
            return;
        }

        if (num <= *max.begin()) {
            max.insert(num);
        } else {
            min.insert(num);
        }
    }

    void deQueue(auto& min, auto& max, int num) {

        auto it = max.find(num);
        if (it != max.end()) {
            max.erase(it);
            return;
        }

        it = min.find(num);
        if (it != min.end()) {
            min.erase(it);
        }
    }

    void reBalance(auto& min, auto& max) {

        int max_size = max.size();
        int min_size = min.size();

        if (max_size > min_size + 1) {
            auto it = max.begin();
            int num = *it;
            max.erase(it);
            min.insert(num);
            return;
        }

        if (min_size > max_size + 1) {
            auto it = min.begin();
            int num = *it;
            min.erase(it);
            max.insert(num);
        }
    }

    int getMedian(auto& min, auto& max) {

        int max_size = max.size();
        int min_size = min.size();

        if (max_size > min_size) {
            return *max.begin();
        }

        if (max_size < min_size) {
            return *min.begin();
        }

        return *max.begin();
    }
};