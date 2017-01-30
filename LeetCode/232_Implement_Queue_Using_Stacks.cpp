class MyQueue {
public:
    /** Initialize your data structure here. */
    MyQueue() = default;

    /** Push element x to the back of queue. */
    void push(int x) {
        in_.push(x);
    }

    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        int element = peek();
        out_.pop();
        return element;
    }

    /** Get the front element. */
    int peek() {
        if (out_.empty()) {
            int size = in_.size();
            for (int i = 0 ; i < size ; ++i) {
                int element = in_.top();
                in_.pop();
                out_.push(element);
            }
        }
        return out_.top();
    }

    /** Returns whether the queue is empty. */
    bool empty() {
        return in_.empty() && out_.empty();
    }

private:
    std::stack<int> in_;
    std::stack<int> out_;
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue obj = new MyQueue();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.peek();
 * bool param_4 = obj.empty();
 */