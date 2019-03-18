class RandomizedSet {
public:
    RandomizedSet()
        : size_(0) {

        srand(time(nullptr));
    }

    /*
     * @param val: a value to the set
     * @return: true if the set did not already contain the specified element or false
     */
    bool insert(int val) {
        // write your code here

        if (map_.count(val) == 1) {
            return false;
        }

        // Update the vector.
        vector_.push_back(val);

        // Update the map.
        map_[val] = size_;

        ++size_;
        return true;
    }

    /*
     * @param val: a value from the set
     * @return: true if the set contained the specified element or false
     */
    bool remove(int val) {
        // write your code here

        if (map_.count(val) == 0) {
            return false;
        }

        int index = map_[val];

        // Update the vector.
        int tail = vector_.back();
        vector_.pop_back();
        vector_[index] = tail;

        // Update the map.
        map_.erase(val);
        map_[tail] = index;

        --size_;
        return false;
    }

    /*
     * @return: Get a random element from the set
     */
    int getRandom() {
        // write your code here

        int index = rand() % size_;
        return vector_[index];
    }

private:
    int size_;
    std::vector<int> vector_;
    std::unordered_map<int, int> map_;
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet obj = new RandomizedSet();
 * bool param = obj.insert(val);
 * bool param = obj.remove(val);
 * int param = obj.getRandom();
 */