class MedianFinder {
public:
    MedianFinder()
     : count_element_(0),
       min_heap_(),
       max_heap_()
    {}

    // Adds a number into the data structure.
    void addNum(int num)
    {
        // Insert the given element into the appropriate heap.
        if (count_element_ == 0)
            min_heap_.push(num);
        else {
            int median = min_heap_.top();
            if (num > median)
                min_heap_.push(num);
            else
                max_heap_.push(num);
        }
        ++count_element_;

        // Balance two heaps.
        // Ensure that the size of the minimum heap is always larger than
        // or equal to the size of the maximum heap.
        int size_min = min_heap_.size();
        int size_max = max_heap_.size();
        if ((size_min - size_max) > 1) {
            int median = min_heap_.top();
            min_heap_.pop();
            max_heap_.push(median);
        } else if ((size_max - size_min) > 0) {
            int median = max_heap_.top();
            max_heap_.pop();
            min_heap_.push(median);
        }
    }

    // Returns the median of current data stream
    double findMedian()
    {
        if ((count_element_ >> 1 << 1) != count_element_)
            return static_cast<double>(min_heap_.top());
        double cast_min = static_cast<double>(min_heap_.top());
        double cast_max = static_cast<double>(max_heap_.top());
        return (cast_min + cast_max) / 2;
    }

private:
    int count_element_;
    priority_queue<int, vector<int>, greater<int>> min_heap_;
    priority_queue<int, vector<int>, less<int>> max_heap_;

};