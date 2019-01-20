class BucketNode {
    int key, value;
    BucketNode succ;

    public BucketNode(int key, int value) {
        this.key = key;
        this.value = value;
        succ = null;
    }
}


class MyHashMap {

    private int mod_base_;
    private BucketNode[] bucket_;

    /** Initialize your data structure here. */
    public MyHashMap() {

        // Tunable bucket size.
        mod_base_ = 10000;
        bucket_ = new BucketNode[mod_base_];
    }

    /** value will always be non-negative. */
    public void put(int key, int value) {

        int bucket_index = key % mod_base_;

        if (bucket_[bucket_index] == null) {
            bucket_[bucket_index] = new BucketNode(key, value);
        }

        BucketNode curr = bucket_[bucket_index];
        while (curr != null) {
            if (curr.key == key) {
                curr.value = value;
                return;
            }
            curr = curr.succ;
        }

        curr = new BucketNode(key, value);
        curr.succ = bucket_[bucket_index];
        bucket_[bucket_index] = curr;
    }

    /** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
    public int get(int key) {

        int bucket_index = key % mod_base_;

        if (bucket_[bucket_index] == null) {
            return -1;
        }

        BucketNode curr = bucket_[bucket_index];
        while (curr != null) {
            if (curr.key == key) {
                return curr.value;
            }
            curr = curr.succ;
        }

        return -1;
    }

    /** Removes the mapping of the specified value key if this map contains a mapping for the key */
    public void remove(int key) {

        int bucket_index = key % mod_base_;

        if (bucket_[bucket_index] == null) {
            return;
        }

        BucketNode pred = null;
        BucketNode curr = bucket_[bucket_index];
        while (curr != null) {
            if (curr.key == key) {
                if (pred == null) {
                    bucket_[bucket_index] = curr.succ;
                } else {
                    pred.succ = curr.succ;
                }
                curr = null;
                return;
            }

            pred = curr;
            curr = curr.succ;
        }
    }
}

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap obj = new MyHashMap();
 * obj.put(key,value);
 * int param_2 = obj.get(key);
 * obj.remove(key);
 */