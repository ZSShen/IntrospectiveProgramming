class Solution {
public:
    /**
     * @param numbers: Give an array numbers of n integer
     * @param target: An integer
     * @return: return the sum of the three integers, the sum closest target.
     */
    int threeSumClosest(vector<int> &numbers, int target) {
        // write your code here

        int ans = 0;
        int size = numbers.size();
        if (size < 3) {
            return ans;
        }

        std::sort(numbers.begin(), numbers.end());

        int diff = INT_MAX;

        int i = 0;
        while (i < size - 2) {

            int l = i + 1, r = size - 1;
            while (l < r) {
                int sum = numbers[i] + numbers[l] + numbers[r];
                if (sum == target) {
                    return sum;
                }

                int temp = abs(sum - target);
                if (temp < diff) {
                    diff = temp;
                    ans = sum;
                }

                if (sum > target) {
                    while (l < --r && numbers[r] == numbers[r + 1]);
                } else {
                    while (++l < r && numbers[l] == numbers[l - 1]);
                }
            }

            while (++i < size - 2 && numbers[i] == numbers[i - 1]);
        }

        return ans;
    }
};