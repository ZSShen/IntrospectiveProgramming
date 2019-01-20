class DequeNode {
    int value;
    DequeNode pred, succ;

    public DequeNode(int value) {
        this.value = value;
        this.pred = this;
        this.succ = this;
    }
}


class MyCircularDeque {

    private int capacity_, size_;
    private DequeNode head_, tail_;

    /** Initialize your data structure here. Set the size of the deque to be k. */
    public MyCircularDeque(int k) {

        capacity_ = k;
        size_ = 0;
        head_ = tail_ = null;
    }

    /** Adds an item at the front of Deque. Return true if the operation is successful. */
    public boolean insertFront(int value) {
        if (size_ == capacity_) {
            return false;
        }

        if (head_ == null) {
            head_ = tail_ = new DequeNode(value);
            ++size_;
            return true;
        }

        DequeNode new_head = new DequeNode(value);
        new_head.succ = head_;
        head_.pred = new_head;
        head_ = new_head;
        ++size_;
        return true;
    }

    /** Adds an item at the rear of Deque. Return true if the operation is successful. */
    public boolean insertLast(int value) {
        if (size_ == capacity_) {
            return false;
        }

        if (tail_ == null) {
            tail_ = head_ = new DequeNode(value);
            ++size_;
            return true;
        }

        DequeNode new_tail = new DequeNode(value);
        new_tail.pred = tail_;
        tail_.succ = new_tail;
        tail_ = new_tail;
        ++size_;
        return true;
    }

    /** Deletes an item from the front of Deque. Return true if the operation is successful. */
    public boolean deleteFront() {
        if (size_ == 0) {
            return false;
        }

        if (size_ == 1) {
            head_ = tail_ = null;
            --size_;
            return true;
        }

        DequeNode new_head = head_.succ;
        new_head.pred = new_head;
        head_ = null;
        head_ = new_head;
        --size_;
        return true;
    }

    /** Deletes an item from the rear of Deque. Return true if the operation is successful. */
    public boolean deleteLast() {
        if (size_ == 0) {
            return false;
        }

        if (size_ == 1) {
            tail_ = head_ = null;
            --size_;
            return true;
        }

        DequeNode new_tail = tail_.pred;
        new_tail.succ = new_tail;
        tail_ = null;
        tail_ = new_tail;
        --size_;
        return true;
    }

    /** Get the front item from the deque. */
    public int getFront() {
        return (size_ != 0) ? head_.value : -1;
    }

    /** Get the last item from the deque. */
    public int getRear() {
        return (size_ != 0)? tail_.value : -1;
    }

    /** Checks whether the circular deque is empty or not. */
    public boolean isEmpty() {
        return size_ == 0;
    }

    /** Checks whether the circular deque is full or not. */
    public boolean isFull() {
        return size_ == capacity_;
    }
}

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque obj = new MyCircularDeque(k);
 * boolean param_1 = obj.insertFront(value);
 * boolean param_2 = obj.insertLast(value);
 * boolean param_3 = obj.deleteFront();
 * boolean param_4 = obj.deleteLast();
 * int param_5 = obj.getFront();
 * int param_6 = obj.getRear();
 * boolean param_7 = obj.isEmpty();
 * boolean param_8 = obj.isFull();
 */