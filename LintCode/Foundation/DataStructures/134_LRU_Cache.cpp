#include <list>


struct Entry {
    int key;
    int value;

    Entry(int key, int value)
        : key(key), value(value)
    { }
};


class LRUCache {
public:
    /*
    * @param capacity: An integer
    */
    LRUCache(int capacity)
        : size_(0), cap_(capacity)
    { }

    /*
     * @param key: An integer
     * @return: An integer
     */
    int get(int key) {
        // write your code here

        if (map_.count(key) == 0) {
            return -1;
        }

        auto iter = map_[key];
        auto entry = *iter;

        // Update the list.
        list_.erase(iter);
        list_.push_front(entry);

        // Update the map.
        map_[key] = list_.begin();

        return entry.value;
    }

    /*
     * @param key: An integer
     * @param value: An integer
     * @return: nothing
     */
    void set(int key, int value) {
        // write your code here

        if (map_.count(key) == 1) {
            // Cache hit

            auto iter = map_[key];
            auto entry = *iter;
            entry.value = value;

            // Update the list.
            list_.erase(iter);
            list_.push_front(entry);

            // Update the map.
            map_[key] = list_.begin();

        } else {
            // Cache miss

            if (size_ == cap_) {
                auto entry = list_.back();

                // Update the list.
                list_.pop_back();

                // Update the map.
                map_.erase(entry.key);

                --size_;
            }

            // Update the list.
            list_.push_front(Entry(key, value));

            // Update the map.
            auto iter = list_.begin();
            map_[key] = iter;

            ++size_;
        }
    }

private:
    int size_;
    int cap_;

    std::list<Entry> list_;
    std::unordered_map<int, std::list<Entry>::iterator> map_;
};


#include <list>

class LRUCache {
public:
    /*
    * @param capacity: An integer
    */LRUCache(int capacity)
      : size(0),
        capacity(capacity) {
        // do intialization if necessary
    }

    /*
     * @param key: An integer
     * @return: An integer
     */
    int get(int key) {
        // write your code here

        if (refs.count(key) == 0) {
            return -1;
        }

        auto iter = refs[key];
        int value = iter->second;

        list.erase(iter);
        list.push_front(std::make_pair(key, value));
        refs[key] = list.begin();

        return value;
    }

    /*
     * @param key: An integer
     * @param value: An integer
     * @return: nothing
     */
    void set(int key, int value) {
        // write your code here

        if (refs.count(key) == 0) {
            list.push_front(std::make_pair(key, value));
            refs[key] = list.begin();

            ++size;
            if (size == capacity + 1) {
                auto iter = --list.end();
                int expired_key = iter->first;

                list.erase(iter);
                refs.erase(expired_key);

                --size;
            }
            return;
        }

        auto iter = refs[key];
        list.erase(iter);
        list.push_front(std::make_pair(key, value));
        refs[key] = list.begin();
    }

private:
    int size;
    int capacity;
    std::list<std::pair<int, int>> list;
    std::unordered_map<int, std::list<std::pair<int, int>>::iterator> refs;
};
