class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k)
    {
        vector<int> ans;
        int size = nums.size();
        if (!((1 <= k) && (k <= size)))
            return ans;

        multiset<int> set;
        for (int i = 0 ; i < k ; ++i)
            set.insert(nums[i]);

        int front = 0;
        int rear = k - 1;
        while (true) {
            int max = *set.rbegin();
            ans.push_back(max);

            int elem = nums[front];
            multiset<int>::iterator iter = set.find(elem);
            set.erase(iter);

            ++front;
            ++rear;
            if (rear == size)
                break;

            elem = nums[rear];
            set.insert(elem);
        }

        return ans;
    }
};