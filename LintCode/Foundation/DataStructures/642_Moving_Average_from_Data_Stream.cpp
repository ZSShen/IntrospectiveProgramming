class MovingAverage {
public:
    /*
    * @param size: An integer
    */
    MovingAverage(int size)
        : size_(size),
          total_(0)
    { }

    /*
     * @param val: An integer
     * @return:
     */
    double next(int val) {
        // write your code here

        if (queue_.size() == size_) {
            int elem = queue_.front();
            queue_.pop();
            total_ -= elem;
        }
        queue_.push(val);
        total_ += val;

        return total_ / queue_.size();
    }

private:
    int size_;
    double total_;
    std::queue<int> queue_;
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage obj = new MovingAverage(size);
 * double param = obj.next(val);
 */