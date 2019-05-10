class MinStack {
public:
    MinStack()
      : size(0) {
        // do intialization if necessary
    }

    /*
     * @param number: An integer
     * @return: nothing
     */
    void push(int number) {
        // write your code here

        nums.push_back(number);
        ++size;

        if (size == 1) {
            mins.push_back(number);
            return;
        }

        int min = std::min(mins.back(), number);
        mins.push_back(min);
    }

    /*
     * @return: An integer
     */
    int pop() {
        // write your code here

        --size;

        int back = nums.back();

        nums.pop_back();
        mins.pop_back();

        return back;
    }

    /*
     * @return: An integer
     */
    int min() {
        // write your code here

        return mins.back();
    }


private:
    int size;
    std::vector<int> nums;
    std::vector<int> mins;

    /**
     *
     *  2 3 4 1 2
     *  2 2 2 1 1
     *
     */
};