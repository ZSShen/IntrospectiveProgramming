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


class MovingAverage {
public:
    /*
    * @param size: An integer
    */MovingAverage(int size)
      : capacity(size), size(0), sum(0.0) {
        // do intialization if necessary
    }

    /*
     * @param val: An integer
     * @return:
     */
    double next(int val) {
        // write your code here

        if (size < capacity) {
            sum += val;
            deque.push_back(val);
            ++size;

            return sum / static_cast<double>(size);
        }

        sum -= deque.front();
        deque.pop_front();
        sum += val;
        deque.push_back(val);

        return sum / static_cast<double>(size);
    }

private:
    int capacity;
    int size;
    double sum;
    std::deque<double> deque;
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage obj = new MovingAverage(size);
 * double param = obj.next(val);
 */