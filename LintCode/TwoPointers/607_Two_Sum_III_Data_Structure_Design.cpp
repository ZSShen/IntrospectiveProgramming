class TwoSum {
public:
    /**
     * @param number: An integer
     * @return: nothing
     */
    void add(int number) {
        // write your code here
        set_.insert(number);
    }

    /**
     * @param value: An integer
     * @return: Find if there exists any pair of numbers which sum is equal to the value.
     */
    bool find(int value) {
        // write your code here

        for (int src : set_) {
            int dst = value - src;
            int count = (src == dst) ? 2 : 1;
            if (set_.count(dst) >= count) {
                return true;
            }
        }

        return false;
    }

private:
    std::unordered_multiset<int> set_;
};