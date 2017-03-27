class MinStack {
public:
    /** initialize your data structure here. */
    MinStack()
        : size_(0)
    { }
    
    void push(int x) {
        stack_.push_back(x);

        ++size_;
        if (size_ == 1) {
            mins_.push_back(x);
            return;
        }
        mins_.push_back(std::min(mins_.back(), x));
    }
    
    void pop() {
        stack_.pop_back();
        mins_.pop_back();
        --size_;
    }
    
    int top() {
        return stack_.back();
    }
    
    int getMin() {
        return mins_.back();
    }

private:
    int size_;
    std::vector<int> stack_;
    std::vector<int> mins_;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */