class LRUCache {
private:
    std::list<std::pair<int, int>> list_;
    std::unordered_map<
        int,
        std::list<std::pair<int,int>>::iterator> map_;

    int size_, capacity_;

public:
    LRUCache(int capacity) {
        size_ = 0;
        capacity_ = capacity;
    }

    int get(int key) {

        auto map_iter = map_.find(key);
        if (map_iter == map_.end()) {
            return -1;
        }

        auto& list_iter = map_iter->second;
        int value = list_iter->second;
        list_.erase(list_iter);
        list_.push_front(std::make_pair(key, value));
        map_iter->second = list_.begin();

        return value;
    }

    void put(int key, int value) {

        auto iter = map_.find(key);
        if (iter != map_.end()) {
            list_.erase(iter->second);
            list_.push_front(std::make_pair(key, value));
            iter->second = list_.begin();
            return;
        }

        if (size_ == capacity_) {
            auto& tail = list_.back();
            iter = map_.find(tail.first);
            map_.erase(iter);
            list_.pop_back();
            --size_;
        }

        list_.push_front(std::make_pair(key, value));
        map_.insert(std::make_pair(key, list_.begin()));
        ++size_;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache obj = new LRUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */