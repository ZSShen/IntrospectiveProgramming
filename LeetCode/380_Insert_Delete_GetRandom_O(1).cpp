#include <vector>
#include <unordered_map>


class RandomizedSet {
private:
    std::vector<int> vector_;
    std::unordered_map<int, std::vector<int>::iterator> map_;
    int size_;

public:
    /** Initialize your data structure here. */
    RandomizedSet()
        : size_(0) {

        srand(time(nullptr));
    }

    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {

        auto map_iter = map_.find(val);
        if (map_iter != map_.end()) {
            return false;
        }

        vector_.push_back(val);
        map_.insert(std::make_pair(val, std::prev(vector_.end())));
        ++size_;
        return true;
    }

    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {

        auto map_iter = map_.find(val);
        if (map_iter == map_.end()) {
            return false;
        }

        auto& vector_iter = map_iter->second;
        *vector_iter = vector_.back();
        vector_.pop_back();
        map_.erase(map_iter);
        --size_;
        return true;
    }

    /** Get a random element from the set. */
    int getRandom() {

        int index = rand() % size_;
        return vector_[index];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet obj = new RandomizedSet();
 * bool param_1 = obj.insert(val);
 * bool param_2 = obj.remove(val);
 * int param_3 = obj.getRandom();
 */