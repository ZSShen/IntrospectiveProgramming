class ListNode {
    int value;
    ListNode pred, succ;

    public ListNode(int value) {
        this.value = value;
        pred = succ = this;
    }
}


class MyLinkedList {

    private int size_;
    private ListNode head_, tail_;

    /** Initialize your data structure here. */
    public MyLinkedList() {
        size_ = 0;
        head_ = tail_ = null;
    }

    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    public int get(int index) {
        if (index >= size_) {
            return -1;
        }

        ListNode curr = head_;
        for (int i = 0 ; i < index ; ++i) {
            curr = curr.succ;
        }

        return curr.value;
    }

    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
    public void addAtHead(int val) {
        if (head_ == null) {
            head_ = tail_ = new ListNode(val);
            size_ = 1;
            return;
        }

        ListNode new_head = new ListNode(val);
        tail_.succ = new_head;
        head_.pred = new_head;
        new_head.succ = head_;
        new_head.pred = tail_;
        head_ = new_head;
        ++size_;
    }

    /** Append a node of value val to the last element of the linked list. */
    public void addAtTail(int val) {
        if (tail_ == null) {
            tail_ = head_ = new ListNode(val);
            size_ = 1;
            return;
        }

        ListNode new_tail = new ListNode(val);
        tail_.succ = new_tail;
        head_.pred = new_tail;
        new_tail.succ = head_;
        new_tail.pred = tail_;
        tail_ = new_tail;
        ++size_;
    }

    /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
    public void addAtIndex(int index, int val) {
        if (index > size_) {
            return;
        }

        if (index == 0) {
            addAtHead(val);
            return;
        }

        if (index == size_) {
            addAtTail(val);
            return;
        }

        ListNode pred = null;
        ListNode curr = head_;
        for (int i = 0 ; i < index ; ++i) {
            pred = curr;
            curr = curr.succ;
        }

        ListNode new_node = new ListNode(val);
        new_node.succ = curr;
        new_node.pred = pred;
        pred.succ = new_node;
        curr.pred = new_node;
        ++size_;
    }

    /** Delete the index-th node in the linked list, if the index is valid. */
    public void deleteAtIndex(int index) {
        if (index >= size_) {
            return;
        }

        if (index == 0) {
            tail_.succ = head_.succ;
            head_.succ.pred = tail_;
            head_ = null;
            head_ = tail_.succ;
            --size_;
            return;
        }

        if (index == size_ - 1) {
            head_.pred = tail_.pred;
            tail_.pred.succ = head_;
            tail_ = null;
            tail_ = head_.pred;
            --size_;
            return;
        }

        ListNode curr = head_;
        for (int i = 0 ; i < index ; ++i) {
            curr = curr.succ;
        }

        curr.pred.succ = curr.succ;
        curr.succ.pred = curr.pred;
        curr = null;
        --size_;
    }
}

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList obj = new MyLinkedList();
 * int param_1 = obj.get(index);
 * obj.addAtHead(val);
 * obj.addAtTail(val);
 * obj.addAtIndex(index,val);
 * obj.deleteAtIndex(index);
 */