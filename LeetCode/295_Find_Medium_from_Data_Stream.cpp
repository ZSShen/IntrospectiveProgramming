class MedianFinder {
public:
    /** initialize your data structure here. */
    MedianFinder() 
      : size_(0)
    { }
    
    void addNum(int num) {

        ++size_;
        
        if (size_ == 1) {
            max_.push(num);
            return;
        }
    
        // Determine which queue the input number should be stored. 
        if (num <= max_.top()) {
            max_.push(num);
        } else {
            min_.push(num);
        }
        
        // Rebalance two queues.
        int size_max = max_.size();
        int size_min = min_.size();
        if (size_max - size_min == 2) {
            min_.push(max_.top());
            max_.pop();
        } else if (size_min - size_max == 2) {
            max_.push(min_.top());
            min_.pop();
        }
    }
    
    double findMedian() {
        
        int size_max = max_.size();
        int size_min = min_.size();
        if (size_max == size_min) {
            return static_cast<double>(max_.top() + min_.top()) / 2;
        }
        
        if (size_max > size_min) {
            return max_.top();
        } else {
            return min_.top();
        }
    }

private:
    int size_;
    std::priority_queue<int, std::vector<int>> max_;
    std::priority_queue<int, std::vector<int>, std::greater<int>> min_;
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
